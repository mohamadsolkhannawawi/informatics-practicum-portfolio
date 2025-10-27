/* File : pohon3.c */
/* Deskripsi : File Body ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal : Jum'at, 06 Desember 2024*/

#include "pohon3.h"

/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* function Alokasi( E: infotype)-> bintree */
/* {menghasilkan alokasi memori pohon dengan info=E, left=NIL, right=NIL  } */
bintree3 Alokasi3(infotype E) {
    bintree3 P = (bintree3)malloc(sizeof(node3));
    if (P != NIL) {
        parent(P) = NIL;
        akar(P) = E;
        visited(P) = False;
        left(P) = NIL;
        right(P) = NIL;
    }
    return P;
}

/* procedure Dealokasi (input/output P:bintree) */
/* {I.S. P terdefinisi
    F.S. P dikembalikan ke sistem
    Proses: Melakukan pengembalian bintree P} */
void Dealokasi3(bintree3 *P) {
    free(*P);
    *P = NIL;
}

/********** PEMBUATAN POHON BARU ***********/
/* function Tree(A:bintree3, X:infotype, V:Boolean, kiri:bintree3, kanan:bintree3)-> bintree3
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree3 Tree3(bintree3 A, infotype X, Boolean V, bintree3 kiri, bintree3 kanan) {
    // Kamus Lokal
    bintree3 P;
    
    // Algoritma
    P = Alokasi3(X);
    if (P != NIL) {
        parent(P) = A;
        visited(P) = V;
        left(P) = kiri;
        right(P) = kanan;
    }
    return P;
}

// procedure printParent( input P:bintree3) 
// {I.S. P terdefinisi; F.S. -}
// {proses mencetak parent dari setiap node pada P}
void printParent(bintree3 P) {
    if (P != NIL) {
        if (parent(P) != NIL) {
            printf("Node %c memiliki parent %c\n", akar(P), akar(parent(P)));
        } else {
            printf("Node %c adalah akar\n", akar(P));
        }
        printParent(left(P));
        printParent(right(P));
    }
}

/*procedure resetVisited( input/output P : bintree3 )
{I.S: P terdefinisi; F.S: -}
{proses mengubah status visited semua node di P menjadi false}*/
void resetVisited (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    if (P != NIL) {
        visited(P) = False;
        resetVisited(left(P));
        resetVisited(right(P));
    }
}

/* function IsEmptyTree(P:bintree3) --> Boolean 
   {mengembalikan true bila bintree3 L kosong} */
Boolean IsEmptyTree (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    return (P == NIL);
}

/* function IsDaun (P:bintree3)-> Boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
Boolean IsDaun (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    if (P != NIL) {
        return (left(P) == NIL && right(P) == NIL);
    } else {
        return False;
    }
}

/* function IsBiner (P:bintree3)-> Boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
Boolean IsBiner (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    if (P != NIL) {
        return (left(P) != NIL && right(P) != NIL);
    } else {
        return False;
    }
}

/* function IsUnerLeft(P:bintree3)-> Boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
Boolean IsUnerLeft (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    if (P != NIL) {
        return (left(P) != NIL && right(P) == NIL);
    } else {
        return False;
    }
}

/* function IsUnerRight(P:bintree3)-> Boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
Boolean IsUnerRight (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    if (P != NIL) {
        return (left(P) == NIL && right(P) != NIL);
    } else {
        return False;
    }
}

/* procedure printDFS( input P:bintree3)
{mencetak node-node P dari elemen terkiri mendalam baru ke kanan} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void printDFS (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    if (P != NIL) {
        printf("%c(",akar(P));
        printDFS(left(P));
        printf(",");
        printDFS(right(P));
        printf(")");
    } else {
        printf("( )");
    }
}

/* function SearchNode(P:bintree3, X:infotype)-> bintree3
{Menghasilkan bintree3 yang mempunyai nilai X sebagai nodenya}*/
bintree3 SearchNode(bintree3 P, infotype X){
    //Kamus Lokal
    bintree3 found;

    //Algoritma
    if (IsEmptyTree(P)) {
        return NIL;
    } else {
        if (akar(P) == X) {
            return P;
        } else {
            found = SearchNode(left(P), X);
            if (found != NIL) {
                return found;
            } else {
                return SearchNode(right(P), X);
            }
        }
    }
}

// /*procedure printPathX( input P:bintree3, input X:infotype)
// {menampilkan jalur dari akar P hingga node bernilai X }*/
void printPathX (bintree3 P, infotype X){
    //Kamus Lokal
    bintree3 target, current;
    List1 L;

    //Algoritma
    target = SearchNode(P, X);
    CreateList(&L);
    if (target != NIL) {
        current = target;
        while (current != NIL) {
            visited(current) = True;
            InsertVFirst(&L, akar(current));
            current = parent(current);
        } 
        PrintList(L);
    } else {
        printf("Node %c tidak terdapat dalam pohon", X);
    }
}

/*procedure printPathDaunX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga daun bernilai X }*/
void printPathDaunX (bintree3 P, infotype X) {
    // Kamus Lokal
    bintree3 target, current;
    List1 L;

    // Algoritma
    target = SearchNode(P, X);
    CreateList(&L);
    if (target != NIL) {
        if (IsDaun(target)) {
            current = target;
            while (current != NIL) {
                visited(current) = True;
                InsertVFirst(&L, akar(current));
                current = parent(current);
            }
            PrintList(L);
        } else {
            printf("Node %c bukan merupakan daun ", X);
        }
    } else {
        printf("Node %c tidak terdapat dalam pohon", X);
    }
}

/*procedure printAllPaths( input P:bintree3)
{menampilkan semua jalur yang mungkin dari akar P hingga setiap daun}*/
void printAllPaths (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    if (P != NIL) {
        if (IsDaun(P)) {
            printPathX(P,akar(P));
            printf("\n");
        } else {
            printAllPaths(left(P));
            printAllPaths(right(P));
        }
    }
}

/* function NbElmTree(P:bintree3) --> integer
{ menghitung banyaknya elemen bintree3 P} */
int NbElmTree (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    if (P == NIL) {
        return 0;
    } else {
        return 1 + NbElmTree(left(P)) + NbElmTree(right(P));
    }
}

/* function NbDaun(P:bintree3)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    if (P == NIL) {
        return 0;
    } else if (IsDaun(P)) {
        return 1;
    } else {
        return NbDaun(left(P)) + NbDaun(right(P));
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int Max2 (int a, int b) {
    // Kamus Lokal

    // Algoritma
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

/* function Tinggi(P:bintree3)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    if (P == NIL) {
        return -1;
    } else {
        return 1 + Max2(Tinggi(left(P)),Tinggi(right(P)));
    }
}

/* function Level(P:bintree3)-> integer
{menghitung tingkat/generasi node pohon P, level akar=1 }*/
int Level (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    if (IsEmptyTree(P)) {
        return 0;
    } else {
        if (IsDaun(P)) {
            return 1;
        } else {
            return 1 + Max2(Level(left(P)), Level(right(P)));
        }
    }
}

/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT (bintree3 P, int T) {
    // Kamus Lokal

    // Algoritma
    if (P == NIL || T <= 0) {
        return 0;
    } else if (T == 1) {
        return 1;
    } else {
        return CountLevelT(left(P),T-1) + CountLevelT(right(P),T-1);
    }
}

/*procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel (bintree3 P, int N) {
    // Kamus Lokal

    // Algoritma
    if (P != NIL) {
        if (N >= 1) {
            if (N == 1) {
                printf("%c ",akar(P));
            } else {
                PrintLevel(left(P),N-1);
                PrintLevel(right(P),N-1);
            }
        } else {
            printf("N lebih kecil dari 1\n");
        }
    }
}

/* procedure PrintBFS( input P:bintree3)
{mencetak node-node P dari generasi paling terkecil ke terbesar}*/
/*contoh: A B C D */
void PrintBFS (bintree3 P) {
    // Kamus Lokal
    int i;
    // Algoritma
    for (i = 1; i <= Tinggi(P)+1; i++) {
        PrintLevel(P,i);
    }
}

/*procedure Pconcat( input/output Asli:List1, input Tambahan:List1) */
/*{I.S:- ; F.S: list Asli berubah karena disambung list Tambahan}*/
/*{menyambung list Tambahan ke belakang list Asli}*/
void Pconcat (List1 *Asli, List1 Tambahan){
    // Kamus Lokal
    address Last;

    // Algoritma
    if (IsEmptyList(*Asli)) {
        First(*Asli) = First(Tambahan);
    } else {
        Last = First(*Asli);
        while (next(Last) != NIL) {
            Last = next(Last);
        } 
        next(Last) = First(Tambahan);
    }
}

/*function fconcat( Asli:List1, Tambahan:List1) -> List1 */
/*{membentuk list Baru hasil penyambungan list Tambahan ke belakang list Asli}*/
/*{periksa dampaknya, list Asli tidak boleh berubah }*/
List1 Fconcat (List1 Asli, List1 Tambahan){
    // Kamus Lokal
    address P;
    List1 Concat;

    // Algoritma
    CreateList(&Concat);
    if (!IsEmptyList(Asli)) {
        P = First(Asli);
        while (P != NIL) {
            InsertVLast(&Concat, info(P));
            P = next(P);
        } 
    }
    if (!IsEmptyList(Tambahan)) {
        P = First(Tambahan);
        while (P != NIL) {
            InsertVLast(&Concat, info(P));
            P = next(P);
        } 
    }
    return Concat;
}

/*function linearPrefix(P:bintree3) -> List1
{menghasilkan list node dari P terurut prefix akar,kiri,kanan}*/
List1 LinearPrefix (bintree3 P){
    // Kamus Lokal
    List1 L;

    // Algoritma
    CreateList(&L);
    if (!IsEmptyTree(P)) {
        InsertVLast(&L, akar(P));
        Pconcat(&L, LinearPrefix(left(P)));
        Pconcat(&L, LinearPrefix(right(P)));
    }
    return L;
}

/*function linearPosfix(P:bintree3) -> List1
{menghasilkan list node dari P terurut posfix kiri,kanan,akar}*/
List1 LinearPosfix (bintree3 P){
    // Kamus lokal
    List1 L;
    // Algoritma
    CreateList(&L);
    if (!IsEmptyTree(P)) {
        Pconcat(&L, LinearPosfix(left(P)));
        Pconcat(&L, LinearPosfix(right(P)));
        InsertVLast(&L, akar(P));
    }
    return L;
}

/*function linearInfix(P:bintree3) -> List1
{menghasilkan list node dari P terurut infix kiri,akar,kanan}*/
List1 LinearInfix (bintree3 P){
    // Kamus Lokal
    List1 L;

    // Algoritma
    CreateList(&L);
    if (!IsEmptyTree(P)) {
        Pconcat(&L, LinearInfix(left(P)));
        InsertVLast(&L, akar(P));
        Pconcat(&L, LinearInfix(right(P)));
    }
    return L;
}

/*function linearBreadthFS(P:bintree3) -> List1
{menghasilkan list node dari P terurut level/tingkat}*/
List1 LinearBreadthFS (bintree3 P){
    //Kamus Lokal
    List1 L, K;
    infotype value;
    bintree3 current;

    // Algoritma
    CreateList(&L);
    CreateList(&K);
    if (!IsEmptyTree(P)) {
        InsertVLast(&K, akar(P));
        while (!IsEmptyList(K)) {
            DeleteVFirst(&K, &value);
            InsertVLast(&L, value);
            current = SearchNode(P, value);
            if (current != NIL) {
                if (!IsEmptyTree(left(current))) {
                    InsertVLast(&K, akar(left(current)));
                }
                if (!IsEmptyTree(right(current))) {
                    InsertVLast(&K, akar(right(current)));
                }
            }
        } 
    }
    return L;
}
