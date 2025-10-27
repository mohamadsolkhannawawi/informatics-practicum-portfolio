#include <stdio.h>

int main() {
    int num, original, sisa, sum = 0;

    printf("Masukkan angka: ");
    scanf("%d", &num);

    original = num;

    while (num != 0) {
        sisa = num % 10;
        int fact = 1;
        for (int i = 1; i <= sisa; i++) {
            fact *= i;
        }
        sum += fact;
        num /= 10;
    }

    if (sum == original) {
        printf("KUAT");
    } else {
        printf("lemah");
    }

    return 0;
}