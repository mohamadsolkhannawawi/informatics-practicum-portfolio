#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    // Kamus
    int n, a, b;
    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);

    int T[n];
    int state[n];

    // Loop untuk memasukkan nilai elemen T dan menentukan keadaannya
    for (int i = 0; i < n; i++) {
        scanf("%d", &T[i]);
        if (T[i] < a) {
            state[i] = 1; // 1 untuk "Alto"
        } else if (T[i] > b) {
            state[i] = 3; // 3 untuk "Sopran"
        } else {
            state[i] = 2; // 2 untuk "Mezzo-sopran"
        }
    }

    //Algotitma
    // Loop untuk mencetak urutan elemen T dengan menampilkan jenis suaranya
    for (int i = 0; i < n; i++) {
        if (T[i] < a) {
            if (state[i] == state[i - 1]) {
                printf("%d ", T[i]);
            } else {
                if (i != 0) {
                    printf("\n");
                }
                printf("Alto: ");
                printf("%d ", T[i]);
            }
        } else if (T[i] > b) {
            if (state[i] == state[i - 1]) {
                printf("%d ", T[i]);
            } else {
                if (i != 0) {
                    printf("\n");
                }
                printf("Sopran: ");
                printf("%d ", T[i]);
            }
        } else {
            if (state[i] == state[i - 1]) {
                printf("%d ", T[i]);
            } else {
                if (i != 0) {
                    printf("\n");
                }
                printf("Mezzo-sopran: ");
                printf("%d ", T[i]);
            }
        }
    }

    return 0;
}
