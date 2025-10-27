/* File : pohon2.c */
/* Deskripsi : File Body ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal : Jumat, 29 November 2024*/

#include <stdio.h>
#include <stdlib.h>
#include "pohon2.h"

/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H ) {
    // Kamus Lokal
    int i;

    // ALgoritma
    if (!IsEmptyTree(P)) {
        for (i = 1; i <= H; i++) {
            printf("    ");
        }
        printf(" %c\n", info(P));
        if ( left(P) != NIL) {
            PrintTreeInden(left(P), H+1);
        }
        if (right(P) != NIL) {
            PrintTreeInden(right(P), H+1);
        }
    }
}

/* procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
void PrintLevel(bintree P, int N) {
    // Kamus Lokal
    
    // Algoritma
    if (!IsEmptyTree(P)) {
        if (N == 1) {
            printf(" %c", info(P));
        } else {
            PrintLevel(left(P), N-1);
            PrintLevel(right(P), N-1);
        }
    }
}

/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n) {
// Kamus Lokal
    bintree P;
    infotype X;
    int leftNodes, rightNodes;

    // Algoritma
    if (n == 0) {
        return NIL; // Basis rekursi
    } else {
        // Baca nilai simpul dari keyboard
        printf("Masukkan nilai node: ");
        scanf(" %c", &X);

        // Buat pohon seimbang
        P = Tree(X, BuildBalanceTree(n - 1 - (n / 2)), BuildBalanceTree(n / 2));
        return P;
    }
}

/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P) {
    // Kamus Lokal
    int leftHeight, rightHeight;

    // Algoritma
    if (IsEmptyTree(P)) {
        return True;
    } else {
        leftHeight = Tinggi(left(P));
        rightHeight = Tinggi(right(P));
        return (abs(leftHeight - rightHeight) <= 1) && IsBalanceTree(left(P)) && IsBalanceTree(right(P));
    }
}

/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree P, infotype X) {
    // Kamus Lokal

    // Algoritma
    if (IsEmptyTree(P)) {
        P = Alokasi(X);
    } else {
        if (IsEmptyTree(left(P))) {
            left(P) = Alokasi(X);
        } else {
            AddDaunTerkiri(left(P), X);
        }
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree P, infotype X, infotype Y, boolean Kiri) {
    // Kamus Lokal

    // Algoritma
    if (!IsEmptyTree(P)) {
        if (IsDaun(P)) {
            if (info(P) == X) {
                if (Kiri) {
                    left(P) = Alokasi(Y);
                } else {
                    right(P) = Alokasi(Y);
                }
            }
        } else {
            if (left(P) != NIL) {
                AddDaun(left(P), X, Y, Kiri);
            } else {
                AddDaun(right(P), X, Y, Kiri);
            }
        }
    }
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X) {
    if (!SearchX(*P, X)) { 
        if (*P == NIL) {
            *P = Alokasi(X);
        } else {
            if (left(*P) == NIL) {
                InsertX(&left(*P), X);
            } else if (right(*P) == NIL) {
                InsertX(&right(*P), X);
            } else {
                InsertX(&left(*P), X);
            }
        }
    }
}


/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype *X) {
    if (!IsEmptyTree(*P)) {
        if (IsDaun(*P)) {
            *X = info(*P); 
            Dealokasi(P);     
        } else {
            if (left(*P) != NIL) {
                DelDaunTerkiri(&left(*P), X);
            } else {
                DelDaunTerkiri(&right(*P), X);
            }
        }
    }
}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X) {
    // Kamus Lokal

    // Algoritma
    if (!IsEmptyTree(*P)) {
        if (IsDaun(*P)) {
            if (info(*P) == X) {
                Dealokasi(P);
            }
        } else {
            DelDaun(&left(*P), X);
            DelDaun(&right(*P), X);
        }
    }
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
// Asumsi, semua nilai X yang ada dihapus
void DeleteX(bintree *P, infotype X) {
    // Kamus Lokal

    // Algoritma
    if (!IsEmptyTree(*P)) {
        if (info(*P) == X) {
            Dealokasi(P);
        } else {
            DeleteX(&left(*P), X);
            DeleteX(&right(*P), X);
        }
    }
}

/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y) {
    // Kamus Lokal

    // Algoritma
    if (!IsEmptyTree(*P)) {
        if (info(*P) == X) {
            info(*P) = Y;
            if (left(*P) != NIL) {
                UpdateAllX(&left(*P), X, Y);
            } else {
                UpdateAllX(&right(*P), X, Y);
            }
        } else {
            UpdateAllX(&left(*P), X, Y);
            UpdateAllX(&right(*P), X, Y);
        }
    }
}


/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
// Asumsi jika kosong, kembalikan '#'
char maxTree(bintree P) {
    // Kamus Lokal
    char maxLeft, maxRight, max;

    // Algoritma
    if (IsEmptyTree(P)) {
        return '#'; 
    } else {
        max = info(P); 
        if (!IsEmptyTree(left(P))) {
            maxLeft = maxTree(left(P)); 
            if (maxLeft > max) {
                max = maxLeft; 
            }
        }
        if (!IsEmptyTree(right(P))) {
            maxRight = maxTree(right(P)); 
            if (maxRight > max) {
                max = maxRight; 
            }
        }
        return max; 
    }
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
// Asumsi jika kosong, kembalikan '#'
char minTree(bintree P) {
    // Kamus Lokal
    char minLeft, minRight, min;

    // Algoritma
    if (IsEmptyTree(P)) {
        return '#';
    } else {
        min = info(P);
        if (!IsEmptyTree(left(P))) {
            minLeft = minTree(left(P));
            if (minLeft < min) {
                min = minLeft;
            }
        }
        if (!IsEmptyTree(right(P))) {
            minRight = minTree(right(P));
            if (minRight < min) {
                min = minRight;
            }
        }
        return min;
    }
}

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X) {
    // Kamus Lokal

    // ALgoritma
    if (IsEmptyTree(P)) {
        return False;
    } else {
        if (info(P) == X) {
            return True;
        } else {
            if (info(P) > X) {
                return BSearch(left(P), X);
            } else {
                return BSearch(right(P), X);
            }
        }
    }
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X) {
    // Kamus Lokal

    // Algoritma
    if (IsEmptyTree(P)) {
        return Alokasi(X);
    } else {
        if (!SearchX(P, X)) {
            if (X < info(P)) {
                left(P) = InsSearch(left(P), X);
            } else {
                right(P) = InsSearch(right(P), X);
            }
        } else {
            printf("Elemen %c sudah ada di pohon!\n", X);
        }
        return P; 
    }
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X) {
    // Kamus Lokal
    bintree temp;
    bintree successorParent;
    infotype successor;

    // Algoritma
    if (!IsEmptyTree(*P)) {
        if (info(*P) == X) {
            if (IsDaun(left(*P)) && IsDaun(right(*P))) {
                Dealokasi(P);
                *P = NIL;
            } else if (IsDaun(left(*P))) {
                temp = *P;
                *P = right(*P);
                Dealokasi(&temp);
            } else if (IsDaun(right(*P))) {
                temp = *P;
                *P = left(*P);
                Dealokasi(&temp);
            } else {
                successorParent = *P;
                temp = right(*P);
                while (left(temp) != NIL) {
                    successorParent = temp;
                    temp = left(temp);
                }
                info(*P) = info(temp);
                if (successorParent == *P) {
                    right(*P) = right(temp);
                } else {
                    left(successorParent) = right(temp);
                }
                left(*P) = left(temp);
                Dealokasi(&temp);
            }
        } else if (info(*P) > X) {
            DelBtree(&left(*P), X);
        } else {
            DelBtree(&right(*P), X);
        }
    }
}







