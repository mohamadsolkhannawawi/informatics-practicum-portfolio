#include <stdio.h>

int main (){
    //Kamus 
    int N, i, sum;
    scanf("%d", &N);
    int Elmt[N];

    //Algoritma
    sum = 0;
    for ( i = 0; i < N; i++){
        scanf("%d", &Elmt[i]);
        Elmt[i] = i;
        sum = sum + Elmt[i];
    }
    printf("\nsum = %d", sum);
}