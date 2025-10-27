/* Nama File  : MAXSort.c */
/* Deskripsi  : Mengurut tabel integer [1..N] terurut mengecil dengan maksimum suksesif.*/ 
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 16 Mei 2024*/

#include <stdio.h>

void MAXSort(int T[], int N){
    //Kamus lokal
    int i, j, temp, IMAX, pass;
    //Algoritma
    for (pass = 0; pass<N; pass++){
        IMAX = pass;
        for (i = pass+1; i<N; i++){
            if (T[IMAX] < T[i]){
                IMAX = i;
            }
        }
        temp = T[IMAX];
        T[IMAX] = T[pass];
        T[pass] = temp;
    }
}

int main() {
        int i;
        int T[5] = {64, 5, 12, 22, 11};
        int N = 5;

        printf("Sebelum diurutkan: ");
        for (i=0; i<N; i++){
                printf("%d ", T[i]);
        }
        MAXSort(T, N);
        printf("\nSetelah diurutkan: ");
        for (i=0; i<N; i++){
                printf("%d ", T[i]);
        }
        return 0;
}