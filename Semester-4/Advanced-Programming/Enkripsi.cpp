#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk mengenkripsi teks menggunakan Caesar Cipher
string enkripsiCaesar(const string& teks, int k) {
    string hasil = teks;
    for (char& c : hasil) {
        if (islower(c)) {
            c = (c - 'a' + k) % 26 + 'a';
        }
    }
    return hasil;
}

int main() {
    string S = "zebra";
    int k = 5;
    string hasilEnkripsi = enkripsiCaesar(S, k);
    cout << "Hasil enkripsi dari \"" << S << "\" dengan k = " << k << " adalah: " << hasilEnkripsi << endl;
    return 0;
}
