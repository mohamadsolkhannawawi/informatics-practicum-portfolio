// Nama : Mohamad Solkhan Nawawi
// NIM  : 24060123120020
// Kelas: PL A

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.length()!=t.length()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

int main() {
    // Contoh 1
    string s = "batu";
    string t = "tabu";

    if (isAnagram(s, t)) {
        cout << "batu dan tabu adalah Anagram" << endl;
    } else {
        cout << "batu dan tabu Bukan Anagram" << endl;
    }

    // Contoh 2
    string s2 = "sapi";
    string t2 = "kuda";

    if (isAnagram(s2, t2)) {
        cout << "sapi dan kuda adalah Anagram" << endl;
    } else {
        cout << "sapi dan kuda Bukan Anagram" << endl;
    }
    return 0;
}

