/* File : List2.c */
/* Deskripsi : File body ADT list berkait circular dengan representasi fisik pointer */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal : Jum'at, 8 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
    //kamus lokal
	address P;
	//algoritma
	P = (address) malloc (sizeof(Elm));
	if (P != NIL) { //ruang memori tersedia
		info(P) = E;
		next(P) = NIL;
	}
	return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  secara circular
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P) {
    // Kamus Lokal

    // Algoritma
    free(*P);
    (*P) = NULL;
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List2 *L) {
    // Kamus Lokal

    // Algoritma
    First(*L) = NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> Boolean 
   {mengembalikan True bila list L kosong} */
Boolean IsEmptyList (List2 L) {
    // Kamus Lokal

    // Algoritma
    return (First(L) == NIL);
}

/* function IsOneElm(L:List2) --> Boolean 
   {mengembalikan true bila list L hanya punya satu elemen} */
Boolean IsOneElm (List2 L) {
    // Kamus Lokal
    address P;
    int count;

    // Algoritma
    P = First(L);
    return (P != NIL && next(P) == First(L));
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L) {
    // Kamus Lokal
    address P, Q;

    // Algoritma
    P = First(L);
    if (P != NIL) {
        Q = P;
        do {
            printf("%c ", info(P));
            P = next(P);
        } while (P != Q);
    }
    
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L) {
    // Kamus Lokal
    address P;
    int count;

    // Algoritma
    P = First(L);
    if (P == NIL) {
        return 0;
    } else {
        count = 1;
        P = next(P);
        while (P != First(L)) {
            count++;
            P = next(P);
        }
    }
    return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V ) {
    // Kamus Lokal
    address P, Q;

    // Algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
            next(P) = P;
        } else {
            Q = First(*L);
            while (next(Q) != First(*L)) {
                Q = next(Q);
            }
            next(Q) = P;
            next(P) = First(*L);
            First(*L) = P;
        }
    }
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V ) {
    // Kamus Lokal
    address P, Q;

    // Algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
            next(P) = P;
        } else {
            Q = First(*L);
            while (next(Q) != First(*L)) {
                Q = next(Q);
            }
            next(Q) = P;
            next(P) = First(*L);
        }
    }
    P = NIL;
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V) {
    // Kamus Lokal
    address P, Q;

    // Algoritma
    *V = '#';
    if (!IsEmptyList(*L)) {
        P = First(*L);
        *V = info(P);
        if (IsOneElm(*L)) {
            Dealokasi(&P);
            First(*L) = NIL;
        } else {
            Q = First(*L);
            while (next(Q) != First(*L)) {
                Q = next(Q);
            }
            First(*L) = next(P);
            next(Q) = First(*L);
            Dealokasi(&P);
        }
    }
}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V) {
    // Kamus Lokal
    address P, Q;

    // Algoritma
    *V = '#';
    if (!IsEmptyList(*L)) {
        P = First(*L);
        if (IsOneElm(*L)) {
            *V = info(P);
            Dealokasi(&P);
            First(*L) = NIL;
        } else {
            Q = First(*L);
            while (next(next(Q)) != First(*L)) {
                Q = next(Q);
            }
            P = next(Q);
            *V = info(P);
            next(Q) = First(*L);
            Dealokasi(&P);
        }
    }
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X) {
    // Kamus Lokal
    address P, Q;

    // Algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        if (info(P) == X) {
            DeleteVFirst(L, &X);
        } else {
            Q = First(*L);
            while (next(Q) != First(*L) && info(next(Q)) != X) {
                Q = next(Q);
            }
            if (next(Q) != First(*L)) {
                P = next(Q);
                next(Q) = next(P);
                Dealokasi(&P);
            }
        }
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A) {
    // Kamus Lokal
    address P;

    // Algoritma
    P = First(L);
    *A = NIL;
    if (P != NIL) {
        do {
            if (info(P) == X) {
                *A = P;
            }
            P = next(P);
        } while (P != First(L) && *A == NIL);
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y) {
    // Kamus Lokal
    address P;

    // Algoritma
    P = First(*L);
    if (P != NIL) {
        do {
            if (info(P) == X) {
                info(P) = Y;
            }
            P = next(P);
        } while (P != First(*L));
    }
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, 
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L) {
    //Kamus Lokal
	address prev, current, nextN, last;

	//Algoritma
    if (IsEmptyList(*L)) {
        printf("List Kosong\n");
    } else {
        prev = NIL;
        current = First(*L);
        last = First(*L);
        do
        {
            nextN = next(current);
            next(current) = prev;
            prev = current;
            current = nextN;
        } while (current != First(*L));
        next(last) = prev;
        First(*L) = prev;
    }
}

/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X) {
    // Kamus Lokal
    address P;
    int count;

    // Algoritma
    P = First(L);
    count = 0;
    if (P != NIL) {
        do {
            if (info(P) == X) {
                count++;
            }
            P = next(P);
        } while (P != First(L));
    }
    return count;
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X) {
    // Kamus Lokal
    int count;

    // Algoritma
    count = CountX(L, X);
    return (float) count / NbElm(L);
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L) {
    // Kamus Lokal
    address P;
    int count;

    // Algoritma
    P = First(L);
    count = 0;
    if (P != NIL) {
        do {
            if (info(P) == 'A' || info(P) == 'a' || info(P) == 'I' || info(P) == 'i' || info(P) == 'U' || info(P) == 'u' ||  info(P) == 'E'  || info(P) == 'e' || info(P) == 'O' || info(P) == 'o') {
                count++;
            }
            P = next(P);
        } while (P != First(L));
    }
    return count;
}

/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L) {
    // Kamus Lokal
    address P;
    int count;

    // Algoritma
    P = First(L);
    count = 0;
    if (P != NIL) {
        do {
            if (info(P) == 'N' || info(P) == 'n') {
                if (info(next(P)) == 'G' || info(next(P)) == 'g') {
                    count++;
                }
            }
            P = next(P);
        } while (P != First(L));
    }
    return count;
}

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V) {
    // Kamus Lokal
    address P, AX;
    Boolean found;
    // Algoritma
    if (IsEmptyList(*L)) {
        printf("List Kosong\n");
    } else {
        P = Alokasi(V);
        AX = First(*L);
        found = False;
        if(P != NIL) {
            do {
                if (info(AX) == X) { //Elemen X ditemukan
                    found = True;
                    next(P) = next(AX);
                    next(AX) = P;
                } else { //Elemen X tidak ditemukan
                    AX = next(AX);
                }    
            } while (AX != First(*L) && found == False);
            if (found == False) { //Elemen X tidak ditemukan di dalam list
                printf("Elemen %c tidak ditemukan di dalam list\n", X);
                Dealokasi (&P);
            }
        } else { //Gagal Alokasi
            printf("Gagal Alokasi\n");
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V) {
    // Kamus lokal
    address P, BX, IX, Last;
    Boolean found;
    // Algoritma
    if (IsEmptyList(*L)) {
        printf("List Kosong\n");
    } else {
        P = Alokasi(V);
        BX = NIL;
        IX = First(*L);
        found = False;
        if(P != NIL) {
            do {
                if (info(IX) == X) { //Elemen X ditemukan
                    found = True;
                    if (BX == NIL) { //Elemen X ada di pertama
                        Last = First(*L);
                        while (next(Last) != First(*L)) {
                            Last = next(Last);
                        } // {Endwhile : next(Last) = First(*L)}
                        next(P) = First(*L);
                        next(Last) = P;
                        First(*L) = P;
                    } else {
                        next(BX) = P;
                        next(P) = IX;   
                    }  
                } else { //Elemen X tidak ditemukan
                    BX = IX;
                    IX = next(IX);
                }
            } while (IX != First(*L) && found == False);
            if (found == False) { //Elemen X tidak ditemukan di dalam list
                printf("Elemen %c tidak ditemukan di dalam list\n", X);
                Dealokasi (&P);
            }
        } else { //Gagal Alokasi
            printf("Gagal Alokasi\n");
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V) {
    // Kamus lokal
    address AX, Last, Delete;
    Boolean found;
    //algoritma
    if (!IsEmptyList(*L)) {
        AX = First(*L);
        found = False;
        do {
            if (info(AX) == X) { //Elemen X ditemukan

                found = True;
                if (next(AX) == AX) { // List hanya terdiri dari 1 elemen
                    (*V) = info(AX);
                    Dealokasi (&AX);
                    First(*L) = NIL;
                } else { //List terdiri dari lebih dari 1 elemen
                    Delete = next(AX);
                    (*V) = info(Delete);
                    if (Delete == First(*L)) { //Elemen yang dihapus adalah elemen pertama
                        First(*L) = next(Delete);
                    }
                    next(AX) = next(Delete);
                    Dealokasi (&Delete);
                }
            } else { //Elemen X tidak ditemukan
                AX = next(AX);
            }
        } while (AX != First(*L) && found == False);
        if (found == False) { //Elemen X tidak ditemukan di dalam list
            (*V) = '#';
            printf("Elemen %c tidak ditemukan di dalam list\n", X);
        }
    } else { //Kasus List Kosong
        (*V) = '#';
        printf("List Kosong\n");
    }
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V) {
    // Kamus lokal
    address IX, Prev, BeforePrev,Last;
    Boolean found;
    // Algoritma
    if (IsEmptyList(*L)) {
        printf("List Kosong\n");
    } else {
        IX = First(*L);
        found = False;
        do {
            if (info(IX) == X) { //Elemen X ditemukan
                found = True;
                if (next(IX) == IX) { // List hanya terdiri dari 1 elemen
                    (*V) = info(IX);
                    Dealokasi (&IX);
                    First(*L) = NIL;
                } else { //List terdiri dari lebih dari 1 elemen
                    Prev = First(*L);
                    while (next(Prev) != IX) {
                        Prev = next(Prev);
                    } // {Endwhile : next(Prev) = IX}
                    (*V) = info(Prev);    
                    if (Prev == First(*L)) { //Elemen pertana yang dihapus
                        Last = First(*L);
                        while (next(Last) != First(*L)) {
                            Last = next(Last);
                        } // {Endwhile : next(Last) = First(*L)}
                        First(*L) = next(Prev);
                        next(Last) = First(*L);
                    } else { //Elemen yang dihapus bukan elemen pertama
                        BeforePrev = First(*L);
                        while (next(BeforePrev) != Prev) {
                            BeforePrev = next(BeforePrev);
                        } // {Endwhile : next(BeforePrev) = Prev}
                        next(BeforePrev) = IX;
                    }   
                    Dealokasi(&Prev);
                }
            } else { //Elemen X tidak ditemukan
                IX = next(IX);
            }
        } while (IX != First(*L) && found == False);
        if (found == False) { //Elemen X tidak ditemukan di dalam list
            (*V) = '#';
            printf("Elemen %c tidak ditemukan di dalam list\n", X);
        }
    }
}

/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X) {
    // Kamus lokal
    address P, temp;
    // Algoritma
    if (IsEmptyList(*L)) {
        printf("List Kosong\n");
    } else {
        P = First(*L);
        do {
            temp = next(P);
            if (info(P) == X) { //Elemen X ditemukan
                DeleteX(L, X);
            }
            P = temp;
        } while (!IsEmptyList(*L) && next(P) != First(*L));
    }   
}

/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X) {
    // Kamus lokal
    address P;
    int i;
    Boolean found;
    // Algoritma
    
    if (IsEmptyList(L)) {
        printf("List Kosong\n");
    } else {
        P = First(L);
        i = 1;
        found = False;
        do {
            if (info(P) == X) {
                printf("%d ", i);
                found = True;
            }
            i++;
            P = next(P);
        } while (P != First(L));
        if (found == False) {
            printf("0");
        }
    }
}

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L) {
    // Kamus Lokal
    address P;
    int max, count;

    // Algoritma
    P = First(L);
    max = 0;
    if (P != NIL) {
        do {
            count = CountX(L, info(P));
            if (count > max) {
                max = count;
            }
            P = next(P);
        } while (P != First(L));
    }
    return max;
}

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L) {
    // Kamus Lokal
    address P;
    int max, count;
    infotype modus;

    // Algoritma
    P = First(L);
    max = 0;
    if (P != NIL) {
        do {
            count = CountX(L, info(P));
            if (count > max) {
                max = count;
                modus = info(P);
            }
            P = next(P);
        } while (P != First(L));
    }
    return modus;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L) {
    // Kamus Lokal
    address P, Q, R;

    // Algoritma
    CreateList(L);
    P = First(L1);
    if (P != NIL) {
        do {
            InsertVLast(L, info(P));
            P = next(P);
        } while (P != First(L1));
    }
    Q = First(L2);
    if (Q != NIL) {
        do {
            InsertVLast(L, info(Q));
            Q = next(Q);
        } while (Q != First(L2));
    }
}

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2) {
    // Kamus Lokal
    address P, Q;
    int i, n;

    // Algoritma
    CreateList(L1);
    CreateList(L2);
    P = First(L);
    n = NbElm(L);
    if (P != NIL) {
        i = 1;
        do {
            if (i <= n / 2) {
                InsertVLast(L1, info(P));
            } else {
                InsertVLast(L2, info(P));
            }
            P = next(P);
            i++;
        } while (P != First(L));
    }
}

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2) {
    // Kamus Lokal
    address P;

    // Algoritma
    CreateList(L2);
    P = First(L1);
    if (P != NIL) {
        do {
            InsertVLast(L2, info(P));
            P = next(P);
        } while (P != First(L1));
    }
}
