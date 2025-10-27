#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void BubbleSort(int T[], int N) {
    int Pass, Temp, K;
    for (Pass = 0; Pass < N - 1; Pass++) {
        for (K = 0; K < N - Pass - 1; K++) {
            if (T[K] > T[K + 1]) {
                Temp = T[K];
                T[K] = T[K + 1];
                T[K + 1] = Temp;
            }
        }
    }
}


int main() {
    int i;
    int k;
    int selisih;
    int panjang_array1;
    int panjang_array2;
    scanf("%d %d", &panjang_array1, &panjang_array2);
    
    int array1[panjang_array1];
    for (i = 0; i < panjang_array1; i++){
        scanf("%d", &array1[i]);
    }
    
    int array2[panjang_array2];
    for (i = 0; i < panjang_array2; i++){
        scanf("%d", &array2[i]);
    }
    
    int count_array1[999] = {0};
    for (i = 0; i < panjang_array1; i++) {
        count_array1[array1[i]]++;
    }

    int count_array2[999] = {0};
    for (i = 0; i < panjang_array2; i++) {
        count_array2[array2[i]]++;
    }
    
    int lost[panjang_array1];
    k = 0;
    for (i = 0; i < 999; i++) {
        selisih = count_array1[i] - count_array2[i];
        for (int j = 0; j < selisih; j++) {
            lost[k++] = i;
        }
    }
    
    BubbleSort(lost, k);
    
    for (i = 0; i < k; i++) {
        printf("%d ", lost[i]);
    }
    printf("\n");

    return 0; 
}
