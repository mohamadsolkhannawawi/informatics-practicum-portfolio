#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100001

void assignBracketValues(int pos[], int noBracket[], int n, int start) {
    for (int i = 0; i <= n; i++) {
        noBracket[i] = 0;
    }

    for (int i = start; i <= n; i += 2) {
        noBracket[pos[i]] = i;
        noBracket[pos[i - 1]] = i;
    }
}

bool validateBrackets(int noBracket[], int n) {
    stack<int> checker;
    for (int i = 0; i < n; i++) {
        int now = noBracket[i];
        if (now == 0) continue;
        if (checker.empty() || checker.top() != now) {
            checker.push(now);
        } else {
            checker.pop();
        }
    }
    return checker.empty();
}

void invalidOutput() {
    cout << "INVALID\n";
    exit(0);
}

int main() {
    int n, pos[MAX_N], noBracket[MAX_N];
    string s;
    
    getline(cin, s);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int inputNumber;
        cin >> inputNumber;
        pos[inputNumber] = i;
    }
    
    assignBracketValues(pos, noBracket, n, 2);
    if (!validateBrackets(noBracket, n)) invalidOutput();
    
    assignBracketValues(pos, noBracket, n, 3);
    if (!validateBrackets(noBracket, n)) invalidOutput();
    
    for (int i = 1; i < n; i++) {
        cout << ((i % 2 == 1) ^ (pos[i] < pos[i + 1]) ? 'A' : 'B');
    }
    cout << endl;
}
