#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk mendekripsi teks terenkripsi dengan pergeseran tertentu
string decryptCaesarCipher(const string& encryptedText, int shift) {
    string decryptedText = encryptedText;
    for (char& c : decryptedText) {
        if (islower(c)) {
            c = (c - 'a' - shift + 26) % 26 + 'a';
        }
    }
    return decryptedText;
}

int main() {
    string encryptedText = "epctxlvldtsdpxzrlvfcdfdtytmpcxlyqlle";

    // Mencoba semua kemungkinan pergeseran dari 1 hingga 25
    for (int shift = 1; shift <= 25; ++shift) {
        string decryptedText = decryptCaesarCipher(encryptedText, shift);
        cout << "Shift " << shift << ": " << decryptedText << endl;
    }

    return 0;
}
