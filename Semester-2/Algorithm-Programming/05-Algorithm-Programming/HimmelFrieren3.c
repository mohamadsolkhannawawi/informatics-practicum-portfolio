#include <stdio.h>
#include <stdbool.h>

int main() {
    // Kamus
    int n, i, j;
    bool isPrime;
    int frierenKillCount, himmelKillCount;   
    // Membaca banyaknya iblis
    scanf("%d", &n);

    int iblis[n];
    // Membaca kekuatan iblis
    for (i = 0; i < n; i++) {
        scanf("%d", &iblis[i]);
    }

    // Algoritma
    frierenKillCount = 0, himmelKillCount = 0;   
        printf("Frieren: ");
        for (i = 0; i < n ; i++){
            if (iblis[i] % 5 == 0 && iblis[i] <= 150 && iblis[i] != 0) {
                frierenKillCount++;
                printf("%d ", iblis[i]);
            }
        }
        printf("\n");
    
        printf("Himmel: ");
        for (i = 0; i < n; i++) {
            if (iblis[i] > 1) {
                isPrime = true;
                for (j = 2; j * j <= iblis[i]; j++) {
                    if (iblis[i] % j == 0) {
                        isPrime = false;
                        break;
                    }
                }
                if (isPrime && iblis[i] <= 100 && iblis[i] % 5 != 0) {
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
            printf("Seri!\n");
        }


    return 0;
}