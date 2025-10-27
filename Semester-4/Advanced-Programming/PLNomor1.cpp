#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define fi first
#define se second

typedef pair<int, int> pii;

int n, a[100005], pos[100005];
string s;

bool checkValid(vector<pii> &pairs) {
    int bracket[n + 5], status[n + 5];
    fill(bracket, bracket + n + 5, -1);
    
    for (auto &[cl, cr] : pairs) {
        bracket[cl] = cr;
        bracket[cr] = cl;
        status[cl] = 1;
        status[cr] = 0;
    }
    
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        if (bracket[i] == -1) continue;
        if (status[i]) {
            st.push(bracket[i]);
        } else {
            if (st.empty() || st.top() != bracket[i]) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    getline(cin, s);
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    
    if (n == 2) {
        cout << "B" << endl;
        return 0;
    }
    
    vector<pii> rizal, febri;
    for (int i = 1; i < n; i++) {
        int l = pos[i], r = pos[i + 1];
        if (l > r) swap(l, r);
        if (i % 2) rizal.pb({l, r});
        else febri.pb({l, r});
    }
    
    if (!checkValid(rizal) || !checkValid(febri)) {
        cout << "INVALID" << endl;
        return 0;
    }
    
    string ans = "B";
    bool bef = pos[2] > pos[1];
    for (int i = 3; i <= n; i++) {
        bool now = pos[i] > pos[i - 1];
        if (bef) ans += (ans[i - 3] == 'A' ? 'B' : 'A');
        else ans += (ans[i - 3] == 'A' ? 'A' : 'B');
        bef = now;
    }
    
    cout << ans << endl;
    return 0;
}
