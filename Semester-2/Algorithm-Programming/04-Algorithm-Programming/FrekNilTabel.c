/* Nama File  : FrekNilTabel.c */
/* Deskripsi  : Mengecek dan menampilkan di layar nilai-nilai elemen dari tabel yang frekuensi kemunculannya lebih dari satu kali.*/
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 17 Maret 2024*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    //Kamus
    int N;
    printf("=================== Frekuensi Nilai Tabel =====================\n\n");
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &N);

    int Elmt[N];
    int frekuensi[N];
    int i, j;
    bool tampil;

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

        printf("\n========================================================\n\n");
        printf("Elemen yang muncul lebih dari sekali: ");
        for (i = 0; i < N; i++) {
            if (frekuensi[i] > 1) {
                tampil = true;
                for (j = 0; j < i; j++) {
                    if (Elmt[i] == Elmt[j]) {
                        tampil = false;
                        break;
                    }
                }
                if (tampil) {
                    printf("%d ", Elmt[i]);
                }
            }
        }
    }
    printf("\n\n========================================================\n");
    return 0;
}
