/* Nama File  : BukanKelipatanK.c */
/* Deskripsi  : Mengecek dan menampilkan di layar sebuah deret angka tanpa k dan kelipatannya */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 13 Maret 2024*/

#include <stdio.h>

int main () {
    //kamus
    int i, k, n, jumlahDeret; // k sebagai inputan k, n sebagai inputan n, i sebagai counter, jumlahDeret untuk menampung jumlah deret

    //Algoritma
    printf("\n============== Bukan Kelipatan K =================\n");

    printf("\nMasukan k : ");
    scanf("%d", &k);
    printf("\nMasukan n : ");
    scanf("%d", &n);

    printf("\n=================================================\n");

    printf("\nDeret Bilangan\n");
    jumlahDeret = 0;
    for (i = 1; jumlahDeret < n; i++){
        if (i % k != 0){
            jumlahDeret++;
            printf("%d ", i);
        }
    }

    printf("\n\n=================================================\n");
    return 0;
}