#include <stdio.h>
#include <stdbool.h>

int main() {
    // Kamus
    int n; // Banyaknya iblis
    int i, j; // Counter
    bool flagPrima; // Menandai bilangan prima
    int frierenKillCount, himmelKillCount; // Inisialisasi variabel untuk menghitung banyaknya iblis yang berhasil dibunuh

    // Membaca banyaknya iblis
    scanf("%d", &n);

    int iblis[n];
    
    // Membaca kekuatan iblis
    for (i = 0; i < n; i++) {
        scanf("%d", &iblis[i]);
    }

    frierenKillCount = 0;
    himmelKillCount = 0;
    // Algoritma
    printf("Frieren: ");
    for (i = 0; i < n; i++) {
        if (iblis[i] % 5 == 0 && iblis[i] <= 150 && iblis[i] != 0) {
            frierenKillCount++;
            printf("%d ", iblis[i]);
        }
    }
    printf("\n");

    printf("Himmel: ");
    for (i = 0; i < n; i++) {
        if (iblis[i] > 1) {
            flagPrima = true;
            for (j = 2; j * j <= iblis[i]; j++) {
                if (iblis[i] % j == 0) {
                    flagPrima = false; // Bukan bilangan prima
                    break;
                }
            }
            if (flagPrima && iblis[i] <= 100 && iblis[i] % 5 != 0) {
                himmelKillCount++;
                printf("%d ", iblis[i]);
            }
        }
    }
    printf("\n");

    if (frierenKillCount > himmelKillCount) {
        printf("Frieren menang!");
    } else if (himmelKillCount > frierenKillCount) {
        printf("Himmel menang!");
    } else {
        printf("Seri!\n"); // Jika jumlah iblis yang berhasil dibunuh sama
    }

    return 0;
}
