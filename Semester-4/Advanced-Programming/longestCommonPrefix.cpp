// Nama : Mohamad Solkhan Nawawi
// NIM  : 24060123120020
// Kelas: PL A

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Fungsi untuk mencari longest common prefix
string LCP(vector<string>& v) {
    string ans = "";
    if (v.empty()) return ans;

    sort(v.begin(), v.end());
    string first = v[0];
    string last = v[v.size() - 1];

    for (int i = 0; i < min(first.size(), last.size()); i++) {
        if (first[i] != last[i]) {
            return ans;
        }
        ans += first[i];
    }
    return ans;
}

// Fungsi main untuk pengujian
int main() {
    // Contoh 1
    vector<string> input1 = {"flower", "flow", "flight"};
    cout << "Input: flower, flow, flight" << endl;
    cout << "Output: " << LCP(input1) << endl << endl;

    // Contoh 2
    vector<string> input2 = {"dog", "racecar", "car"};
    cout << "Input: dog, racecar, car" << endl;
    cout << "Output: " << LCP(input2) << endl;

    return 0;
}
