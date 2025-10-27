#include <stdio.h>
#include <stdlib.h>

int main() {
    // Deklarasi Variabel
    int maxWeight, n, maxItems = 0;

    // Input batas maksimum berat dan jumlah barang
    scanf("%d", &maxWeight);
    scanf("%d", &n);

    // Deklarasi array untuk menyimpan berat barang
    int *arrBarang = (int*) malloc(n * sizeof(int));
    if (arrBarang == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input berat dari setiap barang dan mencari jumlah barang maksimum yang dapat dimuat
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrBarang[i]);
        int sumWeight = 0, items = 0;
        for (int j = i; j < n; j++) {
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
    
    // Output jumlah maksimum barang yang dapat dimuat
    printf("%d", maxItems);

    // Free allocated memory
    free(arrBarang);

    return 0;
}
