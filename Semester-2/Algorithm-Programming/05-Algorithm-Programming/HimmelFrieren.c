#include <stdio.h>

int main() {
    int n;
    // Membaca banyaknya iblis
    scanf("%d", &n);

    int iblis[n];
    // Membaca kekuatan iblis
    for (int i = 0; i < n; i++) {
        scanf("%d", &iblis[i]);
    }

    int frierenKillCount = 0, himmelKillCount = 0;
    for (int i = 0; i < n; i++) {
        if (iblis[i] % 5 == 0 && iblis[i] <= 150 && iblis[i] != 0) {
            frierenKillCount++;
        }
        else if (iblis[i] > 1) {
            int isPrime = 1;
            for (int j = 2; j * j <= iblis[i]; j++) {
                if (iblis[i] % j == 0) {
                    isPrime = 0;
                    break;
                }
            }
            if (isPrime && iblis[i] <= 100) {
                himmelKillCount++;
            }
        }
    }
    if (frierenKillCount > 0 && himmelKillCount > 0)
    {
        printf("Frieren: ");
        for (int i = 0; i < n ; i++)
        {
            if (iblis[i] % 5 == 0 && iblis[i] <= 150 && iblis[i] != 0) {
                printf("%d ", iblis[i]);
            }
        }
        printf("\n");
        printf("Himmel: ");
        for (int i = 0; i < n; i++) {
            if (iblis[i] > 1) {
                int isPrime = 1;
                for (int j = 2; j * j <= iblis[i]; j++) {
                    if (iblis[i] % j == 0) {
                        isPrime = 0;
                        break;
                    }
                }
                if (isPrime && iblis[i] <= 100 && iblis[i] % 5 != 0) {
                    printf("%d ", iblis[i]);
                }
            }
        }
        printf("\n");
    }

    if (frierenKillCount > himmelKillCount) {
        printf("Frieren menang!");
    } else if (himmelKillCount > frierenKillCount) {
        printf("Himmel menang!");
    } else {
        printf("Seri!\n");
    }

    return 0;
}