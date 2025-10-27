#include "Node.h"
#include <algorithm>

template <typename T>
Node<T>::Node() : parent(nullptr), prev(nullptr), next(nullptr), size(0) {}

template <typename T>
Node<T>::~Node() {
    keys.clear();
    children.clear();
    vals.clear();
    prev = nullptr;
    next = nullptr;
    parent = nullptr;
}

template <typename T>
int Node<T>::findKey(int key) {
    int l = 0;
    int r = keys.size() - 1;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (keys[mid] == key) {
            return mid;
        } else if (keys[mid] < key) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return -1;
}

template <typename T>
int Node<T>::keyInsertIndex(int key) {
    return std::upper_bound(keys.begin(), keys.end(), key) - keys.begin();
}

template <typename T>
int Node<T>::indexOfChild(Node<T>* child) {
    for (size_t i = 0; i < children.size(); i++) {
        if (children[i] == child) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

template <typename T>
void Node<T>::removeFromLeaf(int key) {
    int index = findKey(key);

    if (index == -1) {
        return;
    }

    keys.erase(keys.begin() + index);
    vals.erase(vals.begin() + index);
    size--;

    if (parent && !keys.empty()) {
        int cIndex = parent->findKey(key);
        if (cIndex != -1) {
            parent->keys[cIndex] = keys.front();
        }
    }
}

template <typename T>
void Node<T>::removeFromInternal(int key) {
    int index = findKey(key);

    if (index == -1) {
        return;
    }

    Node<T>* leftMostLeaf = children[index];

    while (leftMostLeaf->type != NodeType::NODE_LEAF) {
        leftMostLeaf = leftMostLeaf->children.front();
    }

    keys[index] = leftMostLeaf->keys.front();
    size--;
}

template <typename T>
void Node<T>::borrowFromRightLeaf() {
    Node<T>* next = this->next;
    Node<T>* nextParent = next->parent;

    keys.push_back(next->keys.front());
    vals.push_back(next->vals.front());
    next->keys.erase(next->keys.begin());
    next->vals.erase(next->vals.begin());

    size++;
    next->size--;

    nextParent->keys[nextParent->indexOfChild(next) - 1] = next->keys.front();
}

template <typename T>
void Node<T>::borrowFromLeftLeaf() {
    Node<T>* prev = this->prev;
    Node<T>* parent = this->parent;

    keys.insert(keys.begin(), prev->keys.back());
    vals.insert(vals.begin(), prev->vals.back());
    prev->keys.pop_back();
    prev->vals.pop_back();

    size++;
    prev->size--;

    parent->keys[parent->indexOfChild(this) - 1] = keys.front();
}

template <typename T>
void Node<T>::mergeWithRightLeaf() {
    Node<T>* next = this->next;
    Node<T>* nextParent = next->parent;

    for (int i = 0; i < next->size; i++) {
        int key = next->keys[i];
        T val = next->vals[i];
        set(key, val);
    }

    this->next = next->next;
    if (this->next) {
        this->next->prev = this;
    }

    int childIndex = nextParent->indexOfChild(next);
    nextParent->keys.erase(nextParent->keys.begin() + childIndex - 1);
    nextParent->children.erase(nextParent->children.begin() + childIndex);
    nextParent->size--;

    delete next;
}

template <typename T>
void Node<T>::mergeWithLeftLeaf() {
    Node<T>* prev = this->prev;
    Node<T>* parent = this->parent;

    for (int i = 0; i < size; i++) {
        int key = keys[i];
        T val = vals[i];
        prev->set(key, val);
    }

    prev->next = next;
    if (prev->next) {
        prev->next->prev = prev;
    }

    int childIndex = parent->indexOfChild(this);
    parent->keys.erase(parent->keys.begin() + childIndex - 1);
    parent->children.erase(parent->children.begin() + childIndex);
    parent->size--;

    delete this;
}

template <typename T>
void Node<T>::borrowFromRightInternal(Node<T>* next) {
    Node<T>* parent = this->parent;
    int childIndex = parent->indexOfChild(this);

    keys.push_back(parent->keys[childIndex]);
    parent->keys[childIndex] = next->keys.front();
    next->keys.erase(next->keys.begin());

    size++;
    next->size--;

    children.push_back(next->children.front());
    next->children.erase(next->children.begin());
    children.back()->parent = this;
}

template <typename T>
void Node<T>::borrowFromLeftInternal(Node<T>* prev) {
    Node<T>* parent = this->parent;
    int childIndex = parent->indexOfChild(this);

    keys.insert(keys.begin(), parent->keys[childIndex - 1]);
    parent->keys[childIndex - 1] = prev->keys.back();
    prev->keys.pop_back();

    size++;
    prev->size--;

    children.insert(children.begin(), prev->children.back());
    prev->children.pop_back();
    children.front()->parent = this;
}

template <typename T>
void Node<T>::mergeWithRightInternal(Node<T>* next) {
    Node<T>* parent = this->parent;
    int childIndex = parent->indexOfChild(this);

    keys.push_back(parent->keys[childIndex]);
    parent->keys.erase(parent->keys.begin() + childIndex);
    parent->children.erase(parent->children.begin() + childIndex + 1);

    size += next->size + 1;
    parent->size--;

    for (int key : next->keys) {
        keys.push_back(key);
    }

    for (Node<T>* child : next->children) {
        children.push_back(child);
        child->parent = this;
    }

    delete next;
}

template <typename T>
void Node<T>::mergeWithLeftInternal(Node<T>* prev) {
    Node<T>* parent = this->parent;
    int childIndex = parent->indexOfChild(this);

    prev->keys.push_back(parent->keys[childIndex - 1]);
    parent->keys.erase(parent->keys.begin() + childIndex - 1);
    parent->children.erase(parent->children.begin() + childIndex);

    prev->size += size + 1;
    parent->size--;

    for (int key : keys) {
        prev->keys.push_back(key);
    }

    for (Node<T>* child : children) {
        prev->children.push_back(child);
        child->parent = prev;
    }

    delete this;
}

template <typename T>
void Node<T>::set(int key, const T& val) {
    int keyIndex = findKey(key);

    if (keyIndex != -1) {
        vals[keyIndex] = val;
        return;
    }

    int insIndex = keyInsertIndex(key);
    keys.insert(keys.begin() + insIndex, key);
    vals.insert(vals.begin() + insIndex, val);
    size++;
}

template <typename T>
Node<T>* Node<T>::splitLeaf(int rIndex) {
    Node<T>* newSiblingNode = new Node<T>();
    newSiblingNode->type = NodeType::NODE_LEAF;

    // Update leaf nodes linked list
    newSiblingNode->prev = this;
    newSiblingNode->next = next;
    next = newSiblingNode;

    if (newSiblingNode->next) {
        newSiblingNode->next->prev = newSiblingNode;
    }

    // Transfer keys and vals to new leaf node
    for (int i = size - 1; i >= rIndex; i--) {
        int key = keys[i];
        T val = vals[i];

        newSiblingNode->set(key, val);
        keys.pop_back();
        vals.pop_back();
    }

    keys.shrink_to_fit();
    children.shrink_to_fit();
    vals.shrink_to_fit();

    newSiblingNode->size = newSiblingNode->keys.size();
    size = keys.size();

    return newSiblingNode;
}

template <typename T>
Node<T>* Node<T>::splitInternal(int rIndex) {
    Node<T>* newSiblingNode = new Node<T>();
    newSiblingNode->type = NodeType::NODE_INTERNAL;
    newSiblingNode->keys.resize(size - rIndex - 1);
    newSiblingNode->children.resize(size - rIndex);

    // Transfer children to new internal node
    for (int i = size; i > rIndex; i--) {
        newSiblingNode->children[i - rIndex - 1] = children[i];
        children[i]->parent = newSiblingNode;
        children.pop_back();
    }

    newSiblingNode->size = newSiblingNode->keys.size();

    for (int i = size - 1; i >= size - newSiblingNode->size; i--) {
        newSiblingNode->keys[i - (size - newSiblingNode->size)] = keys[i];
        keys.pop_back();
    }

    keys.pop_back();
    keys.shrink_to_fit();
    children.shrink_to_fit();
    vals.shrink_to_fit();

    size = keys.size();

    return newSiblingNode;
}

template <typename T>
Node<T>* Node<T>::splitNode() {
    int rIndex = size >> 1;
    int newParentKey = keys[rIndex];

    Node<T>* siblingNode;

    if (type == NodeType::NODE_LEAF) {
        siblingNode = splitLeaf(rIndex);
    } else {
        siblingNode = splitInternal(rIndex);
    }

    if (parent) {
        Node<T>* parentNode = parent;

        int index = parentNode->keyInsertIndex(newParentKey);
        parentNode->keys.insert(parentNode->keys.begin() + index, newParentKey);
        parentNode->size++;

        if (index > 0) {
            parentNode->children.insert(parentNode->children.begin() + index + 1, siblingNode);
        } else {
            parentNode->children.insert(parentNode->children.begin(), this);
            parentNode->children.insert(parentNode->children.begin() + 1, siblingNode);
        }

        siblingNode->parent = parentNode;
    } else {
        Node<T>* newRootNode = new Node<T>();

        newRootNode->type = NodeType::NODE_ROOT;
        newRootNode->keys.push_back(newParentKey);
        newRootNode->size = 1;
        newRootNode->children.push_back(this);
        newRootNode->children.push_back(siblingNode);

        if (type == NodeType::NODE_ROOT) {
            type = NodeType::NODE_INTERNAL;
        }

        parent = newRootNode;
        siblingNode->parent = newRootNode;

        return newRootNode;
    }

    return nullptr;
}

// Explicit template instantiation for common types
template class Node<std::string>;
template class Node<int>;
template class Node<double>;
