#include <stdio.h>

void InsertionSORT(int T[], int N) {
        //Kamus Lokal
        int i, Pass, Temp;

        //Algoritma
        for (Pass = 1; Pass < N; Pass++) {
                Temp = T[Pass];
                i = Pass - 1;
                while (Temp < T[i] && i > 0) {
                        T[i + 1] = T[i];
                        i = i - 1;
                }
                if  (Temp >= T[i]) {
                        T[i + 1] = Temp;
                } else {
                        T[i + 1] = T[i];
                        T[i] = Temp;
                }
        }
}

int main () {
        int T[10] = {5, 3, 7, 2, 8, 4, 1, 0, 9, 6};
        int N= 7;

        InsertionSORT(T, N);

        for (int i = 0; i < N; i++) {
                printf("%d ", T[i]);
        }
        printf("\n");
        return 0;
}