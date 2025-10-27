/* Nama File  : AkagiKongou.c */
/* Deskripsi  : Menentukan alur perubahan angka A, B, C dan menampilkan hasilnya di layar */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 13 Maret 2024*/

#include <stdio.h>
#include <stdbool.h>

int main(){
    //kamus
    int A, B, C, Babak; // A untuk inputan pertama, B untuk inputan kedua, C untuk penampung hasil A - B

    //Algoritma
    printf("\n================= Akagi Kongou ===================\n");

    printf("\nMAsukan angka yang dipilih Akagi  :  ");
    scanf("%d", &A);
    printf("\nMAsukan angka yang dipilih Kongou :  ");
    scanf("%d", &B);

    printf("\n=================================================\n\n");

    Babak = 1;
    while (true) {
        printf("Babak %d\n", Babak);
        C = A - B;
        A = B;
        B = C;

        printf("C = %d\n", C);
        printf("A = %d\n", A);
        printf("B = %d\n", B);

        if (B == 0) {
            printf("Pemenangnya adalah Kongou\n");
            break;
        } else if (B < 0) {
            printf("Pemenangnya adalah Akagi\n");
            break;
        }
        Babak++;       
    }

    printf("\n=================================================");
    return 0;
}

    
