#include <stdio.h>
#include <stdlib.h>

int add(int x, int y){ // Ini fungsi
    //Kamus


    //Algoritma
    return x + y;
}

void luaspersegi(int luas, int sisi){ // Pakai Prosedur
    //Kamus

    //Algoritma
    luas = sisi * sisi;
    printf("Luas persegi dengan sisi %d = %d\n", sisi, luas);
}

void luaspersegi2(int *luas, int sisi){ // Pakai Pointer
    //Kamus

    //Algoritma
    *luas = sisi * sisi;
}

void main() {
    //Kamus
    int x, y;
    int luasP;

    //Algoritma
    x = 10;
    y = 5;

    printf("Hasil penjumlahan x + y = %d\n", add(x, y));
    luaspersegi(luasP, y);
    luaspersegi2(&luasP, x);
    printf("Luas persegi dengan sisi = %d\n",luasP);

}
 