/* Nama File  : BinSearch2.c */
/* Deskripsi  : Mencari harga X dalam Tabel T [1..N]
 secara secara dikhotomik, Hasilnya adalah index IX,
 dan IX adalah indeks dimana X ditemukan.
  IX = -1 jika tidak ketemu*/
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 16 Mei 2024*/

#include <stdio.h>

void BinSearch2(int T[], int N, int X, int *IX){
    //Kamus lokal
    int Atas;
    int Bawah;
    int Tengah;

    //algoritma
    Atas = 0;
    Bawah = N -1;
    Tengah = (Atas + Bawah)/2;
    while (Atas < Bawah && X != T[Tengah]){
      if (X < T[Tengah]){
        Bawah = Tengah - 1;
      } else if (X > T[Tengah]) {
        Atas = Tengah + 1;
      }
      Tengah = (Atas + Bawah)/2;
    }

    if (X == T[Tengah]){
      *IX = Tengah;
    } else {
      *IX = -1;
    }
}

int main() {
    int N =8;
    int T[8] = {1, 5, 7, 8, 10, 14, 17, 21};
    int X = 12;
    int IX;
    int Tengah;

    BinSearch2(T, N, X, &IX);
    if (X == T[Tengah]) {
      printf("Elemen ditemukan pada indeks ke %d", IX);
    } else {
      printf("Elemen tidak ditemukan.");
    }

    return 0;
}