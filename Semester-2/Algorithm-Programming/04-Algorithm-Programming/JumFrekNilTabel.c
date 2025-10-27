/* Nama File  : JumFrekNilTabel.c */
/* Deskripsi  : Menghitung dan menampilkan di layar jumlah nilai-nilai elemen dari tabel yang frekuensi kemunculannya lebih dari satu kali.*/
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 17 Maret 2024*/

#include <stdio.h>

int main() {
    //Kamus
    int N;
    printf("=================== Jumlah Frekuensi Nilai Tabel =====================\n\n");
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &N);

    int Elmt[N];
    int frekuensi[N];
    int i, j;
    int total;

    //Algoritma
    printf("\n========================================================\n\n");
    if ( N < 1) {
        printf("Tabel harus berisi minimal 1 elemen.\n");
    } else {
        for (i = 0; i < N; i++) {
            printf("Masukkan index ke-%d: ", i);
            scanf("%d", &Elmt[i]);
            frekuensi[i] = 0;
        }

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (Elmt[i] == Elmt[j]) {
                    frekuensi[i]++;
                }
            }
        }

        for (i = 0; i < N; i++) {
            if (frekuensi[i] > 1) {
                total += Elmt[i];
            }
        }
        printf("\n========================================================\n\n");
        printf("Total nya adalah %d\n", total);
    }
    printf("\n========================================================\n");
    return 0;
}
