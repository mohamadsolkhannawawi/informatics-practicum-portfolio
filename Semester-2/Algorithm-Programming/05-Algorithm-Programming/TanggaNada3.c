#include <stdio.h>

int main() {
    // Input jumlah elemen, nilai a, dan nilai b
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    // Array untuk menyimpan elemen T dan keadaannya
    int T[n];
    int state[n];

    // Meminta input untuk setiap elemen T dan menentukan keadaannya
    for (int i = 0; i < n; i++) {
        scanf("%d", &T[i]);
        if (T[i] < a)
            state[i] = 1; // 1 untuk "Alto"
        else if (T[i] > b)
            state[i] = 3; // 3 untuk "Sopran"
        else
            state[i] = 2; // 2 untuk "Mezzo-sopran"
    }
    
    //Algoritma
    // Mencetak urutan elemen T dengan menampilkan jenis suaranya
    for (int i = 0; i < n; i++) {
        if (T[i] < a) {
            if (state[i] != state[i - 1])
                printf("\nAlto: ");
            printf("%d ", T[i]);
        } else if (T[i] > b) {
            if (state[i] != state[i - 1])
                printf("\nSopran: ");
            printf("%d ", T[i]);
        } else {
            if (state[i] != state[i - 1])
                printf("\nMezzo-sopran: ");
            printf("%d ", T[i]);
        }
    }

    return 0;
}
