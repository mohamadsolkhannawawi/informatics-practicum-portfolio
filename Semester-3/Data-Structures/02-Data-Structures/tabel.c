#ifndef  tabel_c
#define  tabel_c
#include "tabel.h"
#include <stdio.h>
#include "boolean.h"
#include <stdbool.h>
// Deskripsi : program tabel.c
// NIM/Nama : 24060123120020/Mohamad Solkhan Nawawi
// Tanggal : Jumat, 6 September 2024

/*KONSTRUKTOR*/				 
/*procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
void createTable (Tabel *T) {
    //Kamus
    int i;
    //Algoritma
    (*T).size = 0;
    for (i = 1; i <= 10; i++) {
        (*T).wadah[i] = -999;
    }
}

/*SELEKTOR*/
/*function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize (Tabel T){
    return T.size;
}

/*PREDIKAT*/
/*function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable (Tabel T){
    return getSize(T) == 0;
}

/*function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
/*function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable (Tabel T){
    // Algoritma
    if (getSize(T) == 10) {
        return true;
    } else {
        return false;
    }
}

/*OPERASI PENCARIAN*/
/*function searchX (T:Tabel, X: integer) -> integer
	{mencari elemen bernilai X dalam T.wadah dan mengembalikan index terkecilnya}*/
int searchX (Tabel T, int X){
    //Kamus
    int i, idx;
    //Algoritma
    if (!isEmptyTable(T)) {
        i = 1;
        idx = -999;
        while (i <= getSize(T) && idx == -999){
            if (T.wadah[i] == X) {
                idx = i;
            }
            i++;
        }
    }
    return idx;
}

/*function countX (T:Tabel, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam T.wadah}*/
int countX (Tabel T, int X){
    //Kamus
    int i, count;
    //Algoritma
    count = 0;
    if (!isEmptyTable(T)) {
        count = 0;
        for (i = 1; i <= getSize(T); i++) {
            if (T.wadah[i] == X) {
                count++;
            }
        }
    }
    return count;
}

/*function countEmpty( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi } */
int countEmpty (Tabel T){
    // Kamus 
    int i, count;
    // Algoritma
    count = 0;
    if (!isEmptyTable(T)) {
        count = 0;
        for (i = 1; i <= 10; i++) {
            if (T.wadah[i] == -999) {
                count++;
            }
        }
    }
    return count;
}

/*MUTATOR*/
/*procedure addXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X}*/
void addXTable (Tabel *T, int X){
    //Kamus

    //Algoritma
    if (!isFullTable(*T)) {
        (*T).size = (*T).size + 1;
        (*T).wadah[getSize(*T)] = X;
    }
}

/*procedure delXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa}*/
void delXTable (Tabel *T, int X){
    //Kamus
    int i, idx;
    //Algoritma
    if (!isEmptyTable(*T)) {
        idx = searchX(*T, X);
        if (idx != -999) {
            (*T).wadah[idx] = -999;
            if (idx < getSize(*T)) {
                for (i = idx; i < getSize(*T); i++) {
                    (*T).wadah[i] = (*T).wadah[i+1];
                } 
                (*T).wadah[getSize(*T)] = -999;
            }
            (*T).size = (*T).size - 1;
        }
    }
}

/*procedure delAllXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable (Tabel *T, int X){
    //Kamus
    int i, idx;
    //Algoritma
    if (!isEmptyTable(*T)) {
        idx = searchX(*T, X);
        while (idx != -999) {
            (*T).wadah[idx] = -999;
            if (idx < getSize(*T)) {
                for (i = idx; i < getSize(*T); i++) {
                    (*T).wadah[i] = (*T).wadah[i+1];
                }
                (*T).wadah[getSize(*T)] = -999;
            }
            (*T).size = (*T).size - 1;
            idx = searchX(*T, X);
        }
    }
}

/*OPERASI BACA/TULIS*/
/*procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable (Tabel T){
    //Kamus
    int i;
    //Algoritma
    for (i = 1; i <= 10; i++) {
        printf("%d ", T.wadah[i]);
    }
}

/*procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable (Tabel T){
    //Kamus
    int i;
    //Algoritma
    if (!isEmptyTable(T)) {
        for (i = 1; i <= getSize(T); i++) {
            printf("%d ", T.wadah[i]);
        }
    } else {
        printf("Tabel kosong");
    }
}

/*procedure populate1 ( input/output T:Tabel, input N: integer )
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate1 (Tabel *T, int N){
    //Kamus
    int i, X;
    //Algoritma
    if (N <= countEmpty(*T)) {
        for (i = 1; i <= N; i++) {
            scanf("%d ", &X);
            if (X > 0) {
                addXTable(T, X);
            }
        }
    } else {
        printf("inputan N melebihi batas maksimal tabel\n");
    }
}

/*procedure populate2 ( input/output T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: T.wadah terisi beberapa elemen positif}
	{Proses: mengisi elemen T.wadah berulang, bila angka 
	dari keyboard <=0 maka berhenti, tidak diproses}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate2 (Tabel *T){
    //Kamus
    int X;
    boolean check;
    //Algoritma
    if (!isFullTable(*T)) {
        check = true;
        while (check == true && !isFullTable(*T)) {
            printf("Masukan nilai : ");
            scanf("%d ", &X);
            if (X <= 0) {
                check = false;
            } else {
                addXTable(T, X);
            }
        }
    }
}

/*OPERASI STATISTIK*/
/*function SumEl ( T:Tabel ) -> integer 
	{mengembalikan jumlah semua elemen pengisi T } */
int SumEl (Tabel T){
    //Kamus
    int i, sum;
    //Algoritma
    sum = 0;
    if (!isEmptyTable(T)) {
        for (i = 1; i <= getSize(T); i++) {
            sum += T.wadah[i];
        }
    }
    return sum;
}

/*function AverageEl ( T:Tabel ) -> real 
	{mengembalikan nilai rata-rata elemen pengisi T } */
float AverageEl (Tabel T){
    //Kamus
    float sum; 
    //Algoritma
    if (!isEmptyTable(T)) {
        sum = SumEl(T);
        return (float) sum / getSize(T);
    } else {
        return 0;
    }
    return sum;
}

/*function getMaxEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terbesar } */
int getMaxEl (Tabel T){
    //Kamus
    int i, max;
    //Algoritma
    max = -999;
    if (!isEmptyTable(T)) {
        max = T.wadah[1];
        for (i = 2; i <= getSize(T); i++) {
            if (T.wadah[i] > max) {
                max = T.wadah[i];
            }
        }
    }
    return max;
}

/*function getMinEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terkecil } */
int getMinEl (Tabel T){
    //Kamus
    int i, min;
    //Algoritma
    min = -999;
    if (!isEmptyTable(T)) {
        min = T.wadah[1];
        for (i = 2; i <= getSize(T); i++) {
            if (min > T.wadah[i]) {
                min = T.wadah[i];
            }
        }
    }
    return min;
}

/*function Modus ( T:Tabel ) -> integer 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus (Tabel T){
    //Kamus
    int i, countMax, modus;
    //Algoritma
    modus = -999;
    countMax = 0;
    if (!isEmptyTable(T)) {
        modus = T.wadah[1];
        countMax = countX(T, T.wadah[1]);
        for (i = 2; i <= getSize(T); i++) {
            if (countMax < countX(T, T.wadah[i])) {
                countMax = countX(T, T.wadah[i]);
                modus = T.wadah[i];
            }
        }
    }
    return modus;
}

/*OPERASI PENGURUTAN*/
/*procedure SortAsc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari nilai terkecil hingga nilai terbesar}
	{Proses: mengurutkan elemen dalam T.wadah dari nilai terkecil hingga nilai terbesar}*/
void sortAsc (Tabel *T){
    //Kamus
    int i, j, temp;
    //Algoritma
    if (!isEmptyTable(*T)) {
        for (i = 1; i <= getSize(*T); i++) {
            for (j = i+1; j <= getSize(*T); j++) {
                if ((*T).wadah[i] > (*T).wadah[j]) {
                    temp = (*T).wadah[i];
                    (*T).wadah[i] = (*T).wadah[j];
                    (*T).wadah[j] = temp;
                }
            }
        }
    }
}

/*procedure SortDesc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari nilai terbesar hingga nilai terkecil}
	{Proses: mengurutkan elemen dalam T.wadah dari nilai terbesar hingga nilai terkecil}*/
void sortDesc (Tabel *T){
    //Kamus
    int i, j, temp;
    //Algoritma
    if (!isEmptyTable(*T)) {
        for (i = 1; i <= getSize(*T); i++) {
            for (j = i+1; j <= getSize(*T); j++) {
                if ((*T).wadah[i] < (*T).wadah[j]) {
                    temp = (*T).wadah[i];
                    (*T).wadah[i] = (*T).wadah[j];
                    (*T).wadah[j] = temp;
                }
            }
        }
    }
}

#endif