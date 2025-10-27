/*Nama file: driverMesinKar.c*/ 
/*Deskripsi: driver mesin karakter*/ 
#include <assert.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include "mesinKar.h" 
/* definisi states secara global*/ 
char CC; 
int main(){ 
/*kamus*/ 
/*algoritma*/ 
printf("Awal pita..........\n"); 
START(); 
while (!EOP()) 
{ 
printf("%c",CC); 
ADV(); 
} 
printf("\n............Akhir pita, bye\n"); 
return 0; 
} 