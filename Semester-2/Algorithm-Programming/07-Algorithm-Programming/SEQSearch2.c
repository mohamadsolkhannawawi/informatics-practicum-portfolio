/* Nama File  : SEQSearch2.c */
/* Deskripsi  : File sequential search versi 2*/
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 7 Mei 2024*/


#include "SEQSearch2.h"
#include <stdio.h>
#include <stdbool.h>

void SEQSearch2(int T[], int N, int X, int IX, bool Found) {
    // Kamus
    int i; // Counter

    // Algortima
    i = 0;
    Found = false;
    while ( i < N && !Found ) {
        if (T[i] == X ) {
            Found = true;
        } else {
            i++;
        }
    }

    if (Found) {
        IX = i + 1;
        printf("Elemen %d berada pada indeks %d\n", X, IX);
    } else {
        IX = 0;
        printf("Elemen %d tidak ditemukan\n", X);
    }
}
   