/* Nama File  : SegitigaUnik.c */
/* Deskripsi  : Mengecek dan menampilkan di layar sebuah pola bilangan segitiga unik dengan n baris yang berisikan angka 0-9, dan jika angkanya habis kembali ke 0 */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 13 Maret 2024*/

#include <stdio.h>

int main() {
  //kamus
    int n, i, j, num; // n sebagai inputan n, i sebagai counter, j sebagai counter, num untuk menampung angka yang akan ditampilkan

    //Algoritma
    printf("\n================= Segitiga Unik =================\n");

    printf("\nMasukkan n: ");
    scanf("%d", &n);

    printf("\n=================================================\n");

    num = 0; 
    printf("\nPola Segitiga\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d", num++);
            if ( num == 10 ) {
                num = 0;
            }
        }
    
        printf("\n");
        num = num++;
    }
    
    printf("\n===============================================\n");
    return 0;
}
