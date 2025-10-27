/* Nama File  : SEQSearchWithSentinel.c */
/* Deskripsi  : Mencari harga X dalam Tabel T [1..N]
 secara sekuensial mulai dari Hasilnya adalah indeks IX 
 di mana Tix X (IX terkecil) | IX-0 jika tidak ketemu.
 Sentinel diletakkan di TN+1 */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 16 Mei 2024*/


#include <stdio.h>

void SEQSearchWithSentinel(int T[], int N, int X, int *IX ){
    //kamus lokal
    int i;
    //algoritma
    T[N] = X;
    i = 0;
    while (T[i] != X){
        i++;
    }

    if (i < N){
        *IX = i;
    } else {
        *IX = -1;
    }
}

int main(){
    //kamus
    int N = 8;
    int T[9] = {1, 3, 5, -8, 12, 90, 3, 15};
    int X = 9;
    int IX;

    //algoritma
    SEQSearchWithSentinel(T, N, X, &IX);
    if (IX != -1){
        printf("Index ditemukan pada indeks ke-%d", IX);
    } else {
        printf("Data tidak ditemukan");
    }
}