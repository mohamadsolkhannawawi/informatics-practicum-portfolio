/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060123120020/Mohamad Solkhan Nawawi*/
/* Tanggal   : Jumat, 20 September 2024*/
/***********************************/

#include <stdio.h>
/* include tstack+boolean */
#include "tstack.h"
#include "boolean.h"

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T) {
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    for (i = 1; i <= 10; i++) {
        (*T).wadah[i] = '#';
    }
    (*T).top = 0;
}

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T) {
    //KAMUS LOKAL
    //ALGORITMA
    return (top(T) == 0);
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T) {
    //KAMUS LOKAL
    //ALGORITMA
    return (top(T) == 10);
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E) {
    //KAMUS LOKAL
    //ALGORITMA
    if (!isFullStack(*T)) {
        (*T).top++;
        (*T).wadah[(*T).top] = E;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X) {
    //KAMUS LOKAL
    //ALGORITMA
    if (!isEmptyStack(*T)) {
        *X = (*T).wadah[(*T).top];
        (*T).wadah[(*T).top] = '#';
        (*T).top--;
    }
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T) {
    //KAMUS LOKAL
    int i;
    //ALGORITMA
    for (i = 1; i <= 10; i++) {
        printf("%c", T.wadah[i]);
        if (i < 10) {
            printf("; ");
        }
    }
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T) {
    //KAMUS LOKAL
    int i;
    //ALGORITMA
    for (i = 1; i <= T.top; i++) {
        if (T.wadah[i] != '#') {
            printf("%c", T.wadah[i]);
            if (i < T.top) {
                printf("; ");
            }
        }
    }
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N) {
    //KAMUS LOKAL
    int i;
    char E;
    //ALGORITMA
    if (N > 0 && N <= 10) {
        for (i = 1; i <= N; i++) {
            printf("Masukkan elemen ke-%d: ", i);
            scanf(" %c", &E);
            push(T, E);
        }
    } else {
        printf("Masukan N melebihi jumlah maksimum stack.");
    }
}

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) bila belum penuh atau menjadi kosong bila stack penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (Tstack *T, char E){
    //KAMUS LOKAL
    int i;
    char buang;
    //ALGORITMA
    if (!isFullStack(*T)) {
        push(T, E);
    } else {
        for (i = 1; i <= 10; i++) {
            pop(T, &buang);
        }
    }
}

/*procedure pushZuma ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau berkurang 1 elemen bila E bernilai sama dengan top }
	{Proses: menumpuk top atau menghapus elemen top }
    {contoh: T=['A','B','C'], E='C' menjadi T=['A','B']}*/
void pushZuma (Tstack *T, char E) {
    //KAMUS LOKAL
    char X;
    //ALGORITMA
    if (isEmptyStack(*T)) {
        push(T, E);
    } else {
        if (E == infotop(*T)) {
                pop(T, &X);
        } else {
            if (!isFullStack(*T)) {
                push(T, E);
            }
        }

    }
}


