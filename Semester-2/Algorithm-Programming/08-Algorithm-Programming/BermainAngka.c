/* Nama File  : BermainAngka.c */
/* Deskripsi  : Mencari angka yang dipikirkan 1 - 100 dengan 
menggunakan algoritma binary search */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 16 Mei 2024*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void BermainAngka(int T[100], int N, bool *Found) {
    // Kamus Lokal
    int Atas, Bawah, Tengah;
    char input[10];

    // Algoritma
    Atas = 0;
    Bawah = N - 1;
    *Found = false;

    while ((Atas <= Bawah) && (!*Found)) {
        Tengah = (Atas + Bawah) / 2;
        printf("Apakah %d adalah angka yang Anda pikirkan? (pas/besar/kecil): ", T[Tengah]);
        scanf("%s", input);

        if (strcmp(input, "pas") == 0) {
            *Found = true;
        } else if (strcmp(input, "besar") == 0) {
            Bawah = Tengah - 1;
        } else if (strcmp(input, "kecil") == 0) {
            Atas = Tengah + 1;
        } else {
            printf("Input tidak valid. Silakan masukkan 'pas', 'besar', atau 'kecil'.\n");
        }
    }
}

int main() {
    // Kamus
    int N = 100;
    int T[100] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
        51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
        61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
        71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
        81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
        91, 92, 93, 94, 95, 96, 97, 98, 99, 100
    };
    bool Found;

    // Algoritma
    BermainAngka(T, N, &Found);

    if (Found) {
        printf("Angka ditemukan!\n");
    } else {
        printf("Angka tidak ditemukan.\n");
    }

    return 0;
}
