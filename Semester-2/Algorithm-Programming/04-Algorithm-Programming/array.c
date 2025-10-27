#include <stdio.h>

int main (){
    //Kamus 
    int N, i, sum;
    N = 5;
    int Elmt[N];

    //Algoritma
    sum = 0;
    for ( i = 0; i < 5; i++){
        Elmt[i] = i;
        sum = sum + Elmt[i];
        printf("%d", Elmt[i]);
    }
    printf("\nsum = %d\n", sum);
}