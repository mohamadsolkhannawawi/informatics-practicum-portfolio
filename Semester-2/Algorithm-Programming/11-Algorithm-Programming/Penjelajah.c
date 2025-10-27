#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int n,k;
    int i;
    int j;
    int start;
    int end;
    scanf("%d %d", &n, &k);
    
    int array[n];
    for (i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    
    int mark[n];
    for (i = 0; i < n; i++){
        mark[i] = 0;
    }
    
    for (i = 0; i < n; i++){
        if (array[i] == 1){
            start = i - k;
            if (start < 0){
                start = 0;
            }
            end = i + k;
            if (end >= n){
                end = n - 1;
            }
            for ( j = start; j <= end; j++){
                mark[j] = 1;
            }
        }
    }
    
    int unmark_count = 0;
    for (i = 0; i < n; i++){
        if (mark[i] == 0){
            unmark_count++;
        }
    }
    printf("%d\n", unmark_count);
    return 0;
}