/* Nama File  : gayaSentr.c */
/* Deskripsi  : Menghitung gaya sentripetal */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 22 Februari 2024*/


#include <stdio.h>

int main() {
    //kamus
    float m;
    float v;
    float r;
    float F;

    //Algoritma
    printf("\n==================== Menghitung Gaya Sentripetal ===================\n");
    printf("====================================================================\n");

    printf("Masukan massa (m) : ");
    scanf("%f", &m);

    printf("Masukan kecepatan (v) : ");
    scanf("%f", &v);

    printf("Masukan jari-jari (r) : ");
    scanf("%f", &r);

    printf("\n====================================================================");
    printf("\nDiketahui : \n");
    printf("m = %f\n", m);
    printf("v = %f\n", v);
    printf("r = %f\n", r);
    
    printf("\n====================================================================");
    printf("\nRumus : \n");
    printf("F = m * ((v * v) / r) \n");

    printf("\n====================================================================");
    printf("\nMaka : \n");

    F = m * ((v * v) / r);

    printf("F = %f * ((%f * %f )/%f) \n", m, v, v, r);
    printf("F = %f\n", F);

    printf("\n====================================================================");
    return 0;

}