/* Nama File  : InsertionSORT.c */
/* Deskripsi  : Mengurut tabel integer [1..N] dengan insertion sort (Penyisipan).*/ 
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 24 Mei 2024*/


#include <stdio.h>

void InsertionSORT(int T[], int N) {
    //Kamus Lokal
    int i, Pass, Temp;

    //Algoritma
    for (Pass = 1; Pass < N; Pass++) {
        Temp = T[Pass];
        i = Pass - 1;
        while (Temp < T[i] && i > 0) {
            T[i + 1] = T[i];
            i = i - 1;
        }
        if  (Temp >= T[i]) {
            T[i + 1] = Temp;
        } else {
            T[i + 1] = T[i];
            T[i] = Temp;
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
    InsertionSORT(T, N);
    printf("\nSetelah diurutkan: \n");
    for (i = 0; i < N; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");
    return 0;
}