#include <stdio.h>

void SEQSearchXI(int T[], int N, int X){
    int i = 0;
    while (i < N && T[i] != X){
        i++;
    }
    if (i < N) {
        printf("Data %d found at index %d\n", X, i);
    } else {
        printf("Data %d not found\n", X);
    }
}

int main(){
    int N = 8;
    int T[8] = {1,8, 3, 5, -8, 12, 90, 35};
    int X = 90;

    SEQSearchXI(T, N, X);

    return 0;
}
