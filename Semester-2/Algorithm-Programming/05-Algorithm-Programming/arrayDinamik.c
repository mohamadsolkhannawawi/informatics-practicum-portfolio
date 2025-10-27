// Diberikan sebuah array of integers dengan panjang elemen n dan berisi sembarang 
// bilangan bulat. Susunlah array tersebut sehingga terdapat pengelompokan bilangan
// berdasarkan ganjil-genap. Letakkan bilangan ganjil sebelum bilangan genap

#include <stdio.h>
#include <stdlib.h>

int main () {
    //Kamus
    int var;
    int T[3] = {100, 200, 300};
    int i;
    int *P;

    // Algoritma
    printf("============= Pointer ============\n");
    var = 100;
    P = (int*) malloc (1*sizeof(int));
    *P = var;
    printf("value var : %d\n", var);
    printf("Alamat var : %d\n", &var);
    printf("Value Pointer P : %d\n", *P);
    printf("Alamat pointer P yang dialokasikan malloc : %p\n", P);

    free(P); //Dealokasi

    printf("==========Array=========\n");
    P = (int*) malloc (3*sizeof(int));
    for (i = 0; i < 3; i++){
        *(P + i) = T[i];
        printf("Value P[%d] : %d\n", i, *(P + i));
    }
}