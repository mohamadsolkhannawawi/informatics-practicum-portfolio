/* Nama File  : CountSORT.c */
/* Deskripsi  : Mengurut tabel integer [1..N] dengan pencacahan*/
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 16 Mei 2024*/

#include <stdio.h>

void CountSORT(int T[], int N, int ValMin, int ValMax) {
    //Kamus lokal
    int TabCount[ValMax+1];
    int i, j;

    //Algoritma
    // Inisialisasi TabCount
    for (i = 0; i <= ValMax; i++) {
        TabCount[i] = 0;
    }

    // Menghitung frekuensi kemunculan setiap elemen dalam array T
    for (i = 0; i < N; i++) {
        TabCount[T[i]]++;
    }

    int k = -1; // k sebagai indeks untuk T
    // Mengisi kembali array T dengan elemen yang telah diurutkan
    for (i = ValMin; i <= ValMax; i++) {
        for (j = 0; j < TabCount[i]; j++) {
                k++;
                T[k] = i; // Memasukkan i ke dalam array T sebanyak TabCount[i] kali
        }
    }
}

int main() {
    // Kamus
    int i;
    int T[8] = {2, 5, 3, 0, 2, 3, 0, 3};
    int N = 8;

    // Algoritma
    printf("Sebelum diurutkan: ");
    for (i = 0; i < N; i++) {
        printf("%d ", T[i]);
    }

    CountSORT(T, N, 0, 5); // Mengurutkan array T menggunakan Counting Sort

    printf("\nSetelah diurutkan: ");
    for (i = 0; i < N; i++) {
        printf("%d ", T[i]);
    }

    return 0;
}
