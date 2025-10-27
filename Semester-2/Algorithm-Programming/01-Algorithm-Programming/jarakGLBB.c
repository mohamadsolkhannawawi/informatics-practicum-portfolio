/* Nama File  : jarakGLBB.c */
/* Deskripsi  : Menghitung jarak GLBB */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 22 Februari 2024*/


#include <stdio.h>

int main() {
    //kamus
    float v0;
    float t;
    float a;
    float S;

    //Algoritma
    printf("\n============= Menghitung Jarak GLBB =============\n");
    printf("Masukan kecepatan awal (v0) = ");
    scanf("%f", &v0);

    printf("Masukan waktu (t) = ");
    scanf("%f", &t);

    printf("Masukan percepatan (a) = ");
    scanf("%f", &a);

    printf("\n=================================================");
    printf("\nDiketahui : \n");
    printf("v0 = %f\n", v0);
    printf("t = %f\n", t);
    printf("a = %f\n", a);

    printf("\n=================================================");
    printf("\nRumus : \n");
    printf("S = vo*t + ((a*t*t)/2)\n");

    printf("\n=================================================");
    printf("\nMaka : \n");
    printf("S = %f*%f + ((%f*%f*%f)/2)\n", v0, t, a, t, t);

    S = v0*t + ((a*t*t)/2);
    printf("S = %f", S);
    printf("\n=================================================");

};