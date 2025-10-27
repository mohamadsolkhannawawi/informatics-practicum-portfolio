#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    // Kamus
    int i, j; // Counter
    int n; // Banyaknya iblis
    int frierenKill, himmelKill; // Inisialisasi variabel untuk menghitung banyaknya iblis yang berhasil dibunuh
    bool flagPrima; // Menandai bilangan prima
    scanf("%d", &n);
    int iblis[n];

    // Algoritma
    frierenKill = 0, himmelKill = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &iblis[i]);
        if (iblis[i] != 0 && iblis[i] % 5 == 0 && iblis[i] <= 150) {
            frierenKill++;
        } else if (iblis[i] > 1 && iblis[i] % 5 != 0 && iblis[i] <= 100) {
            flagPrima = true;
            for (j = 2; j <= sqrt(iblis[i]); j++) {
                if (iblis[i] % j == 0) {
                    flagPrima = false;
                    break;
                }
            }
            if (flagPrima) {
                himmelKill++;
            }
        }
    }

    if (frierenKill > 0) {
        printf("Frieren: ");
        for (i = 0; i < n; i++) {
            if (iblis[i] != 0 && iblis[i] % 5 == 0 && iblis[i] <= 150) {
                printf("%d ", iblis[i]);
            }
        }
        printf("\n");
    }

    if (himmelKill > 0) {
        printf("Himmel: ");
        for (i = 0; i < n; i++) {
            if (iblis[i] > 1 && iblis[i] % 5 != 0 && iblis[i] <= 100) {
                flagPrima = 1;
                for (j = 2; j <= sqrt(iblis[i]); j++) {
                    if (iblis[i] % j == 0) {
                        flagPrima = 0;
                        break;
                    }
                }
                if (flagPrima) {
                    printf("%d ", iblis[i]);
                }
            }
        }
        printf("\n");
    }

    if (frierenKill > himmelKill) {
        printf("Frieren menang!");
    } else if (himmelKill > frierenKill) {
        printf("Himmel menang!");
    } else {
        printf("Seri!\n");
    }

    return 0;
}