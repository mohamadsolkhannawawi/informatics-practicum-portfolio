/* Nama File  : NilMax2Tabel.c */
/* Deskripsi  : Mengecek dan menampilkan di layar nilai maksimum kedua dari tabel yang berisi angka integer.*/
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 17 Maret 2024*/

#include <stdio.h>
#include <limits.h>

int main() {
    //Kamus
    int N;
    printf("=================== Nilai Maksimum Kedua =====================\n\n");
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &N);

    int Elmt[N];
    int i, max1, max2;

    //Algoritma
    printf("\n========================================================\n\n");
    if (N < 2) {
        printf("Tabel harus berisi minimal 2 elemen.\n");
    }else {
        for (i = 0; i < N; i++) {
            printf("Masukkan index ke-%d: ", i);
            scanf("%d", &Elmt[i]);
        }
        
        max1 = INT_MIN;
        max2 = INT_MIN;
        for (i = 0; i < N; i++) {
            if (Elmt[i] > max1) {
                max2 = max1;
                max1 = Elmt[i];
            } else if (Elmt[i] > max2 && Elmt[i] != max1) {
                max2 = Elmt[i];
            }
        }
    }
    printf("\nNilai maksimum ke-2: %d\n", max2);
    printf("\n========================================================\n");
    return 0;
}
