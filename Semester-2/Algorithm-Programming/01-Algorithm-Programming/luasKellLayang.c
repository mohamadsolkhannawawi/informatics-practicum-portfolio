/* Nama File  : luasKellLayang.c */
/* Deskripsi  : Menghitung Luas dan Keliling Layang-layang */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 22 Februari 2024*/


#include <stdio.h>

int main() {
    //kamus
    float s1;
    float s2;
    float d1;
    float d2;
    float Luas;
    float Kell;

    //Algoritma
    printf("\n============ Menghitung Luas dan Keliling Layang-layang ============\n");
    printf("====================================================================\n");

    printf("Masukan sisi satu (s1) : ");
    scanf("%f", &s1);

    printf("Masukan sisi dua (s2) : ");
    scanf("%f", &s2);

    printf("Masukan diagonal satu (d1) : ");
    scanf("%f", &d1);

    printf("Masukan diagonal dua (d2) : ");
    scanf("%f", &d2);

    printf("\n=================================================");
    printf("\nDiketahui : \n");
    printf("s1 = %f\n", s1);
    printf("s2 = %f\n", s2);
    printf("d1 = %f\n", d1);
    printf("d2 = %f\n", d2);

    printf("\n=================================================");
    printf("\nRumus : \n");
    printf("Luas = (d1 * d2)/2 \n");
    printf("Keliling = 2*(s1 + s2)\n");

    printf("\n=================================================");
    printf("\nMaka : \n");

    Luas = ((d1 * d2)/2);
    Kell = (2*(s1 + s2));

    printf("Luas = (%f * %f)/2\n", d1, d2);
    printf("Luas = %f\n", Luas);

    printf("\nKeliling = 2*(%f + %f)\n", s1, s2);
    printf("Keliling = %f", Kell);
    printf("\n=================================================");
    return 0;

}