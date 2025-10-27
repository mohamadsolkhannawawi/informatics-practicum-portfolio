#include <stdio.h>

int main() {
    int n, target, i;

    printf("Masukkan panjang array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Masukkan target x: ");
    scanf("%d", &target);

    printf("Masukkan elemen array sebanyak %d: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n < 2) {
        printf("Tidak ada output");
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("%d dan %d\n", arr[i], arr[j]);
            }
        }
    }
    
    return 0;
}