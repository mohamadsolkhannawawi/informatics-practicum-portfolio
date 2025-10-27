// Soal
// Pak Dengklek ingin mengganti lagi kata sandi kandangnya menjadi sedikit rumit, sesuai dengan tanggal lahir bebek tertuanya, dengan format:

// [tahun+10]-[bulan]-[tanggal+7]
// Sebagai contoh, untuk tanggal 1 Januari 2023, kata sandi sesuai format di atas adalah:

// 2033-Januari-8
// Diketahui, bebek tertua Pak Dengklek lahir pada 15 Februari 2023. Lengkapilah program di sebelah kanan agar mengeluarkan sebuah baris berisi kata sandi barunya.

// Materi
// Pada soal ini, kita akan belajar tipe data baru. Kali ini, variabel bulan memiliki tipe data std::string. Tipe ini memungkinkan variabel untuk berisi nilai berupa string (teks).

// Untuk bisa menggunakan std::string, kita perlu #include <string>.

// Karena sudah terdapat perintah using namespace std; kita bisa langsung menuliskan string (tidak harus std::string).

#include <iostream>
#include <string>
using namespace std;

int main() {
    int tahun = 2023;
    string bulan = "Februari";
    int tanggal = 15;

    cout << tahun+10 << "-" << bulan << "-" << tanggal+7 << endl;
    return 0;
}

