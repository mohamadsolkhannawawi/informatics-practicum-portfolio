/* Nama File  : DriverSEQ.c */
/* Deskripsi  : Driver untuk mejalankan file SEQSearch1 dan SEQSearch2 */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 7 Mei 2024*/

#include "SEQSearch1.h"
#include "SEQSearch1.c"
#include "SEQSearch2.h"
#include "SEQSearch2.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main() {
    // Kamus
    int i; //Counter
    int IX; // Indeks
    int X; // Target
    int N; //Jumlah elemen tabel
    bool Found = false;
    printf("Masukkan jumlah elemen tabel : ");
    scanf("%d", &N);

    printf("\n");
    printf("Masukkan elemen yang dicari :");
    scanf("%d", &X);

    int T[N];
    for (i = 0; i < N; i++) {
        printf("Masukkan elemen ke-%d : ", i+1);
        scanf("%d", &T[i]);
    }

    printf("\n");
    printf("Dengan menggunakan SEQSearch1 : \n");
    SEQSearch1(T, N, IX, X);
    printf("\n");
    printf("Dengan menggunakan SEQSearch2 : \n");
    SEQSearch2(T, N, X, IX, Found);
    printf("\n");

    return 0;
}