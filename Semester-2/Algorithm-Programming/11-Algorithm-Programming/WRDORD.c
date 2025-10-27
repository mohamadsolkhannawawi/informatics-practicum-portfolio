#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i;
    int j;
    int panjang_array;
    int temp;
    int index;
    scanf("%d", &panjang_array);
    
    int array[panjang_array];
    for (i = 0; i < panjang_array; i++){
        scanf("%d", &array[i]);
    }
    
    for (i = 0; i < panjang_array - 1; i++){
        for (j = 0; j < panjang_array - i - 1; j++){
            if (array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    int ambil[panjang_array / 2 +1];
    index = 0;
    for (i = 1; i < panjang_array; i +=2){
        ambil[index++] = array[i];
    }
    
    for (i = 0; i < index - 1; i++){
        for (j = 0; j < index - i - 1; j++){
            if (ambil[j] < ambil[j+1]){
                temp = ambil[j];
                ambil[j] = ambil[j+1];
                ambil[j+1] = temp;
            }
        }
    }    
    index = 0;
    for (i = 1; i < panjang_array; i += 2){
        array[i] = ambil[index++];
    }
    
    for (i = 0; i < panjang_array; i++){
        printf("%d ", array[i]);
    }
    
    return 0;
}
