#include <stdio.h>

int main (){
    //Kamus 
    int n, m, i, j;
    printf("Masukan jumlah baris = ");
    scanf("%d", &n);
    printf("Masukan jumlah kolom = ");
    scanf("%d", &m);
    int T [n] [m];
    

    //Algoritma
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf("Masukan index %d, %d = ", i, j);
            scanf("%d", & T [i] [j]);
        }
    }

    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            printf("%d ", T [i] [j]);
        }
        printf("\n");
    }
}