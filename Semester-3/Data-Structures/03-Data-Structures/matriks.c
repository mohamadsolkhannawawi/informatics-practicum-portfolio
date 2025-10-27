/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060123120020/Mohamad Solkhan Nawawi*/
/* Tanggal   : Jumat, 13 September 2024*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>

/* include matriks.h & boolean.h */
#include "matriks.h"
#include "boolean.h"

/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M){
    // KAMUS LOKAL
    int i, j;
    // ALGORITMA
    for (i = 1; i <= 10; i++){
        for (j = 1; j <= 10; j++){
            (*M).cell[i][j] = -999;
        }
    }
    (*M).nbaris = 0;
    (*M).nkolom = 0;
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M){
    // ALGORITMA
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M){
    // ALGORITMA
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M){
    // ALGORITMA
    return (M.nbaris == 0 || M.nkolom == 0);
}
/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M) {
    // KAMUS LOKAL
    // ALGORITMA
    return (M.nbaris == 10 && M.nkolom == 10);
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col) {
    // KAMUS LOKAL
    int i, j;
    // ALGORITMA
    *row = -999; // inisialisasi row
    *col = -999; // inisialisasi col
    if (!isEmptyMatriks(M)) { // jika matriks tidak kosong
        i = 0;
        while (i < M.nbaris && *row == -999) { // loop baris dengan syarat row belum ditemukan
            j = 0;
            while (j < M.nkolom && *row == -999) { // loop kolom dengan syarat row belum ditemukan
                if (M.cell[i][j] == X) { // jika elemen ditemukan
                    *row = i; // simpan indeks baris
                    *col = j; // simpan indeks kolom
                }
                j++; // increment j
            }
            i++; // increment i
        }
    }
}


/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX (Matriks M, int X) {
    // KAMUS LOKAL
    int i, j, count;
    // ALGORITMA
    count = 0;
    if (!isEmptyMatriks(M)){
        for (i = 1; i <= 10; i++){
            for (j = 1; j <= 10; j++){
                if (M.cell[i][j] == X){
                    count++;
                }
            }
        }
    }
    return count;
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX (Matriks *M, int X, int row, int col){
    //Kamus Lokal
    // ALGORITMA
    if (!isFullMatriks(*M)){
        if (isEmptyMatriks(*M)){
            (*M).nbaris = 1;
            (*M).nkolom = 1;
            (*M).cell[1][1] = X;
        } else {
            if ((*M).cell[row][col] == -999){
                (*M).cell[row][col] = X;
                if (row > (*M).nbaris){
                    (*M).nbaris = row;
                }
                if (col > (*M).nkolom){
                    (*M).nkolom = col;
                }
            }
        }
    }
}

/* procedure editX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell pada baris ke-row dan kolom ke-col diubah dengan nilai X}
	{Proses: mengubah isi M.cell pada baris ke-row dan kolom ke-col dengan nilai X} */
void editX (Matriks *M, int X, int row, int col) {
    // KAMUS LOKAl
    // ALGORITMA
    if (!isEmptyMatriks(*M)){
        if (row <= (*M).nbaris && col <= (*M).nkolom){
            (*M).cell[row][col] = X;
        }
    }
}

/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX (Matriks *M, int X){
    //Kamus Lokal
    int i, j, row, col;
    boolean rowempty, colempty;
    //Algoritma
    if (!isEmptyMatriks(*M)) {
        searchX(*M, X, &row, &col);
        if (row != -999 && col != -999) {
            (*M).cell[row][col] = -999;
            //Pengecekan Kekosongan
            rowempty = true;
            for (j = 1; j <= getNKolom(*M); j++){
                if ((*M).cell[row][j] != -999){
                    rowempty = false;
                }
            }
            if (rowempty == true){
                if (row == getNBaris(*M)) {
                    (*M).nbaris--;
                }
            }
            colempty = true;
            for (i = 1; i <= getNBaris(*M); i++) {
                if ((*M).cell[i][col] != -999) {
                    colempty = false;
                }
            }
            if (colempty == true) {
                if (col == getNKolom(*M)) {
                    (*M).nkolom--;
                }
            }    
        }
    }
}


/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y) {
    // KAMUS LOKAL
    int i, j;
    // ALGORITMA
    if (x <= 10 && y <= 10){
        for (i = 1; i <= x; i++){
            for (j = 1; j <= y; j++){
                (*M).cell[i][j] = rand() % 100;
            }
        }
        (*M).nbaris = x;
        (*M).nkolom = y;
    }
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n) {
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    if (n <= 10){
        for (i = 1; i <= n; i++){
            (*M).cell[i][i] = 1;
        }
        (*M).nbaris = n;
        (*M).nkolom = n;
    }
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y) {
    // KAMUS LOKAL
    int i, j;
    // ALGORITMA
    if (x <= 10 && y <= 10){
        for (i = 1; i <= x; i++){
            for (j = 1; j <= y; j++){
                printf("Masukkan elemen baris ke-%d kolom ke-%d: ", i, j);
                scanf("%d", &(*M).cell[i][j]);
            }
        }
        (*M).nbaris = x;
        (*M).nkolom = y;
    }
}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M) {
    // KAMUS LOKAL
    int i, j;
    // ALGORITMA
    if (!isEmptyMatriks(M)){
        for (i = 1; i <= M.nbaris; i++){
            for (j = 1; j <= M.nkolom; j++){
                printf("%d ", M.cell[i][j]);
            }
            printf("\n");
        }
    }

}

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks (Matriks M) {
    // KAMUS LOKAL
    int i, j;
    // ALGORITMA
    if (!isEmptyMatriks(M)){
        for (i = 1; i <= M.nbaris; i++){
            for (j = 1; j <= M.nkolom; j++){
                if (M.cell[i][j] != -999){
                    printf("%d ", M.cell[i][j]);
                }
            }
            printf("\n");
        }
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2) {
    // KAMUS LOKAL
    Matriks M;
    int i, j;
    // ALGORITMA
    if (M1.nbaris == M2.nbaris && M1.nkolom == M2.nkolom){
        for (i = 1; i <= M1.nbaris; i++){
            for (j = 1; j <= M1.nkolom; j++){
                if (M1.cell[i][j] == -999 || M2.cell[i][j] == -999) {
                    M.cell[i][j] = -999;
                } else {
                    M.cell[i][j] = M1.cell[i][j] + M2.cell[i][j];
                }
            }   
        M.nbaris = M1.nbaris;
        M.nkolom = M1.nkolom;
        }
    }
    return M;
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2) {
    // KAMUS LOKAL
    Matriks M;
    int i, j;
    // ALGORITMA
    if (M1.nbaris == M2.nbaris && M1.nkolom == M2.nkolom){
        for (i = 1; i <= M1.nbaris; i++){
            for (j = 1; j <= M1.nkolom; j++){
                if (M1.cell[i][j] == -999 || M2.cell[i][j] == -999) {
                    M.cell[i][j] = -999;
                } else {
                    M.cell[i][j] = M1.cell[i][j] - M2.cell[i][j];
                }
            }
            M.nbaris = M1.nbaris;
            M.nkolom = M1.nkolom;
        }    
    }
    return M;
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2) {
    // KAMUS LOKAL
    Matriks M;
    int i, j, k;
    // ALGORITMA
    if (M1.nkolom == M2.nbaris){
        for (i = 1; i <= M1.nbaris; i++){
            for (j = 1; j <= M2.nkolom; j++){
                M.cell[i][j] = 0;
                for (k = 1; k <= M1.nkolom; k++){
                     if (M1.cell[i][k] == -999 || M2.cell[k][j] == -999) {
                        M.cell[i][j] = -999;  // Jika salah satu elemen adalah -999
                        break;  // Tidak perlu melanjutkan perkalian
                    }
                    M.cell[i][j] += M1.cell[i][k] * M2.cell[k][j];
                }
            }
        }
        M.nbaris = M1.nbaris;
        M.nkolom = M2.nkolom;
    }
    return M;
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x) {
    // KAMUS LOKAL
    Matriks M;
    int i, j;
    // ALGORITMA
    for (i = 1; i <= M1.nbaris; i++){
        for (j = 1; j <= M1.nkolom; j++){
            if (M1.cell[i][j] == -999) {
                M.cell[i][j] = -999;
            } else {  // Jika elemen adalah -999
            M.cell[i][j] = M1.cell[i][j] * x;
            }
        }
        M.nbaris = M1.nbaris;
        M.nkolom = M1.nkolom;
    }
    return M;
}
/* OPERASI STATISTIK*/
/* function getSumMatriks (M:Matriks) -> integer 
	{mengembalikan jumlah semua elemen pengisi M.cell} */
int getSumMatriks (Matriks M) {
    // KAMUS LOKAL
    int i, j, sum;
    // ALGORITMA
    sum = 0;
    if (!isEmptyMatriks(M)){
        for (i = 1; i <= M.nbaris; i++){
            for (j = 1; j <= M.nkolom; j++){
                if (M.cell[i][j] != -999){
                    sum += M.cell[i][j];
                }
            }
        }
    }
}

/* function getAveragematriks (M:Matriks) -> real 
	{mengembalikan nilai rata-rata elemen pengisi M.cell} */
float getAverageMatriks (Matriks M) {
    // KAMUS LOKAL
    int i, j, sum, count;
    // ALGORITMA
    sum = 0;
    count = 0;
    if (!isEmptyMatriks(M)){
        for (i = 1; i <= M.nbaris; i++){
            for (j = 1; j <= M.nkolom; j++){
                if (M.cell[i][j] != -999){
                    sum += M.cell[i][j];
                    count++;
                }
            }
        }
    }
    return (float) sum / count;
}

/* function getMaxMatriks (M:Matriks) -> integer
	{mengembalikan nilai elemen terbesar pengisi M.cell } */
int getMaxMatriks (Matriks M) {
    // KAMUS LOKAL
    int i, j, max;
    // ALGORITMA
    max = -999;
    if (!isEmptyMatriks(M)){
        for (i = 1; i <= M.nbaris; i++){
            for (j = 1; j <= M.nkolom; j++){
                if (M.cell[i][j] != -999 && M.cell[i][j] > max){
                    max = M.cell[i][j];
                }
            }
        }
    }
    return max;
}

/* function getMinMatriks (M:Matriks) -> integer
	{mengembalikan nilai elemen terkecil pengisi M.cell} */
int getMinMatriks (Matriks M) {
    // KAMUS LOKAL
    int i, j, min;
    // ALGORITMA
    min = 999;
    if (!isEmptyMatriks(M)){
        for (i = 1; i <= M.nbaris; i++){
            for (j = 1; j <= M.nkolom; j++){
                if (M.cell[i][j] != -999 && M.cell[i][j] < min){
                    min = M.cell[i][j];
                }
            }
        }
    }
    return min;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M) {
    // KAMUS LOKAL
    Matriks temp;
    int i, j;
    // ALGORITMA
    for (i = 1; i <= (*M).nbaris; i++){
        for (j = 1; j <= (*M).nkolom; j++){
            temp.cell[j][i] = (*M).cell[i][j];
        }
    }
    for (i = 1; i <= (*M).nbaris; i++){
        for (j = 1; j <= (*M).nkolom; j++){
            (*M).cell[i][j] = temp.cell[i][j];
        }
    }
}

/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M) {
    // KAMUS LOKAL
    Matriks temp;
    int i, j;
    // ALGORITMA
    for (i = 1; i <= M.nbaris; i++){
        for (j = 1; j <= M.nkolom; j++){
            temp.cell[j][i] = M.cell[i][j];
        }
    }
    temp.nbaris = M.nkolom;
    temp.nkolom = M.nbaris;
    return temp;
}