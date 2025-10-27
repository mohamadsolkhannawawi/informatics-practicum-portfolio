// Diberikan sebuah array of integers dengan panjang elemen n dan berisi sembarang bilangan 
// bulat. Susunlah array tersebut sehingga terdapat pengelompokan bilangan berdasarkan
// ganjil-genap. Letakkan bilangan ganjil sebelum bilangan genap

#include <stdio.h>

int main() {
    //Kamus
    int i; // Counter
    int n; // Panjang array
    // Membaca panjang array
    scanf("%d", &n);

    int arr[n];
    // Membaca elemen array
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //Algoritma
    // Menampilkan array yang telah diurutkan berdasarkan ganjil 
    for (i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }

    // Menampilkan array yang telah diurutkan berdasarkan genap
    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}
// Input: 10
// 1 2 3 4 5 6 7 8 9 10
// Output: 1 3 5 7 9 2 4 6 8 10
