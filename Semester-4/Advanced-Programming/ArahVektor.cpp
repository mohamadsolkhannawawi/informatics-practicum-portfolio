// Nama  : Mohamad Solkhan Nawawi 
// NIM   : 24060123120020
// Kelas : PL A


#include <iostream>
#include <complex>
using namespace std;

typedef complex<int> P; // Tipe data untuk menyimpan titik sebagai bilangan kompleks

string tentukanArah(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    // Buat titik-titik sebagai bilangan kompleks
    P titikPangkal_V1 = {x1, y1};
    P titikUjung_V1 = {x2, y2};
    P titikPangkal_V2 = {x3, y3};
    P titikUjung_V2 = {x4, y4};

    // Periksa keterhubungan: ujung vektor pertama (p2) harus sama dengan pangkal vektor kedua (p3)
    if (titikUjung_V1 != titikPangkal_V2)
        return "tidak terhubung";

    // Buat vektor arah
    P v1 = titikUjung_V1 - titikPangkal_V1; // Vektor pertama
    P v2 = titikUjung_V2 - titikPangkal_V2; // Vektor kedua

    // Hitung cross product dari vektor v1 dan v2
    int cross = imag(conj(v1) * v2);

    if (cross > 0)
        return "kiri"; 
    else if (cross < 0)
        return "kanan"; 
    else
        return "sejajar"; 
}

int main() {
    // Deklarasi variabel untuk menyimpan koordinat titik-titik
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    // Input koordinat titik-titik
    cout << "Masukkan koordinat titik-titik (Pisahkan dengan spasi):" << endl;
    cout << "Masukkan Titik Pangkal Vektor v1 (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Masukkan Titik Ujung Vektor v1 (x2 y2)  : ";
    cin >> x2 >> y2;
    cout << "Masukkan Titik Pangkal Vektor v2( x3 y3): ";
    cin >> x3 >> y3;
    cout << "Masukkan Titik Ujung Vektor v2 (x4 y4)  : ";
    cin >> x4 >> y4;

    // Panggil fungsi untuk menentukan arah
    string hasil = tentukanArah(x1, y1, x2, y2, x3, y3, x4, y4);
    // Tampilkan hasil
    cout << "Output: " << hasil << endl;

    return 0;
}
