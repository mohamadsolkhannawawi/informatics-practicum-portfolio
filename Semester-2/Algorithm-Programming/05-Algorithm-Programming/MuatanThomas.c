#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    //Kamus
    int i, j; // Counter 
    int n; // Banyaknya barang
    int items; // Menyimpan jumlah barang yang bisa diangkut
    int maxItems; // Banyaknya barang yang bisa diangkut
    int maxWeight; // Berat maksimum yang bisa diangkut
    int sumWeight; // Menyimpan jumlah berat barang

    //Membaca masukan beras maksimum dan banyaknya barang
    scanf("%d", &maxWeight);
    scanf("%d", &n);

    int arrBarang[n];
    for (i = 0 ; i < n ; i++) {
        scanf("%d", &arrBarang[i]); 
    }

    //Algoritma
    maxItems = 0;
    for(i = 0 ; i < n ; i++) {   
        sumWeight = 0;
        items = 0;
        for(j = i ; j < n; j++) {
            sumWeight += arrBarang[j];
            if (sumWeight <= maxWeight) {
                items++;
            } else {
                break;
            }
        }
        if (items > maxItems) {
            maxItems = items;
        }
    }
    
    printf("%d", maxItems);
    return 0;
}