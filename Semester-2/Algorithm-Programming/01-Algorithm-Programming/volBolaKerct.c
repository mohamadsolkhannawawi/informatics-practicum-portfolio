/* Nama File  : volBolaKerct.c */
/* Deskripsi  : Menghitung volume bola dan volume kerucut */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 22 Februari 2024*/


#include <stdio.h>

int main() {
    //kamus
    const float PHI = 3.1415;
    float r;
    float Vb;
    float Vk;

    //Algoritma
    printf("\n============ Menghitung Volume Bola dan Volume Kerucut =============\n");
    printf("====================================================================\n");

    printf("Masukan jari-jari (r) : ");
    scanf("%f", &r);

    printf("\n====================================================================");
    printf("\nDiketahui : \n");
    printf("r = %f\n", r);
    printf("PHI = %f\n", PHI);
    printf("Volume Kerucut = 1/2 * Volume Bola\n");

    printf("\n====================================================================");
    printf("\nRumus : \n");
    printf("Volume Bola = 4/3 * (PHI * r * r * r)\n");
    printf("Volume Kerucut = 1/2 * Volume Bola\n");

    printf("\n====================================================================");
    printf("\nMaka : \n");

    Vb = (4 * (PHI * r * r * r)/3);
    Vk = (4 * (PHI * r * r * r)/3)/2;

    printf("Volume Bola = (4/3 * (%f * %f * %f * %f)) \n", PHI, r, r, r);
    printf("Volume Bola = %f\n", Vb);

    printf("\nVolume Kerucut = (1/2 * %f)", Vb);
    printf("\nVolume Kerucut = %f", Vk);

    printf("\n====================================================================");
    return 0;

}