/* Nama File  : MINSort.c */
/* Deskripsi  : Mengurut tabel integer [1..N] terurut membesar dengan minimum suksesif.*/
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 16 Mei 2024*/

#include <stdio.h>

void MINSort(int T[], int N){
    //Kamus lokal
    int i, j, temp, IMIN, pass;
    //Algoritma
    for (pass = 0; pass<N; pass++){
        IMIN = pass;
        for (i = pass+1; i<N; i++){
            if (T[IMIN] > T[i]){
                IMIN = i;
            }
        }
        temp = T[IMIN];
        T[IMIN] = T[pass];
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
        MINSort(T, N);
        printf("\nSetelah diurutkan: ");
        for (i=0; i<N; i++){
                printf("%d ", T[i]);
        }
        return 0;
}