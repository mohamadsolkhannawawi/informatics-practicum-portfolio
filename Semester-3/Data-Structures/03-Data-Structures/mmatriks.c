/* Program   : mmatriks.c */
/* Deskripsi : file DRIVER modul matriks integer */
/* NIM/Nama  : 24060123120020/Mohamad Solkhan Nawawi*/
/* Tanggal   : Jumat, 13 September 2024*/
/***********************************/

#include <stdio.h>
#include "matriks.c"
#include "boolean.h"

int main() {
    // KAMUS LOKAL
    Matriks M1, M2, M3;
    int X , row, col;

    // ALGORITMA
    // Inisialisasi matriks
    initMatriks(&M1);
    initMatriks(&M2);
    initMatriks(&M3);

    // Populasi matriks dengan input dari user
    printf("======================= Mengisi Matriks dengan Populate =======================\n");
    printf("Populasi Matriks M1 (Matriks 3 x 3):\n");
    populateMatriks(&M1, 3, 3);  // Contoh matriks 3x3

    // Tampilkan matriks yang sudah diisi

    printf("Print Matriks M1:\n");
    printMatriks(M1);
    printf("View Matriks M1:\n");
    viewMatriks(M1);

    // Aplikasi getNBaris dan getNKolom
    printf("Jumlah baris M1: %d\n", getNBaris(M1));
    printf("Jumlah kolom M1: %d\n", getNKolom(M1));

    // Aplikasi isEmptyMatriks dan isFullMatriks
    printf("Matriks M1 kosong? %s\n", isEmptyMatriks(M1) ? "Ya" : "Tidak");
    printf("Matriks M1 penuh? %s\n", isFullMatriks(M1) ? "Ya" : "Tidak");

    // Search X
    printf("======================= Pencarian nilai X =======================\n");
    printf("Isi Matriks M1 saat ini:\n");
    printMatriks(M1);
    printf("Masukkan nilai yang ingin dicari di M1: ");
    scanf("%d", &X);
    searchX(M1, X, &row, &col);
    if (row != -999 && col != -999) {
        printf("Elemen %d ditemukan di baris %d kolom %d.\n", X, row, col);
    } else {
        printf("Elemen %d tidak ditemukan.\n", X);
    }

    // Count X
    printf("======================= Menghitung Jumlah Elemen =======================\n");
    printf("Masukkan nilai yang ingin dihitung di M1: ");
    scanf("%d", &X);
    printf("Jumlah elemen %d di M1: %d\n", X, countX(M1, X));

    // Add X
    printf("======================= Menambahkan Elemen ke Matriks =======================\n");
    printf("Masukkan nilai yang ingin ditambahkan di M1: ");
    scanf("%d", &X);
    printf("Masukkan baris yang ingin diisi: ");
    scanf("%d", &row);
    printf("Masukkan kolom yang ingin diisi: ");
    scanf("%d", &col);
    addX(&M1, X, row, col);
    if (M1.cell[row][col] == -999) {
        printf("Elemen %d berhasil ditambahkan di baris %d kolom %d.\n", X, row, col);
    } else {
        printf("Elemen %d gagal ditambahkan di baris %d kolom %d, karena sudah terisi.\n", X, row, col);
    }
    printf("Isi Matriks M1 saat ini:\n");    
    printMatriks(M1);


    // Edit X
    printf("======================= Mengubah Elemen di Matriks =======================\n");
    printf("Masukkan nilai X: ");
    scanf("%d", &X);
    printf("Masukkan baris yang ingin diubah: ");
    scanf("%d", &row);
    printf("Masukkan kolom yang ingin diubah: ");
    scanf("%d", &col);
    editX(&M1, X, row, col);
    if (row <= getNBaris(M1) && col <= getNKolom(M1)) {
        printf("Elemen %d berhasil diubah di baris %d kolom %d.\n", X, row, col);
    } else {
        printf("Elemen %d gagal diubah di baris %d kolom %d, karena melebihi ukuran maksimal.\n", X, row, col);
    }
    printMatriks(M1);

    // Delete X
    printf("======================= Menghapus Elemen di Matriks =======================\n");
    printf("Masukkan nilai yang ingin dihapus di M1: ");
    scanf("%d", &X);
    delX(&M1, X);
    printf("Elemen %d berhasil dihapus.\n", X);
    printMatriks(M1);

    // Populasi Matriks M2 dengan angka random (contoh 3x3)
    printf("======================= Mengisi Matriks dengan Random =======================\n");
    isiMatriksRandom(&M2, 3, 3);
    printf("Matriks M2 (random):\n");
    printMatriks(M2);

    // Populasi Matriks M3 dengan matriks identitas (contoh 3x3)
    printf("======================= Mengisi Matriks dengan Identitas =======================\n");
    isiMatriksIdentitas(&M3, 3);
    printf("Matriks M3 (identitas):\n");
    printMatriks(M3);

    // Penjumlahan matriks
    printf("======================= Operasi Aritmatika =======================\n");
    M3 = addMatriks(M1, M2);
    printf("Hasil penjumlahan M1 + M2:\n");
    printMatriks(M3);

    // Pengurangan matriks
    M3 = subMatriks(M1, M2);
    printf("Hasil pengurangan M1 - M2:\n");
    printMatriks(M3);

    // Perkalian matriks dengan matriks
    M3 = kaliMatriks(M1, M2);
    printf("Hasil perkalian M1 * M2:\n");
    printMatriks(M3);

    // Perkalian matriks dengan skalar
    M3 = kaliSkalarMatriks(M1, 2);
    printf("Hasil perkalian M1 dengan skalar 2:\n");
    printMatriks(M3);

    // Mencari nilai sum matriks
    printf("======================= Operasi Statistik =======================\n");
    printf("Isi Matriks M1 saat ini:\n");
    printMatriks(M1);
    printf("Jumlah elemen M1: %d\n", getSumMatriks(M1));

    // Mencari nilai rata-rata matriks
    printf("Rata-rata M1: %.2f\n", getAverageMatriks(M1));

    // Mencari nilai maksimum dan minimum dalam M1
    printf("Nilai maksimum M1: %d\n", getMaxMatriks(M1));
    printf("Nilai minimum M1: %d\n", getMinMatriks(M1));

    // Transpose matriks
    printf("======================= Transpose Matriks =======================\n");
    printf("Isi Matriks M1 saat ini:\n");
    printMatriks(M1);
    transposeMatriks(&M1);
    printf("Transpose Matriks M1:\n");
    printMatriks(M1);

    // Get transpose matriks
    M3 = getTransposeMatriks(M1);
    printf("Get transpose Matriks M1:\n");
    printMatriks(M3);

    return 0;
}
