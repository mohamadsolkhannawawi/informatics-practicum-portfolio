/* File : pohon1.h */
/* Deskripsi : File main ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal : Jumat, 22 November 2024*/

#include "pohon1.h"
#include "pohon1.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Kamus Lokal
    bintree P, Q, pohonOneElm;
    infotype X, Y;
    int count;

    // Algoritma
    printf("======================= Pembuatan Tree ==================\n");
    printf("Pohon P, Q dan pohonOneElm dibuat\n");
    P = Tree('A', 
                Tree('B', 
                    NIL, Tree('B',
                             NIL, 
                             NIL)), 
                Tree('C', 
                        Tree('C' ,
                            NIL, 
                            NIL), 
                        NIL));
    printf("Pohon P: ");
    PrintPrefix(P);
    printf("\n");
    Q = Tree('Z', 
            Tree('X', 
                NIL, 
                NIL), 
            Tree('Y', 
                NIL, 
                NIL));
    printf("Pohon Q: ");
    PrintPrefix(Q);
    printf("\n");
    printf("Pohon pohonOneElm: ");
    pohonOneElm = Tree(' ', NIL, NIL);
    PrintPrefix(pohonOneElm);
    printf("\n\n");

    printf("======================= Fungsi GetAkar ==================\n");
    printf("Akar Pohon P: %c\n", GetAkar(P));
    printf("Akar Pohon Q: %c\n", GetAkar(Q));
    printf("Akar Pohon pohonOneElm: %c\n", GetAkar(pohonOneElm));
    printf("\n");
    
    printf("======================= Fungsi GetLeft ==================\n");
    printf("left(P) = %c\n", GetAkar(GetLeft(P)));
    printf("left(Q) = %c\n", GetAkar(GetLeft(Q)));
    printf("\n");

    printf("======================= Fungsi GetRight =================\n");
    printf("right(P) = %c\n", GetAkar(GetRight(P)));
    printf("right(Q) = %c\n", GetAkar(GetRight(Q)));
    printf("\n");

    printf("======================= Fungsi IsEmptyTree ==============\n");
    printf("Apakah P kosong? %s\n", IsEmptyTree(P) ? "True" : "False");
    printf("Apakah Q kosong? %s\n", IsEmptyTree(Q) ? "True" : "False");
    printf("Apakah pohonOneElm kosong? %s\n", IsEmptyTree(pohonOneElm) ? "True" : "False");
    printf("\n");

    printf("======================= Fungsi IsDaun ===================\n");
    printf("Apakah P daun? %s\n", IsDaun(P) ? "True" : "False");
    printf("Apakah Q daun? %s\n", IsDaun(Q) ? "True" : "False");
    printf("Apakah pohonOneElm daun? %s\n", IsDaun(pohonOneElm) ? "True" : "False");
    printf("\n");

    printf("======================= Fungsi IsBiner ==================\n");
    printf("Apakah P biner? %s\n", IsBiner(P) ? "True" : "False");
    printf("Apakah Q biner? %s\n", IsBiner(Q) ? "True" : "False");
    printf("Apakah pohonOneElm biner? %s\n", IsBiner(pohonOneElm) ? "True" : "False");
    printf("\n");

    printf("======================= Fungsi IsUnerLeft ===============\n");
    printf("Apakah P unerleft? %s\n", IsUnerLeft(P) ? "True" : "False");
    printf("Apakah Q unerleft? %s\n", IsUnerLeft(Q) ? "True" : "False");
    printf("Apakah pohonOneElm unerleft? %s\n", IsUnerLeft(pohonOneElm) ? "True" : "False");
    printf("\n");

    printf("======================= Fungsi IsUnerRight ==============\n");
    printf("Apakah P unerright? %s\n", IsUnerRight(P) ? "True" : "False");
    printf("Apakah Q unerright? %s\n", IsUnerRight(Q) ? "True" : "False");
    printf("Apakah pohonOneElm unerright? %s\n", IsUnerRight(pohonOneElm) ? "True" : "False");
    printf("\n");

    printf("======================= Fungsi PrintPrefix ==============\n");
    printf("Prefix P: ");
    PrintPrefix(P);
    printf("\n");
    printf("Prefix Q: ");
    PrintPrefix(Q);
    printf("\n\n");

    printf("======================= Fungsi NbElm ====================\n");
    printf("Jumlah Elemen P: %d\n", NbElm(P));
    printf("Jumlah Elemen Q: %d\n", NbElm(Q));
    printf("Jumlah Elemen pohonOneElm: %d\n", NbElm(pohonOneElm));
    printf("\n");

    printf("======================= Fungsi NbDaun ===================\n");
    printf("Jumlah Daun P: %d\n", NbDaun(P));
    printf("Jumlah Daun Q: %d\n", NbDaun(Q));
    printf("Jumlah Daun pohonOneElm: %d\n", NbDaun(pohonOneElm));
    printf("\n");

    printf("======================= Fungsi Tinggi ===================\n");
    printf("Tinggi P: %d\n", Tinggi(P));
    printf("Tinggi Q: %d\n", Tinggi(Q));
    printf("Tinggi pohonOneElm: %d\n", Tinggi(pohonOneElm));
    printf("\n");

    printf("======================= Fungsi SearchX ==================\n");
    printf("Prefix P: ");
    PrintPrefix(P);
    printf("\n");
    printf("Apakah ada 'B' di P? %s\n", SearchX(P, 'B') ? "True" : "False");
    printf("Apakah ada 'Z' di P? %s\n", SearchX(P, 'Z') ? "True" : "False");
    printf("\n");
    
    printf("======================= Fungsi UpdateX ==================\n");
    printf("Sebelum Update: ");
    PrintPrefix(P);
    printf("\n");
    printf("Setelah Update: ");
    UpdateX(&P, 'B', 'Z');
    PrintPrefix(P);
    printf("\n\n");

    printf("======================= Fungsi CountX ===================\n");
    printf("Prefix P: ");
    PrintPrefix(P);
    printf("\n");
    printf("Jumlah 'Z' di P: %d\n", CountX(P, 'Z'));
    printf("\n");
    printf("Prefix Q: ");
    PrintPrefix(Q);
    printf("\n");
    printf("Jumlah 'Z' di Q: %d\n", CountX(Q, 'Z'));
    printf("\n");

    printf("======================= Fungsi IsSkewLeft ===============\n");
    printf("Print Prefix P: ");
    PrintPrefix(P);
    printf("\n");
    printf("Print Prefix Q: ");
    PrintPrefix(Q);
    printf("\n");
    printf("Apakah pohon condong kiri? %s", IsSkewLeft(P) ? "True" : "False");
    printf("\n");
    printf("Apakah pohon condong kiri? %s", IsSkewLeft(Q) ? "True" : "False");
    printf("\n\n");

    printf("======================= Fungsi IsSkewRight ==============\n");
    printf("Print Prefix P: ");
    PrintPrefix(P);
    printf("\n");
    printf("Print Prefix Q: ");
    PrintPrefix(Q);
    printf("\n");
    printf("Apakah pohon condong kanan? %s", IsSkewRight(P) ? "True" : "False");
    printf("\n");
    printf("Apakah pohon condong kanan? %s", IsSkewRight(Q) ? "True" : "False");
    printf("\n\n");

    printf("======================= Fungsi PrintPrefixRingkas =======\n");
    printf("Prefix P ringkas: ");
    PrintPrefixRingkas(P);
    printf("\n");
    printf("Prefix Q ringkas: ");
    PrintPrefixRingkas(Q);
    printf("\n\n");

    printf("======================= Fungsi LevelX ===================\n");
    printf("Prefix P: ");
    PrintPrefix(P);
    printf("\n");
    printf("Level 'D' di P: %d\n", LevelX(P, 'D'));
    printf("Level 'Z' di P: %d\n", LevelX(P, 'Z'));
    printf("\n");

    printf("======================= Fungsi CountLevelT ==============\n");
    printf("Prefix P: ");
    PrintPrefix(P);
    printf("\n");
    printf("Banyaknya Node pada level 3: %d\n", CountLevelT(P, 3));
    printf("Banyaknya Node pada level 2: %d\n", CountLevelT(P, 2));
    printf("\n");

    printf("======================= Fungsi GetDaunTerkiri ========================\n");
    printf("Prefix P: ");
    PrintPrefix(P);
    printf("\n");
    printf("Daun paling kiri dari P: %c\n", GetDaunTerkiri(P));
    printf("\n");
    printf("Prefix Q: ");
    PrintPrefix(Q);
    printf("\n");
    printf("Daun paling kiri dari Q: %c\n", GetDaunTerkiri(Q));
    printf("\n");

    printf("======================= Fungsi GetDaunTerkanan ========================\n");
    printf("Prefix P: ");
    PrintPrefix(P);
    printf("\n");
    printf("Daun paling kanan dari P: %c\n", GetDaunTerkanan(P));
    printf("\n");
    printf("Prefix Q: ");
    PrintPrefix(Q);
    printf("\n");
    printf("Daun paling kanan dari Q: %c\n", GetDaunTerkanan(Q));
    printf("\n");

    printf("======================= Fungsi FrekuensiX ========================\n");
    printf("Prefix P: ");
    PrintPrefix(P);
    printf("\n");
    printf("Frekuensi 'A' di P: %.2f\n", FrekuensiX(P, 'A'));
    printf("Frekuensi 'Z' di P: %.2f\n", FrekuensiX(P, 'Z'));
    printf("\n");

    printf("======================= Fungsi CountVocal ========================\n");
    printf("Prefix P: ");
    PrintPrefix(P);
    printf("\n");
    printf("CountVocal P: %d\n", CountVocal(P));
    printf("Prefix Q: ");
    PrintPrefix(Q);
    printf("\n");
    printf("CountVocal Q: %d\n", CountVocal(Q));
    printf("\n");

    printf("======================= Fungsi Modus ========================\n");
    printf("Prefix P: ");
    PrintPrefix(P);
    printf("\n");
    printf("Modus P: %c\n", Modus(P));
    printf("Prefix Q: ");
    PrintPrefix(Q);
    printf("\n");
    printf("Modus Q: %c\n", Modus(Q));

    return 0;
}