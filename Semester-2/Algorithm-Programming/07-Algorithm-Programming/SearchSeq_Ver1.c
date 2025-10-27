#include <stdio.h>

void SEQSearchXI(int T[], int N, int X){
    int i = 1;
    while (i < N and T[i] != X){
        i++;
    }
    if (i < N and T[i] = X) {
        printf("%d\n", i);
    } else {
        printf("%d\n", X);
    }
}

int main(){
    int N = 8;
    int T[8] = {1,8, 3, 5, -8, 12, 90, 35};
    int X = 90;

    SEQSearchXI(T, N, X);

    return 0;
