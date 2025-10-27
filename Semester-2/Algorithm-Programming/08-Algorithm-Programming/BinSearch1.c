/* Nama File  : BinSearch1.c */
/* Deskripsi  : Mencari harga X dalam Tabel T [1..N]
 secara dikhotomik, Hasilnya adalah sebuah boolean Found,
 true jika ketemu, Nilai elemen tabel terurut membesar: T1 <= T2 <= T3 <= ...<= TN*/
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 16 Mei 2024*/

#include <stdio.h>
#include <stdbool.h>

void BinSearch1(int T[], int N, int X, bool *Found, int *IX ){
    //Kamus lokal
    int Atas;
    int Bawah;
    int Tengah;

    //Algoritma
    Atas = 0;
    Bawah = N-1;
    *Found = false;

    while ( Atas <= Bawah && !*Found){
      Tengah = (Atas + Bawah)/2;
      if (X == T[Tengah]){
        *Found = true;
        *IX = Tengah;
      } else if (X < T[Tengah]) {
        Bawah = Tengah - 1;
      } else {
        Atas = Tengah + 1;
      }
    }
}

int main () {
    int N = 8;
    int T[8] = {1, 5, 7, 8, 10, 14, 17, 20};
    int X = 21;
    int IX;
    bool Found;

    BinSearch1(T, N, X, &Found, &IX);
    if (Found){
      printf("Elemen ditemukan pada indeks ke-%d", IX);
    } else {
      printf("Elemen tidak ditemukan.");
    }
}