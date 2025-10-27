/* File : pohon1.c */
/* Deskripsi : File body ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal : Jumat, 22 November 2024*/

#include "pohon1.h"
#include <stdio.h>
#include <stdlib.h>

/* function Alokasi( E: infotype)-> bintree */
/* {menghasilkan alokasi memori pohon dengan info=E, left=NIL, right=NIL  } */
bintree Alokasi(infotype E) {
    // Kamus Lokal
    bintree P;

    // Algoritma
    P = (bintree) malloc(sizeof(node));
    if (P != NIL) {
        info(P) = E;
        left(P) = NIL;
        right(P) = NIL;
        return P;
    }
}

/* procedure Dealokasi (input/output P:bintree) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian bintree P} */
void Dealokasi (bintree *P) {
    // Kamus Lokal

    // Algoritma
    if (*P != NIL) {
        left(*P) = NIL;
        right(*P) = NIL;
    }
    *P = NIL;
}

/* function Tree(Akar:infotype, Left:BinTree, Right:BinTree)-> BinTree
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree Tree (infotype akar, bintree left, bintree right) {
    // Kamus Lokal
    bintree P;

    // ALgoritma
    P = Alokasi(akar);
    if (P != NIL) {
        left(P) = left;
        right(P) = right;
    }
    return P;
}

/****** SELEKTOR *****/
/*function GetAkar (P : BinTree) -> infotype
{ Mengirimkan nilai Akar pohon biner P }*/
infotype GetAkar(bintree P) {
    // Kamus Lokal

    // Algoritma
    return info(P);
}

/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P) {
    // Kamus Lokal

    // Algoritma
    return left(P);
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P) {
    // Kamus Lokal

    // Algoritma
    return right(P);
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean 
   {mengembalikan true bila bintree L kosong} */
boolean IsEmptyTree (bintree P) {
    // Kamus Lokal

    // Algoritma
    return (P == NIL);
}

/* function IsDaun (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P) {
    // Kamus Lokal

    // Algoritma
    if (!IsEmptyTree(P)) {
        return (IsEmptyTree(left(P)) && IsEmptyTree(right(P)));
    } else {
        return False;
    }
}

/* function IsBiner (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P) {
    // Kamus Lokal

    // Algoritma
    if (!IsEmptyTree(P)) {
        return (!IsEmptyTree(left(P)) && !IsEmptyTree(right(P)));
    } else {
        return False;
    }
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P) {
    // Kamus Lokal

    // Algoritma
    if (!IsEmptyTree(P)) {
        return (!IsEmptyTree(left(P)) && IsEmptyTree(right(P)));
    } else {
        return False;
    }
}

/* function IsUnerRight(P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P) {
    // Kamus Lokal

    // Algoritma
    if (!IsEmptyTree(P)) {
        return (IsEmptyTree(left(P)) && !IsEmptyTree(right(P)));
    } else {
        return False;
    }
}

/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree P) {
    // Kamus Lokal

    // Algoritma
    if (!IsEmptyTree(P)) {
        printf("%c", info(P));
        printf("(");
        if (!IsEmptyTree(left(P))) {
            PrintPrefix(left(P));
        } else {
            printf("( )");
        }

        printf(",");

        if (!IsEmptyTree(right(P))) {
            PrintPrefix(right(P));
        } else {
            printf("( )");
        }
        printf(")");
    }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P) {
    // Kamus Lokal

    // Algoritma
    if (IsEmptyTree(P)) {
        return 0;
    } else {
        return 1 + NbElm(left(P)) + NbElm(right(P));
    }
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P) {
    // Kamus Lokal

    // Algoritma
    if (P != NIL) {
        if (IsDaun(P)) {
            return 1 + NbDaun(left(P)) + NbDaun(right(P));
        } else {
            return NbDaun(left(P)) + NbDaun(right(P));
        }
    } else {
        return 0;
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b) {
    // Kamus Lokal

    // Algoritma
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen yaitu 0 }*/
int Tinggi(bintree P) {
    // Kamus Lokal

    // ALgoritma
    if (P != NIL) {
        if (NbElm(P) == 1) {
            return 0;
        } else {
            return 1 + max2(Tinggi(left(P)), Tinggi(right(P)));
        }
    }
}

/*function SearchX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchX(bintree P, infotype X) {
    // Kamus Lokal

    // Algoritma
    if (IsEmptyTree(P)) {
        return False;
    } else {
        if (info(P) == X) {
            return True;
        } else {
            return (SearchX(left(P), X)) || (SearchX(right(P), X));
        }
    }
}

/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(bintree *P, infotype X, infotype Y) {
    // Kamus Lokal

    // Algoritma
    if (!IsEmptyTree(*P)) {
        if (info(*P) == X) {
            info(*P) = Y;
        } else if (SearchX(left(*P), X)) {
            UpdateX(&left(*P), X, Y);
        } else {
            UpdateX(&right(*P), X, Y);
        }
    }
}

/*function CountX(P:BinTree, X:infotype) -> integer 
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X) {
    // Kamus Lokal

    // Algoritma
    if (IsEmptyTree(P)) {
        return 0;
    } else {
        if (info(P) == X) {
            return 1 + CountX(left(P), X) + CountX(right(P), X);
        } else {
            return CountX(left(P), X) + CountX(right(P), X);
        }
    }
}

/*function IsSkewLeft (P : BinTree)-> boolean 
{ Mengirim true jika P adalah pohon condong kiri } */
// Asumsi : Pohon kosong adalah pohon condong 
boolean IsSkewLeft (bintree P) {
    // Kamus Lokal

    // Algoritma
    if (IsEmptyTree(P)) {
        return True;
    } else {
        if (IsEmptyTree(right(P))) {
            return IsSkewLeft(left(P));
        } else {
            return False;
        }
    }
}

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
// Asumsi : Pohon kosong adalah pohon condong kanan
boolean IsSkewRight (bintree P) {
    // Kamus Lokal

    // Algoritma
    if (IsEmptyTree(P)) {
        return True;
    } else {
        if (IsEmptyTree(left(P))) {
            return IsSkewRight(right(P));
        } else {
            return False;
        }
    }
}

/* procedure PrintPrefixRingkas(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(( ),D),C)*/
void PrintPrefixRingkas(bintree P) {
    //Kamus lokal

    //Algoritma
    if (P != NIL) {
        printf("%c", akar(P));
        if (!IsEmptyTree(left(P)) || !IsEmptyTree(right(P))) {
            printf("(");
            if (!IsEmptyTree(left(P))) {
                PrintPrefixRingkas(left(P));
            } else {
                printf("( )");
            }

            printf(",");

            if (!IsEmptyTree(right(P))) {
                PrintPrefixRingkas(right(P));
            } else {
                printf("( )");
            }
            printf(")");
        }
    }
}

/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X) {
    // Kamus Lokal

    // Algoritma
    if (P != NIL) {
        if (info(P) == X) {
            return 1;
        } else {
            if (SearchX(left(P), X)) {
                return 1 + LevelX(left(P), X);
            } else {
                return 1 + LevelX(right(P), X);
            }
        }
    }
}

/*function CountLevelT(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT(bintree P, int T) {
    // Kamus Lokal

    // Algoritma
    if (IsEmptyTree(P)) {
        return 0;
    } else {
        if (T == 1) {
            return 1;
        } else {
            return CountLevelT(left(P), T-1) + CountLevelT(right(P), T-1);
        }
    }
}

/*function GetDaunTerkiri(bintree P)-> infotype 
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P) {
    // Kamus Lokal

    // Algoritma
    if (IsEmptyTree(P)) {
        return '#';
    } else {
        if (IsDaun(P)) {
            return info(P);
        } else {
            if (!IsEmptyTree(left(P))) {
                return GetDaunTerkiri(left(P));
            } else {
                return GetDaunTerkiri(right(P));
            }
        }
    }
}

/*function GetDaunTerkanan(bintree P)-> infotype 
{mengembalikan nilai info daun paling kanan, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkanan(bintree P) {
    // Kamus Lokal

    // Algoritma
    if (IsEmptyTree(P)) {
        return '#';
    } else {
        if (IsDaun(P)) {
            return info(P);
        } else {
            if (!IsEmptyTree(right(P))) {
                return GetDaunTerkanan(right(P));
            } else {
                return GetDaunTerkanan(left(P));
            }
        }
    }
}

/*function FrekuensiX(L:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree L }*/
float FrekuensiX(bintree P, infotype X) {
    // Kamus Lokal

    // Algoritma
    return (float) CountX(P, X) / NbElm(P);
}

/*function CountVocal(L:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree L}*/
int CountVocal(bintree L) {
    // Kamus Lokal

    // Algoritma
    if (IsEmptyTree(L)) {
        return 0;
    } else {
        if (info(L) == 'A' || info(L) == 'a' || info(L) == 'I' || info(L) == 'i' || info(L) == 'U' || info(L) == 'u' || info(L) == 'E' || info(L) == 'e' || info(L) == 'O' || info(L) == 'o') {
            return 1 + CountVocal(left(L)) + CountVocal(right(L));
        } else {
            return CountVocal(left(L)) + CountVocal(right(L));
        }
    }
}

/*function Modus(L:bintree) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam bintree L}*/
char Modus(bintree P){
    // Kamus lokal
    char modus, modusKiri, modusKanan;
    int count, countKiri, countKanan;

    // Algoritma
    modus = '#';
    count = 0;
    if (!IsEmptyTree(P)) { 
        modus = GetAkar(P);
        count = CountX(P, GetAkar(P));
        if (!IsEmptyTree(left(P))) {
            modusKiri = Modus(left(P));
            countKiri = CountX(P, modusKiri);
            if (countKiri > count) {
                modus = modusKiri;
                count = countKiri;
            }
        }

        if (!IsEmptyTree(right(P))) {
            modusKanan = Modus(right(P));
            countKanan = CountX(P, modusKanan);
            if (countKanan > count) {
                modus = modusKanan;
                count = countKanan;
            }
        }
    }
    return modus;
}
