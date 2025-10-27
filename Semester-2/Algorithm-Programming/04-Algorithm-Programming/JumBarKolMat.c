/* Nama File  : JumBarKolMat.c */
/* Deskripsi  : Menghitung dan menampilkan di layar jumlah elemen dari setiap baris dan kolom dari matriks.*/
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 17 Maret 2024*/

#include <stdio.h>

int main() {
    //Kamus
    int i, j;
    int baris, kolom;
    printf("=================== Jumlah Baris dan Kolom Matriks =====================\n\n");
    printf("Masukkan jumlah baris matriks: ");
    scanf("%d", &baris);
    printf("Masukkan jumlah kolom matriks: ");
    scanf("%d", &kolom);
    int T[baris][kolom];
    int total_baris, total_kolom;
    
    //Algoritma
    printf("\n========================================================\n\n");
    if (baris < 2 && kolom < 2) {
        printf("Matriks harus berisi minimal 2 baris dan 2 kolom untuk membentuk 2 dimensi.\n");
    } else {
        printf("Masukkan elemen-elemen matriks:\n");
        for (i = 0; i < baris; i++) {
            for (j = 0; j < kolom; j++) {
                printf("Elemen ke-%d,%d: ", i + 1, j + 1);
                scanf("%d", &T[i][j]);
            }
        }

        printf("========================================================\n\n");
        for (i = 0; i < baris; i++) {
            total_baris = 0;
            for (int j = 0; j < kolom; j++) {
                total_baris += T[i][j];
            }
            printf("Baris ke-%d -> %d\n", i + 1, total_baris);
        }
        for (j = 0; j < kolom; j++) {
            total_kolom = 0;
            for (int i = 0; i < baris; i++) {
                total_kolom += T[i][j];
            }
            printf("Kolom ke-%d -> %d\n", j + 1, total_kolom);
        }
    }
    printf("\n========================================================\n");
    return 0;
}
