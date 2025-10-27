/* Nama File  : CintaLingkaran.c */
/* Deskripsi  : Mengecek dan menampilkan di layar pola cinta lingkaran dari sebuah Tay yang di jamin membentuk permutasi.*/
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 18 Maret 2024*/

#include <stdio.h>

int main() {
    //Kamus
    int i, next;
    int n;
    printf("=================== Cinta Lingkaran =====================\n\n");
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);
    int T[n];
    int visited[n];

    //Algoritma
    if (n < 1) {
        printf("Tabel harus berisi minimal 1 elemen.\n");
    } else {
        for (i = 0; i < n; i++) {
            printf("Masukkan index ke-%d: ", i + 1);
            scanf("%d", &T[i]);
        }
        printf("\n========================================================\n\n");
        for (i = 0; i < n; i++) {
            visited[i] = 0;
        }

        for (i = 0; i < n; i++) {
            if (!visited[i]) { 
                printf("%d", i + 1);
                visited[i] = 1;

                next = T[i] - 1;
                while (next != i) {
                    printf("-%d", next + 1);
                    visited[next] = 1;
                    next = T[next] - 1;
                }
                printf("\n");
            }
        }
    }
    printf("\n========================================================\n");
    return 0;
}
