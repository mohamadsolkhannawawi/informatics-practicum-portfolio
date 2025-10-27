/*Nama file: mesinKar.h*/ 
/*Deskripsi: prototype mesin karakter*/ 
 
#ifndef MESINKAR_H 
#define MESINKAR_H 
 
#define False 0 
#define True 1 
 
#ifndef MARK 
#define MARK '.' 
#endif 
 
#ifndef ENTER 
#define ENTER 10 
#endif 
 
/*Prototype*/ 
void START(); 
/* I.S. sembarang */ 
/* F.S. CC adalah karakter pertama pita */ 
/*      Jika CC==MARK, EOP menyala(true) */ 
/*      Jika CC!=MARK, EOP padam(false) */ 
 
void ADV(); 
/* I.S. CC!=MARK */ 
/* F.S. CC adalah karakter berikutnya CC pada I.S */ 
/*      Jika CC==MARK, EOP menyala(true) */ 
 
int EOP(); 
/* mengirimkan true jika CC==MARK */ 
 
#endif // MESINKAR_H_INCLUDED