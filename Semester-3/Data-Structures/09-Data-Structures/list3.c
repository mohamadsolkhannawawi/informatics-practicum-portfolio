/* File : list3.c */
/* Deskripsi : File body ADT list berkait dengan representasi fisik pointer kait ganda */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal : Jumat, 15 November 2024*/

#include "list3.h"
#include <stdio.h>
#include <stdlib.h>

/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
    // Kamus Lokal
    address P;

    // ALgoritma
    P = (address) malloc(sizeof(Elm));
    if (P != NIL) {
        info(P) = E;
        next(P) = NIL;
        prev(P) = NIL;
        return P;
    } else {
        return NIL;
    }
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P) {
    // Kamus Lokal

    // Algoritma
    if (*P != NIL) {
        next(*P) = NIL;
        prev(*P) = NIL;
    }
    P = NIL;
}

/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List3 *L) {
    // Kamus Lokal

    // Algoritma
    First(*L) = NIL;
}

/* function IsEmptyList(L:List3) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List3 L) {
    // Kamus Lokal

    // Algoritma
    return (First(L) == NIL);
}

/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List3 L) {
    // Kamus Lokal
    address P;

    // Algoritma
    P = First(L);
    if (IsEmptyList(L)) {
        printf("List kosong\n");
    } else {
        while (P != NIL) {
            printf(" %c \t",info(P));
            P = next(P);
        }
        printf("\n");
    }
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L) {
    // Kamus Lokal
    address P;
    int count;

    // Algoritma
    if (IsEmptyList(L)) {
        return 0;
    } else {
        P = next(First(L));
        count = 1;
        do {
            P = next(P);
            count++;
        } while (P != NIL);
    }
    return count;
}

/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V ) {
    // Kamus Lokal
    address P;

    // Algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
        } else  {
            next(P) = First(*L);
            prev(First(*L)) = P;
            First(*L) = P;
        }
    }
}

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V ) {
    // Kamus Lokal
    address P, Last;

    // Algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
        } else {
            Last = First(*L);
            while (next(Last) != NIL) {
                Last = next(Last);
            }
            next(Last) = P;
            prev(P) = Last;
        }
    }
}

/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V) {
    // Kamus Lokal
    address P; 

    // Algoritma
    *V = '#';
    if (!IsEmptyList(*L)) {
        P = First(*L);
        *V = info(P);
        if (next(P) == NIL) {
            First(*L) = NIL;
        } else {
            First(*L) = next(P);
            prev(First(*L)) = NIL;
            Dealokasi(&P);
        }
    }
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V) {
    // Kamus Lokal
    address P, Last;

    // Algoritma
    *V = '#';
    if (!IsEmptyList(*L)) {
        if (NbElm(*L) == 1) {
            P = First(*L);
            *V = info(P);
            Dealokasi(&P);
            First(*L) = NIL;
        } else {
            Last = First(*L);
            while (next(next(Last)) != NIL) {
                Last = next(Last);
            }
            P = next(Last);
            *V = info(P);
            next(Last) = NIL;
            Dealokasi(&P);
        }
    }
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L terdefinisi }
{ F.S. List mungkin menjadi kosong, atau berkurang 1 elemen. }
{ Proses: Elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteX(List3 *L, infotype X) {
    // Kamus Lokal
    address P;

    // Algoritma
    if (First(*L) != NIL) { 
        P = First(*L);
        while (P != NIL && info(P) != X) {
            P = next(P);
        }
        if (P != NIL) {
            if (P == First(*L)) {
                First(*L) = next(P);
                if (First(*L) != NIL) {
                    prev(First(*L)) = NIL;
                } else {
                    P = NIL; 
                }
            }
            else if (next(P) == NIL) {
                P = prev(P);
                next(P) = NIL;
            }
            else {
                next(prev(P)) = next(P);
                prev(next(P)) = prev(P);
            }
            Dealokasi(&P);
        }
    }
}


/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X. }
{ Proses : Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A) {
    // Kamus Lokal
    address P;

    // Algoritma
    P = First(L);
    while (P != NIL && info(P) != X) {
        P = next(P);
    }
    *A = P;
}

/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.}
{ Proses : Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List3 *L, infotype X, infotype Y) {
    // Kamus Lokal
    address P;

    // Algoritma
    P = First(*L);
    while (P != NIL) {
        if (info(P) == X) {
            info(P) = Y;
        }
        P = next(P);
    }
}

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L) {
    // Kamus Lokal 
    address P, Q, R;

    // Algoritma
    P = First(*L);
    Q = NIL;
    while (P != NIL) {
        R = next(P);
        next(P) = Q;
        prev(P) = R;
        Q = P;
        P = R;
    }
    First(*L) = Q;
}

/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V) {
    // Kamus Lokal
    address P,Q;

    // Algoritma
    P = Alokasi(V);
    if (P != NIL) {
        SearchX(*L, X, &Q);
        if (Q != NIL) {
            next(P) = next(Q);
            prev(P) = Q;
            next(Q) = P;
            if (next(P) != NIL) {
                prev(next(P)) = P;
            }
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V) {
    // Kamus Lokal
    address P,Q;

    // Algoritma
    P = Alokasi(V);
    if (P != NIL) {
        SearchX(*L, X, &Q);
        if (Q != NIL) {
            prev(P) = prev(Q);
            next(P) = Q;
            prev(Q) = P;
            if (prev(P) != NIL) {
                next(prev(P)) = P;
            } else {
                First(*L) = P;
            }
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V) {
    // Kamus Lokal
    address P,Q;

    // Algoritma
    SearchX(*L, X, &Q);
    if (Q != NIL && next(Q) != NIL) {
        P = next(Q);
        *V = info(P);
        next(Q) = next(P);
        if (next(P) != NIL) {
            prev(next(P)) = Q;
        }
        Dealokasi(&P);
    }
}

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V) {
    // Kamus Lokal
    address P,Q;

    // Algoritma
    SearchX(*L, X, &Q);
    if (Q != NIL && prev(Q) != NIL) {
        P = prev(Q);
        *V = info(P);
        prev(Q) = prev(P);
        if (prev(P) != NIL) {
            next(prev(P)) = Q;
        } else {
            First(*L) = Q;
        }
        Dealokasi(&P);
    }
}

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X) {
    // Kamus Lokal
    address P;
    int count;

    // Algoritma
    P = First(L);
    count = 0;
    while (P != NIL) {
        if (info(P) == X) {
            count++;
        }
        P = next(P);
    }
    return count;
}

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X) {
    // Kamus Lokal
    int count;

    // Algoritma
    count = CountX(L, X);
    return (float) count / NbElm(L);
}

/*function MaxMember(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List3 L) {
    // Kamus Lokal
    address P;
    int max, count;

    // Algoritma
    P = First(L);
    max = 0;
    while (P != NIL) {
        count = CountX(L, info(P));
        if (count > max) {
            max = count;
        }
        P = next(P);
    }
    return max;
}

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L) {
    // Kamus Lokal
    address P,Q;
    int max, count;

    // Algoritma
    P = First(L);
    Q = NIL;
    max = 0;
    while (P != NIL) {
        count = CountX(L, info(P));
        if (count > max) {
            max = count;
            Q = P;
        }
        P = next(P);
    }
    return info(Q);
}

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L) {
    // Kamus Lokal
    address P;
    int count;

    // Algoritma
    P = First(L);
    count = 0;
    if (IsEmptyList(L)) {
        return 0;
    } else {
        while (P != NIL) {
            if (info(P) == 'A' || info(P) == 'a' || info(P) == 'I' || info(P) == 'i' || info(P) == 'U' || info(P) == 'u' || info(P) == 'E' || info(P) == 'e' || info(P) == 'O' || info(P) == 'o') {
                count++;
            }
            P = next(P);
        }
    } 
    return count;
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L) {
    // Kamus Lokal
    address P;
    int count;

    // Algoritma
    P = First(L);
    count = 0;
    while (P != NIL) {
        if (info(P) == 'N' || info(P) == 'n') {
            if (next(P) != NIL && (info(next(P)) == 'G' || info(next(P)) == 'g')) {
                count++;
            }
        }
        P = next(P);
    }
    return count;
}

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. - }
{ Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List3 L, infotype X) {
    // Kamus Lokal
    address P;
    int pos;

    // Algoritma
    P = First(L);
    pos = 0;
    while (P != NIL) {
        pos++;
        if (info(P) == X) {
            printf(" %d\t", pos);
        }
        P = next(P);
    }
}

/*Procedure DeleteAllX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. List mungkin menjadi kosong. }
{ Proses: Semua elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteAllX(List3 *L, infotype X) {
    // Kamus Lokal
    address P,Q;

    // Algoritma
    P = First(*L);
    if (P != NIL) {
        while (P != NIL) {
            if (info(P) == X) {
                if (P == First(*L)) {
                    First(*L) = next(P);
                } else {
                    next(Q) = next(P);
                    prev(next(P)) = Q;
                }
            } else {
                Q = P;
            }
            P = next(P);
        }
        Dealokasi(&P);
    }
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List3, input L2:List3, output L:List3)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List3 L1, List3 L2, List3 *L) {
    // Kamus Lokal
    address P,Q;

    // Algoritma
    CreateList(L);
    P = First(L1);
    while (P != NIL) {
        InsertVLast(L, info(P));
        P = next(P);
    }
    Q = First(L2);
    while (Q != NIL) {
        InsertVLast(L, info(Q));
        Q = next(Q);
    }
}

/*Procedure SplitList(input L:List3, output L1:List3, output L2:List3)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List3 L, List3 *L1, List3 *L2) {
    // Kamus Lokal
    address P;
    int i, n;

    // Algoritma
    CreateList(L1);
    CreateList(L2);
    n = NbElm(L);
    P = First(L);
    for (i = 1; i <= n; i++) {
        if (i <= n / 2) {
            InsertVLast(L1, info(P));
        } else  {
            InsertVLast(L2, info(P));
        }
        P = next(P);
    }
}

/*Procedure CopyList(input L1:List3, output L2:List3)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List3 L1, List3 *L2) {
    // Kamus Lokal
    address P;

    // Algoritma
    CreateList(L2);
    P = First(L1);
    while (P != NIL) {
        InsertVLast(L2, info(P));
        P = next(P);
    }
}