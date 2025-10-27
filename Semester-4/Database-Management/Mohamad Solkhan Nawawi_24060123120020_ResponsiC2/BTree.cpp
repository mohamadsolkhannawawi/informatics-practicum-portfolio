#include "BTree.h"
#include <iostream>


// Jangan ubah kode ini

template <typename T>
BTree<T>::BTree(int degree) : deg(degree), depth(1) {
    root = new Node<T>();
    root->type = NodeType::NODE_LEAF;
}

template <typename T>
BTree<T>::~BTree() {
    clear();
}

// ----


template <typename T>
Node<T>* BTree<T>::findLeaf(int key) { 
    Node<T>* curr = root;

    // disini traversal tree untuk menemukan leaf node
    while (curr->type != NodeType::NODE_LEAF) {
        int index = curr->keyInsertIndex(key);
        curr = curr->children[index];
    }

    return curr;
}

template <typename T>
void BTree<T>::set(int key, const T& val) { // fungsi untuk menambahkan atau memperbarui nilai pada B-Tree
    Node<T>* curr = findLeaf(key);
    int index = curr->findKey(key);

    curr->set(key, val);

    if (index != -1) {
        return;
    }

    while (curr && curr->size >= deg) { 
        Node<T>* newRootNode = curr->splitNode();

        if (newRootNode) { // jika node baru dibuat, maka kita perlu memperbarui root
            depth++;
            root = newRootNode;
        }

        curr = curr->parent; 
    }
}

template <typename T>
void BTree<T>::remove(int key) { 
    Node<T>* curr = findLeaf(key);
    int index = curr->findKey(key);

    if (index != -1) {
        remove(key, curr);
    }
}

template <typename T>
void BTree<T>::remove(int key, Node<T>* curr) { //
    // curr adalah node yang sedang diproses
    int minCapacity = deg >> 1; 
    // >> adalah operator bitwise shift ke kanan, jadi minCapacity adalah setengah dari derajat B-Tree
    // misal derajat B-Tree adalah 6, maka minCapacity adalah 3
    // 6 = 110 dalam biner, jadi 110 >> 1 = 011 dalam biner, yaitu 3 dalam desimal
    // jika derajat B-Tree adalah 5, maka minCapacity adalah 2
    // 5 = 101 dalam biner, jadi 101 >> 1 = 010 dalam biner, yaitu 2 dalam desimal

    if (curr->type == NodeType::NODE_LEAF &&curr->findKey(key) != -1) { // jika node adalah leaf, kita bisa langsung menghapus dari leaf
        curr->removeFromLeaf(key);
    }

    if (curr->size < minCapacity) {
        if (curr->type == NodeType::NODE_ROOT) {
            // Jika root memiliki kapasitas kurang dari minCapacity, kita akan menghapusnya
            if (!curr->size && !curr->children.empty()) { // Jika root kosong tapi memiliki anak
                Node<T>* oldRoot = curr;
                Node<T>* newRoot = curr->children[0];

                newRoot->parent = nullptr;
                root = newRoot;
                depth--;

                if (depth > 1) { // Jika masih ada lebih dari satu level, kita tetap menganggap ini sebagai root
                    newRoot->type = NodeType::NODE_ROOT;
                } else { // Jika hanya ada satu level, kita anggap ini sebagai leaf
                    newRoot->type = NodeType::NODE_LEAF;
                }
                delete oldRoot;
                return; 
            }
        } else if (curr->parent) { // Aslinya (curr->type == NodeType::NODE_INTERNAL)
            // Jika node internal memiliki parent, kita akan mencoba meminjam atau menggabungkan
            Node<T>* parent_node = curr->parent;

            if (curr->type == NodeType::NODE_INTERNAL) {
                int currChildIndex = parent_node->indexOfChild(curr);
                Node<T>* next = nullptr; 
                Node<T>* prev = nullptr; 

                if (parent_node->children.size() > static_cast<size_t>(currChildIndex + 1)) {
                    next = parent_node->children[currChildIndex + 1];
                }
                if (currChildIndex > 0) {
                    prev = parent_node->children[currChildIndex - 1];
                }

                if (next && next->parent == parent_node && next->size > minCapacity) {
                    curr->borrowFromRightInternal(next);
                } else if (prev && prev->parent == parent_node && prev->size > minCapacity) {
                    curr->borrowFromLeftInternal(prev);
                } else if (next && next->parent == parent_node && next->size <= minCapacity) {
                    curr->mergeWithRightInternal(next);
                } else if (prev && prev->parent == parent_node && prev->size <= minCapacity) {
                    Node<T>* original_prev = prev;
                    curr->mergeWithLeftInternal(original_prev); 
                    curr = original_prev; 
                }
            } else {
                Node<T>* next_sibling = curr->next;
                Node<T>* prev_sibling = curr->prev;

                if (next_sibling && next_sibling->parent == parent_node && next_sibling->size > minCapacity) {
                    curr->borrowFromRightLeaf();
                } else if (prev_sibling && prev_sibling->parent == parent_node && prev_sibling->size > minCapacity) {
                    curr->borrowFromLeftLeaf();
                } else if (next_sibling && next_sibling->parent == parent_node && next_sibling->size <= minCapacity) {
                    curr->mergeWithRightLeaf();
                } else if (prev_sibling && prev_sibling->parent == parent_node && prev_sibling->size <= minCapacity) {
                    Node<T>* original_prev_leaf = prev_sibling;
                    curr->mergeWithLeftLeaf();
                    curr = original_prev_leaf; 
                }
            }
        }
    }

    if (curr && curr->parent) {
        remove(key, curr->parent);
    }
}

//  Jangan ubah semua kode di bawah

template <typename T>
T* BTree<T>::find(int key) {
    Node<T>* curr = findLeaf(key);
    int index = curr->findKey(key);

    if (index != -1) {
        return &curr->vals[index];
    }

    return nullptr;
}

template <typename T>
void BTree<T>::printTree() {
    if (root) {
        printTree(root, "", true);
    }
}

template <typename T>
void BTree<T>::printTree(Node<T>* node, const std::string& prefix, bool last) {
    std::cout << prefix << "├ [";

    for (size_t i = 0; i < node->keys.size(); i++) {
        std::cout << node->keys[i];
        if (i != node->keys.size() - 1) {
            std::cout << ", ";
        }
    }

    std::cout << "]" << std::endl;

    std::string newPrefix = prefix + (last ? "   " : "╎  ");

    if (node->type != NodeType::NODE_LEAF) {
        for (size_t i = 0; i < node->children.size(); i++) {
            bool isLast = (i == node->children.size() - 1);
            printTree(node->children[i], newPrefix, isLast);
        }
    }
}

template <typename T>
bool BTree<T>::empty() const {
    return root->size == 0;
}

template <typename T>
void BTree<T>::clear() {
    if (root) {
        delete root;
        root = nullptr;
        depth = 0;
    }
}

// Explicit template instantiation for common types
template class BTree<std::string>;
template class BTree<int>;
template class BTree<double>;
