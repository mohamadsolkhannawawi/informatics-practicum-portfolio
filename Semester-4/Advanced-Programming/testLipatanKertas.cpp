#include <iostream>
#include <vector>

using namespace std;

bool isValidPair(vector<int>& stack, vector<bool>& pairs, int value) {
    if (!pairs[value]) {
        pairs[value] = true;
        stack.push_back(value);
    } else if (!stack.empty() && stack.back() == value) {
        stack.pop_back();
    } else {
        return false;
    }
    return true;
}

bool isPossible(vector<int>& origami, int N) {
    vector<int> stack;
    vector<bool> pairs(N, false);

    for (int i = 0; i < N; i++) {
        if (origami[i] == -1 || (origami[i] == N - 1 && (N % 2 == 1))) continue;
        if (!isValidPair(stack, pairs, origami[i] / 2)) return false;
    }

    stack.clear();
    fill(pairs.begin(), pairs.end(), false);

    for (int i = 0; i < N; i++) {
        if (origami[i] == -1 || (origami[i] == N - 1 && (N % 2 == 0))) continue;
        if (!isValidPair(stack, pairs, (origami[i] - 1) / 2)) return false;
    }

    return true;
}

void printPattern(vector<int>& pos, int N) {
    for (int i = 1; i < N; i++) {
        if (i % 2 == 1) {
            cout << (pos[i - 1] < pos[i] ? "A" : "B");
        } else {
            cout << (pos[i - 1] < pos[i] ? "B" : "A");
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string soal;
    int N;

    getline(cin, soal);
    cin >> N;

    vector<int> origami(N), pos(N);
    for (int i = 0; i < N; i++) {
        cin >> origami[i];
        pos[origami[i]] = i;
    }

    if (!isPossible(origami, N)) {
        cout << "INVALID";
    } else {
        printPattern(pos, N);
    }

    return 0;
}
