#include <stdio.h>

int main() {
    int n, x;
    // Membaca panjang array dan jarak pengelompokan
    scanf("%d", &n);
    scanf("%d", &x);

    int arr[n];
    // Membaca elemen array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Menampilkan array yang telah diurutkan berdasarkan jarak x
    for (int i = 0; i < x; i++) {
        for (int j = i; j < n; j += x) {
            printf("%d ", arr[j]);
        }
    }
    printf("\n");

    return 0;
}