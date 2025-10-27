/* Nama File  : SEQSearch1.c */
/* Deskripsi  : Prosedure sequential search versi 1*/
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 7 Mei 2024*/

#ifndef SEQSEARCH1_C
#define SEQSEARCH1_C

#include "SEQSearch1.h"
#include <stdio.h>

void SEQSearch1(int T[], int N, int IX, int X) {
    // Kamus
    int i;

    // Algoritma
    i = 0;
    while ( i < N && T[i] != X ) {
        i++;
    }
    if (T[i] == X) {
        IX = i + 1;
        printf("Elemen %d berada pada indeks %d\n", X, IX);
    } else {
        IX = 0;
        printf("Elemen %d tidak ditemukan\n", X);
    }
}

#endif
