/* Nama File  : jarakPBola.c */
/* Deskripsi  : Menghitung jarak parabola */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 22 Februari 2024*/


#include <stdio.h>

int main() {
    //kamus
    const float g = 9.8;
    float v0;
    float t;
    float y;
    

    //Algoritma
    printf("\n==================== Menghitung Jarak Parabola =====================\n");
    printf("====================================================================\n");

    printf("Masukan kecepatan awal (v0) : ");
    scanf("%f", &v0);

    printf("Masukan waktu (t) : ");
    scanf("%f", &t);

    printf("\n====================================================================");
    printf("\nDiketahui : \n");
    printf("v0 = %f\n", v0);
    printf("t = %f\n", t);
    printf("g = %f\n", g);

    printf("\n====================================================================");
    printf("\nRumus : \n");
    printf("y = v0 * t - 1/2 * (g * t * t).  \n");

    printf("\n====================================================================");
    printf("\nMaka : \n");

    y = (v0 * t) - (g * t * t)/2;

    printf("y = (%f * %f) - 1/2 * (%f * %f * %f) \n", v0, t, g, t, t);
    printf("y = %f\n", y);

    printf("\n====================================================================");
    return 0;

}