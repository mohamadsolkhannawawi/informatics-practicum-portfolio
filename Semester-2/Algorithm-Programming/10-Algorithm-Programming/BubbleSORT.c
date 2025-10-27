/* Nama File  : BubbleSORT.c */
/* Deskripsi  : Mengurut tabel integer [1..N] dengan bubble sort.*/ 
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 24 Mei 2024*/


#include <stdio.h>

void BubbleSORT(int T[], int N) {
    //Kamus Lokal
    int i, K, Pass, Temp;

    //Algoritma
    for (Pass = 1; Pass <= N-1; Pass++){
        for (K = N-1; K >= Pass; K--){
            if (T[K] < T[K-1]){
                Temp = T[K];
                T[K] = T[K-1];
                T[K-1] = Temp;
            }
        }
    }
}

int main () {
    //Kamus
    int i;
    int T[7] = {8, 16, 2, 4, 23, 1, 7};
    int N = 7;

        
    //Algoritma
    printf("Sebelum diurutkan: \n");
    for (i = 0; i < N; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");

    BubbleSORT(T, N);
    printf("Setelah diurutkan: \n");
    for (i = 0; i < N; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");

    return 0;
}