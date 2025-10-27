/* Nama File  : SimetriTabel.c */
/* Deskripsi  : Mengecek dan menampilkan di layar apakah tabel T1 simteri dengan tabel T2.*/
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 17 Maret 2024*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    //Kamus
    int n1, n2;
    printf("=================== Simetri Tabel =====================\n\n");
    printf("Masukkan ukuran Tabel T1: ");
    scanf("%d", &n1);
    printf("Masukkan ukuran Tabel T2: ");
    scanf("%d", &n2);

    int Elmt1[n1], Elmt2[n2];
    int T1[n1], T2[n2];
    int i;
    bool simetris;

    //Algoritma
    printf("\n========================================================\n\n");
    if ( n1 != n2) {
        printf("Tabel T1 tidak simetris dengan Tabel T2.\n");
    } else {
        printf("Masukkan elemen-elemen Tabel T1:\n");
        for (i = 0; i < n1; i++) {
            printf("T1[%d]: ", i);
            scanf("%d", &T1[i]);
        }

        printf("Masukkan elemen-elemen Tabel T2:\n");
        for (i = 0; i < n2; i++) {
            printf("T2[%d]: ", i);
            scanf("%d", &T2[i]);
        }

        simetris = true;
        for (i = 0; i < n1; i++) {
            if (T1[i] != T2[i]) {
                simetris = false;
                break;
            }
        }
        printf("\n========================================================\n\n");
        if (simetris) {
            printf("Tabel T1 simetris dengan Tabel T2.\n");
        } else {
            printf("Tabel T1 tidak simetris dengan Tabel T2.\n");
        }
    }
    printf("\n========================================================\n");
    return 0;
}
