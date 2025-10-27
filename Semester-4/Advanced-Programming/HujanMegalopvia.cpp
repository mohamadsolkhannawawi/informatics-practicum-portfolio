#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;
const int MAX_SIZE = 1000010;
ll heights[MAX_SIZE], sequence[MAX_SIZE], finalOrder[MAX_SIZE]; 
bool isVisited[MAX_SIZE];
int orderCount = 0;
int totalElements, currentIndex;
int leftBound, rightBound;
int leftEdge, rightEdge;

void explore(int position) {
    leftBound = min(leftBound, position);
    rightBound = max(rightBound, position);
    // Kunjungi ke kanan selama memenuhi syarat
    while (!isVisited[rightBound + 1] && heights[rightBound + 1] < heights[position]) { 
        isVisited[++rightBound] = true;
        explore(rightBound);
    }
    // Kunjungi ke kiri selama memenuhi syarat
    while (!isVisited[leftBound - 1] && heights[leftBound - 1] < heights[position]) {
        isVisited[--leftBound] = true;
        explore(leftBound);
    }
    leftEdge = min(leftEdge, position);
    rightEdge = max(rightEdge, position);
    sequence[position] = ++orderCount;
}

int main() {
    cin >> totalElements >> currentIndex;

    for (int i = 1; i <= totalElements; ++i) {
        cin >> heights[i]; 
    }

    heights[0] = heights[totalElements + 1] = INT_MAX; 
    leftBound = rightBound = leftEdge = rightEdge = currentIndex;
    isVisited[currentIndex] = true;
    explore(currentIndex);

    while (leftEdge > 1 || rightEdge < totalElements) {
        if (leftEdge > 1 && !isVisited[leftEdge - 1] && heights[leftEdge - 1] < heights[rightEdge + 1]) {
            --leftEdge;
            isVisited[leftEdge] = true;
            leftBound = rightBound = leftEdge;
            explore(leftEdge);
        } else if (rightEdge < totalElements && !isVisited[rightEdge + 1]) {
            ++rightEdge;
            isVisited[rightEdge] = true;
            leftBound = rightBound = rightEdge;
            explore(rightEdge);
        } else {
            break;
        }
    }

    for (int i = 1; i <= totalElements; ++i) {
        finalOrder[sequence[i]] = i;
    }

    for (int i = 1; i <= totalElements; ++i) {
        cout << finalOrder[i] << " ";
    }
    cout << "\n";

    return 0;
}