/* File : main.c */
/* Deskripsi : Main driver ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal : Jumat, 29 November 2024*/

#include <stdio.h>
#include <stdlib.h>
#include "pohon2.h"
#include "pohon2.c"

int main() {
    // Kamus Lokal
    bintree P, B, Z, UpdateSemua, PohonMaxMin, PohonBinary;
    int n;
    infotype X;

    // Algoritma
    printf("======== PrintTreeInden ========\n");
    B = Tree('A',Tree('B', NIL, NIL), Tree('C', NIL, NIL));
    PrintTreeInden(B, 0);
    printf("\n\n");
    printf("======== PrintLevel ========\n");
    printf("Tinggi Pohon : %d\n", Tinggi(B));
    printf("Level 1 : ");
    PrintLevel(B, 1);
    printf("\n");
    printf("Level 2 : ");
    PrintLevel(B, 2);
    printf("\n\n");
    printf("======== BuildBalanceTree ========\n");
    printf("Membuat pohon seimbang P dengan 5 node\n");
    P = BuildBalanceTree(5);
    PrintTreeInden(P,0);
    printf("\n");
    printf("======== IsBalanceTree ========\n");
    printf("Apakah P seimbang? %s\n", IsBalanceTree(P) ? "True" : "False");
    printf("\n");
    printf("======== AddDaunTerkiri ========\n");
    printf("Membuat pohon B dengan simpul 'A' sebagai root\n");
    B = Tree('A',Tree('B', NIL, NIL), Tree('C', NIL, NIL));
    PrintTreeInden(B, 0);
    printf("Menambahkan daun terkiri 'Z' pada B\n");
    AddDaunTerkiri(B, 'Z');
    PrintTreeInden(B, 0);
    printf("\n");
    printf("======== AddDaun ========\n");
    printf("Pohon B sebelum penambahan\n");
    PrintTreeInden(B, 0);
    printf("Menambahkan daun 'X' dengan anak kiri 'Z' pada pohon B\n");
    AddDaun(B, 'Z', 'X', True);
    printf("Pohon B setelah penambahan\n");
    PrintTreeInden(B, 0);
    printf("\n");
    printf("======== InsertX ========\n");
    printf("Pohon B sebelum penambahan simpul 'Y'\n");
    PrintTreeInden(B, 0);
    printf("Menambahkan simpul 'Y' pada pohon B\n");
    InsertX(&B, 'Y');
    printf("Pohon B setelah penambahan simpul 'Y'\n");
    PrintTreeInden(B, 0);
    printf("\n");
    printf("======== DelDaunTerkiri ========\n");
    printf("Pohon B sebelum penghapusan daun terkiri\n");
    PrintTreeInden(B, 0);
    DelDaunTerkiri(&B, &X);
    printf("Pohon B setelah penghapusan daun terkiri\n");
    PrintTreeInden(B, 0);
    printf("Daun terkiri yang dihapus : %c\n", X);
    printf("Alamat daun terkiri yang dihapus : %p\n", &X);
    printf("\n");
    printf("======== DelDaun ========\n");
    printf("Pohon B sebelum penghapusan daun 'C'\n");
    PrintTreeInden(B, 0);
    printf("Menghapus daun 'C' pada pohon B\n");
    DelDaun(&B, 'C');
    printf("Pohon B setelah penghapusan daun 'C'\n");
    PrintTreeInden(B, 0);
    printf("\n");
    printf("======== DeleteX ========\n");
    Z = Tree('A',Tree('B', Tree('Z', Tree('Z', NIL, NIL), NIL), NIL), Tree('C', NIL, NIL));
    printf("\n");
    printf("Pohon Z sebelum penghapusan simpul 'Z'\n");
    PrintTreeInden(Z, 0);
    printf("Menghapus simpul 'Z' pada pohon Z\n");
    DeleteX(&Z, 'Z');
    printf("Pohon Z setelah penghapusan simpul 'Z'\n");
    PrintTreeInden(Z, 0);
    printf("\n");
    printf("======== UpdateAllX ========\n");
    UpdateSemua = Tree('A',Tree('B', Tree('Z', Tree('Z', NIL, NIL), NIL), NIL), Tree('C', NIL, NIL));
    printf("Pohon UpdateSemua sebelum update semua simpul 'Z' menjadi 'Y'\n");
    PrintTreeInden(UpdateSemua, 0);
    printf("Mengupdate semua simpul 'Z' menjadi 'Y' pada pohon Z\n");
    UpdateAllX(&UpdateSemua, 'Z', 'Y');
    printf("Pohon UpdateSemua setelah update semua simpul 'Z' menjadi 'Y'\n");
    PrintTreeInden(UpdateSemua, 0);
    printf("\n");
    printf("======== maxTree ========\n");
    PohonMaxMin = Tree('Y',Tree('B', Tree('Z', Tree('O', NIL, NIL), NIL), NIL), Tree('C', Tree('Y', NIL, NIL), NIL));
    printf("Pohon PohonMaxMin\n");
    PrintTreeInden(PohonMaxMin, 0);
    printf("Huruf maksimal dari PohonMaxMin : %c\n", maxTree(PohonMaxMin));
    printf("\n");
    printf("======== minTree ========\n");
    printf("Pohon PohonMaxMin\n");
    PrintTreeInden(PohonMaxMin, 0);
    printf("Huruf minimal dari PohonMaxMin : %c\n", minTree(PohonMaxMin));
    printf("\n");
    printf("======== BSearch ========\n");
    PohonBinary = Tree('H',Tree('B', NIL, Tree('C', NIL, NIL)), Tree('Z', Tree('S', NIL, NIL), NIL));
    printf("Pohon PohonBinary\n");
    PrintTreeInden(PohonBinary, 0);
    printf("Apakah 'Y' ada pada PohonBinary? %s\n", BSearch(PohonBinary, 'Y') ? "True" : "False");
    printf("Apakah 'B' ada pada PohonBinary? %s\n", BSearch(PohonBinary, 'B') ? "True" : "False");
    printf("\n");
    printf("======== InsSearch ========\n");
    printf("Pohon PohonBinary sebelum penyisipan elemen\n");
    PrintTreeInden(PohonBinary, 0);
    printf("Menyisipkan elemen ke dalam pohon BST\n");
    PohonBinary = InsSearch(PohonBinary, 'F');
    PohonBinary = InsSearch(PohonBinary, 'B');
    PohonBinary = InsSearch(PohonBinary, 'G');
    PohonBinary = InsSearch(PohonBinary, 'D');
    PohonBinary = InsSearch(PohonBinary, 'C');
    PohonBinary = InsSearch(PohonBinary, 'E');
    printf("Pohon PohonBinary setelah penyisipan elemen\n");
    PrintTreeInden(PohonBinary, 0);
    printf("\n");
    printf("======== DelBtree ========\n");
    printf("Pohon PohonBinary sebelum penghapusan simpul 'B'\n");
    PrintTreeInden(PohonBinary, 0);
    printf("Menghapus simpul 'B' pada pohon BST\n");
    DelBtree(&PohonBinary, 'B');
    printf("Pohon PohonBinary setelah penghapusan simpul 'B'\n");
    PrintTreeInden(PohonBinary, 0);
    printf("\n");

    return 0;
}