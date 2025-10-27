#include <stdio.h>

int main() {
    // Kamus
    int n; // Banyaknya elemen array
    int a; // Batas bawah suara
    int b; // Batas atas suara

    // Membaca nilai n, a, dan b
    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);

    int T[n]; // Array yang menyimpan nilai suara
    for (int i = 0; i < n; i++) {
        scanf("%d", &T[i]);
    }

    // Algoritma
    // Cetak label jenis suara untuk suara pertama
    if (T[0] < a) {
        printf("Alto: ");
    } else if (T[0] > b) {
        printf("Sopran: ");
    } else {
        printf("Mezzo-sopran: ");
    }
    printf("%d ", T[0]); // Cetak suara pertama
    for (int i = 1; i < n; i++) {
        // Cetak baris baru dan label jenis suara baru jika suara sekarang berbeda dengan suara sebelumnya
        if ((T[i] < a && T[i - 1] >= a) || (T[i] > b && T[i - 1] <= b) || (T[i] >= a && T[i] <= b && (T[i - 1] < a || T[i - 1] > b))) {
            printf("\n");
            if (T[i] < a) {
                printf("Alto: ");
            } else if (T[i] > b) {
                printf("Sopran: ");
            } else {
                printf("Mezzo-sopran: ");
            }
        }
        printf("%d ", T[i]);
    }

    return 0;
}
