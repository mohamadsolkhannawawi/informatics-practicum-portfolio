/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal : Jum'at,1 November 2024 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"
#include "list1.c"
int main() {
    //kamus lokal
    List1 senarai_1, senarai_2, senarai_3, senarai_4;
    List1 senarai_5, senarai_6, senarai_7, senarai_8, senarai_copy;
    infotype A;
    address P;
    
    //algoritma
    printf("========================= Menguji CreateList =========================\n");
    CreateList(&senarai_1);
    CreateList(&senarai_2);
    CreateList(&senarai_3);
    printf("List berhasil dibuat\n");

    printf("\n========================= Menguji IsEmptyList =========================\n");
    printf("Apakah senarai_1 kosong? %s\n", IsEmptyList(senarai_1) ? "Ya" : "Tidak");
    printf("Apakah senarai_2 kosong? %s\n", IsEmptyList(senarai_2) ? "Ya" : "Tidak");
    printf("Apakah senarai_3 kosong? %s\n", IsEmptyList(senarai_3) ? "Ya" : "Tidak");

    printf("\n========================= Menguji InsertVFirst =========================\n");
    printf("Menambahkan elemen A, B, C, D ke senarai_1\n");
    InsertVFirst(&senarai_1, 'A');
    InsertVFirst(&senarai_1, 'B');
    InsertVFirst(&senarai_1, 'C');
    InsertVFirst(&senarai_1, 'D');
    printf("Menambahkan elemen X ke senarai_2\n");
    InsertVFirst(&senarai_2, 'X');
    printf("Mengecek kembali apakah senarai_1 kosong? %s\n", IsEmptyList(senarai_1) ? "Ya" : "Tidak");
    printf("Mengecek kembali apakah senarai_2 kosong? %s\n", IsEmptyList(senarai_2) ? "Ya" : "Tidak");
    printf("Mengecek kembali apakah senarai_3 kosong? %s\n", IsEmptyList(senarai_3) ? "Ya" : "Tidak");

    printf("\n========================= Menguji PrintList =========================\n");
    printf("Isi senarai_1: ");
    PrintList(senarai_1);
    printf("\nIsi senarai_2: ");
    PrintList(senarai_2);
    printf("\nIsi senarai_3: ");
    PrintList(senarai_3);

    printf("\n\n========================= Menguji InsertVLast =========================\n");
    printf("Menambahkan elemen E, F, G, H ke senarai_3\n");
    InsertVLast(&senarai_3, 'E');
    InsertVLast(&senarai_3, 'F');
    InsertVLast(&senarai_3, 'G');
    InsertVLast(&senarai_3, 'H');
    printf("Isi senarai_3: ");
    PrintList(senarai_3);

    printf("\n\n========================= Menguji NbElm =========================\n");
    printf("Isi senarai_1: ");
    PrintList(senarai_1);
    printf("\nJumlah elemen senarai_1: %d\n", NbElm(senarai_1));
    printf("Isi senarai_2: ");
    PrintList(senarai_2);
    printf("\nJumlah elemen senarai_2: %d\n", NbElm(senarai_2));
    printf("Isi senarai_3: ");
    PrintList(senarai_3);
    printf("\nJumlah elemen senarai_3: %d\n", NbElm(senarai_3));

    printf("\n========================= Menguji DeleteVFirst =========================\n");
    printf("Isi senarai_1: ");
    PrintList(senarai_1);
    DeleteVFirst(&senarai_1, &A);
    printf("\nMenghapus elemen pertama dari senarai_1\n");
    printf("Isi senarai_1: ");
    PrintList(senarai_1);

    printf("\n\n========================= Menguji DeleteVLast =========================\n");
    printf("Isi senarai_3: ");
    PrintList(senarai_3);
    DeleteVLast(&senarai_3, &A);
    printf("\nMenghapus elemen terakhir dari senarai_3\n");
    printf("Isi senarai_3: ");
    PrintList(senarai_3);

    printf("\n\n========================= Menguji SearchX =========================\n");
    printf("Isi senarai_2: ");
    PrintList(senarai_2);
    printf("\nMencari elemen 'X' di senarai_2\n");
    printf("Hasil pencarian: ");
    SearchX(senarai_2, 'X', P);
    printf("Address dari elemen 'X' di senarai_2: %p\n", P);

    printf("\n\n========================= Menguji UpdateX =========================\n");
    printf("Isi senarai_2: ");
    PrintList(senarai_2);
    printf("\nMengupdate elemen 'X' di senarai_2 menjadi 'Y'\n");
    UpdateX(&senarai_2, 'X', 'Y');
    printf("Isi senarai_2: ");
    PrintList(senarai_2);

    printf("\n\nIsi senarai_3: ");
    PrintList(senarai_3);
    printf("\nMenambahkan elemen 'G' ke senarai_3\n");
    InsertVLast(&senarai_3, 'G');
    printf("Isi senarai_3: ");
    PrintList(senarai_3);
    printf("\nMengupdate elemen 'G' di senarai_3 menjadi 'Z'\n");
    UpdateX(&senarai_3, 'G', 'Z');
    printf("Isi senarai_3: ");
    PrintList(senarai_3);

    printf("\n\n========================= Menguji Invers =========================\n");
    printf("Isi senarai_1: ");
    PrintList(senarai_1);
    printf("\nMembalikkan isi senarai_1\n");
    Invers(&senarai_1);
    printf("Isi senarai_1: ");
    PrintList(senarai_1);
    
    printf("\n\nIsi senarai_3: ");
    PrintList(senarai_3);
    printf("\nMembalikkan isi senarai_3\n");
    Invers(&senarai_3);
    printf("Isi senarai_3: ");
    PrintList(senarai_3);

    printf("\n\n========================= Menguji CountList =========================\n");
    printf("Isi senarai_1: ");
    PrintList(senarai_1);
    printf("\nJumlah elemen 'A' di senarai_1: %d\n", CountX(senarai_1, 'A'));
    printf("Menambahkan elemen 'A' sebanyak 3 ke senarai_1\n");
    InsertVLast(&senarai_1, 'A');
    InsertVLast(&senarai_1, 'A');
    InsertVLast(&senarai_1, 'A');
    printf("Isi senarai_1: ");
    PrintList(senarai_1);
    printf("\nJumlah elemen 'A' di senarai_1: %d\n", CountX(senarai_1, 'A'));

    printf("\n\n========================= Menguji FrekuensiX =========================\n");
    printf("Isi senarai_1: ");
    PrintList(senarai_1);
    printf("\nFrekuensi kemunculan 'A' di senarai_1: %.2f\n", FrekuensiX(senarai_1, 'A'));

    printf("\n\n========================= Menguji SearchAllX =========================\n");
    printf("Isi senarai_1: ");
    PrintList(senarai_1);
    printf("\nMencari posisi kemunculan 'A' di senarai_1\n");
    printf("Posisi kemunculan 'A' di senarai_1: ");
    SearchAllX(senarai_1, 'A');

    printf("\n\n========================= Menguji UpdateAllX =========================\n");
    printf("Isi senarai_1: ");
    PrintList(senarai_1);
    printf("\nMengupdate semua kemunculan 'A' di senarai_1 menjadi 'Z'\n");
    UpdateAllX(&senarai_1, 'A', 'Z');
    printf("Isi senarai_1: ");
    PrintList(senarai_1);

    printf("\n\n========================= Menguji InsertVAfter =========================\n");
    printf("Isi senarai_3 :");
    PrintList(senarai_3);
    printf("\nMenambahkan elemen 'Z' setelah elemen 'G' di senarai_3\n");
    InsertVAfter(&senarai_3, 'G', 'Z');
    printf("Isi senarai_3: ");
    PrintList(senarai_3);

    printf("\n\nIsi senarai_1 :");
    PrintList(senarai_1);
    printf("\nMenambahkan elemen 'O' setelah elemen 'Z' di senarai_1\n");
    InsertVAfter(&senarai_1, 'Z', 'O');
    printf("Isi senarai_1: ");
    PrintList(senarai_1);

    printf("\n\n========================= Menguji MaxMember =========================\n");
    printf("Isi senarai_1: ");
    PrintList(senarai_1);
    printf("\nBanyaknya huruf yang paling banyak muncul di senarai_1: %d\n", MaxMember(senarai_1));

    printf("\n\nIsi senarai_2: ");
    PrintList(senarai_2);
    printf("\nBanyaknya huruf yang paling banyak muncul di senarai_2: %d\n", MaxMember(senarai_2));
    
    printf("\n\nIsi senarai_3: ");
    PrintList(senarai_3);
    printf("\nBanyaknya huruf yang paling banyak muncul di senarai_3: %d\n", MaxMember(senarai_3));

    printf("\n\n========================= Menguji Modus =========================\n");
    printf("Isi senarai_1: ");
    PrintList(senarai_1);
    printf("\nHuruf yang paling banyak muncul di senarai_1: %c\n", Modus(senarai_1));

    printf("\n\nIsi senarai_2: ");
    PrintList(senarai_2);
    printf("\nHuruf yang paling banyak muncul di senarai_2: %c\n", Modus(senarai_2));

    printf("\n\nIsi senarai_3: ");
    PrintList(senarai_3);
    printf("\nHuruf yang paling banyak muncul di senarai_3: %c\n", Modus(senarai_3));

    printf("\n\n========================= Menguji ConcatList =========================\n");
    printf("Isi senarai_1: ");
    PrintList(senarai_1);
    printf("\nIsi senarai_2: ");
    PrintList(senarai_2);
    ConcatList(senarai_1, senarai_2, &senarai_4);
    printf("\nMenggabungkan senarai_1 dan senarai_2 ke senarai_4\n");
    printf("Isi senarai_4: ");
    PrintList(senarai_4);

    printf("\n\n========================= Menguji SplitList =========================\n");
    printf("Isi senarai_1: ");
    PrintList(senarai_1);
    SplitList(senarai_1, &senarai_5, &senarai_6);
    printf("\nMemecah senarai_1 menjadi senarai_5 dan senarai_6\n");
    printf("Isi senarai_5: ");
    PrintList(senarai_5);
    printf("\nIsi senarai_6: ");
    PrintList(senarai_6);

    printf("\n\nIsi senarai_3: ");
    PrintList(senarai_3);
    SplitList(senarai_3, &senarai_7, &senarai_8);
    printf("\nMemecah senarai_3 menjadi senarai_7 dan senarai_8\n");
    printf("Isi senarai_7: ");
    PrintList(senarai_7);
    printf("\nIsi senarai_8: ");
    PrintList(senarai_8);

    printf("\n\n========================= Menguji CopyList =========================\n");
    printf("Isi senarai_1   : ");
    PrintList(senarai_1);
    CopyList(senarai_1, &senarai_copy);
    printf("\nMengcopy isi senarai_1 ke senarai_copy\n");
    printf("Isi senarai_copy: ");
    PrintList(senarai_copy);


















    

  
    return 0;
}