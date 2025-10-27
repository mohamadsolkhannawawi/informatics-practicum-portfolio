#include <stdio.h>
#include <stdlib.h>
#include <Tabel.h>

int main () {
    //Kamus
    TabInt T;
    //algoritma
    CreateEmpty(&T);
    if(IsIdxValid(T,2)){
        printf("Index Valid\n")
    } else {
        printf("Index tidak Valid");
    }
}
