#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int array1[a];
    int array2[b];

    for (int i = 0; i < a; i++) {
        scanf("%d", &array1[i]);
    }

    for (int i = 0; i < b; i++) {
        scanf("%d", &array2[i]);
    }

    int hasil[a]; 
    int bola_hilang = 0;

    for (int i = 0; i < a; i++) {
        int found = 0;
        for (int j = 0; j < b; j++) {
            if (array1[i] == array2[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            hasil[bola_hilang] = array1[i];
            bola_hilang++;
        }
    }

    for (int i = 0; i < bola_hilang - 1; i++) {
        for (int j = i + 1; j < bola_hilang; j++) {
            if (hasil[i] > hasil[j]) {
                int temp = hasil[i];
                hasil[i] = hasil[j];
                hasil[j] = temp;
            }
        }
    }
    

    printf("%d ", bola_hilang);
    for (int i = 0; i < bola_hilang; i++) {
        printf("%d ", hasil[i]);
    }
    printf("\n");

    return 0;
}