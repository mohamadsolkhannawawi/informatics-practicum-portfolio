/* Nama File  : SEQSearchSorted.c */
/* Deskripsi  : Mencari harga X dalam Tabel T [1..N]
 secara sekuensial mulai dari T1, Hasilnya adalah index IX dimana T[IX] = X,
  IX = -1 jika tidak ketemu*/
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 16 Mei 2024*/

#include <stdio.h>

void SEQSearchSorted(int T[], int N, int X, int *IX){
//kamus lokal
    int i;
    //algoritma
    i = 0;
    while (i < N-1 && T[i] < X){
        i++;
    }

    if (T[i] == X){
        *IX = i;
    } else {
        *IX = -1;
    }
}

int main() {
    // Kamus
    int N =8;
    int T[8] = {1, 5, 7, 8, 10, 14, 17, 20};
    int X = 10;
    int IX;

    SEQSearchSorted(T, N, X, &IX);
    if (IX < N){
        printf("Index ditemukan pada indeks ke-%d", IX);
    } else {
        printf("Data tidak ditemukan");
    }
}