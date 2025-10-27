/* File : list3.c */
/* Deskripsi : File driver ADT list berkait dengan representasi fisik pointer kait ganda */
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal : Jumat, 15 November 2024*/

#include "list3.h"
#include "list3.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    // Kamus Lokal
    address P;
    infotype V;
    List3 Senarai;
    List3 Senarai_2;
    List3 Senarai_3;
    List3 Senarai_Split_1;
    List3 Senarai_Split_2;
    List3 Senarai_Copy;

    // Algoritma
    // Test buat list kosong
    printf("================== Test CreateList ===================\n");
    CreateList(&Senarai);
    printf("List berhasil dibuat\n");
    printf("\n");
    // Test cek list kosong
    printf("================== Test IsEmptyList ==================\n");
    printf("Apakah List kosong? %s\n", IsEmptyList(Senarai)? "True" : "False");
    printf("\n");
    // Test jumlah 
    printf("===================== Test NbElm =====================\n");
    printf("Jumlah elemen : %d\n", NbElm(Senarai));
    printf("\n");
    // Test InsertVFirst
    printf("=================== Test InsertVFirst ================\n");
    InsertVFirst(&Senarai, 'B');
    InsertVFirst(&Senarai, 'A');
    printf("Apakah List kosong? %s\n", IsEmptyList(Senarai)? "True" : "False");
    printf("Jumlah elemen : %d\n", NbElm(Senarai));
    printf("\n");
    // Test InsertVLast
    printf("=================== Test InsertVLast =================\n");
    InsertVLast(&Senarai, 'C');
    InsertVLast(&Senarai, 'D');
    printf("Apakah List kosong? %s\n", IsEmptyList(Senarai)? "True" : "False");
    printf("Jumlah elemen : %d\n", NbElm(Senarai));
    printf("\n");
    // Test PrintList
    printf("===================== Test PrintList =================\n");
    PrintList(Senarai);
    printf("\n");
    // Test DeleteVFirst
    printf("================== Test DeleteVFirst =================\n");
    DeleteVFirst(&Senarai, &V);
    printf("Elemen yang dihapus : %c\n", V);
    printf("List setelah dihapus : ");
    PrintList(Senarai);
    printf("\n");
    // Test DeleteVLast
    printf("================== Test DeleteVLast ==================\n");
    DeleteVLast(&Senarai, &V);
    printf("Elemen yang dihapus : %c\n", V);
    printf("List setelah dihapus : ");
    PrintList(Senarai);
    printf("\n");
    // Test DeleteX
    printf("==================== Test DeleteX ====================\n");
    InsertVFirst(&Senarai, 'A');
    InsertVLast(&Senarai, 'B');
    InsertVLast(&Senarai, 'C');
    InsertVLast(&Senarai, 'D');
    InsertVLast(&Senarai, 'E');
    printf("List sekarang: ");
    PrintList(Senarai);
    DeleteX(&Senarai, 'A');
    printf("List setelah A dihapus: ");
    PrintList(Senarai);
    DeleteX(&Senarai, 'E');
    printf("List setelah E dihapus: ");
    PrintList(Senarai);
    printf("List setelah C dihapus: ");
    DeleteX(&Senarai, 'C');
    PrintList(Senarai);
    printf("List setelah Z dihapus: ");
    DeleteX(&Senarai, 'Z');
    PrintList(Senarai);
    printf("\n");
    // Test SearchX
    printf("==================== Test SearchX ====================\n");
    printf("List sekarang: ");
    PrintList(Senarai);
    printf("Cari elemen B: ");
    SearchX(Senarai, 'B', &P);
    if (P != NIL) {
        printf("Ada\n");
    } else {
        printf("Tidak ada\n");
    }
    printf("Address B: %p\n", P);
    printf("Cari elemen Z: ");
    SearchX(Senarai, 'Z', &P);
    if (P != NIL) {
        printf("Ada\n");
    } else {
        printf("Tidak ada\n");
    }
    printf("Address Z: %p\n", P);
    printf("\n");
    // Test UpdateX
    printf("==================== Test UpdateX ====================\n");
    printf("List sebelum diupdate B menjadi Z: ");
    PrintList(Senarai);
    UpdateX(&Senarai, 'B', 'Z');
    printf("List setelah diupdate B menjadi Z: ");
    PrintList(Senarai);
    printf("List sebelum diupdate U menjadi A: ");
    PrintList(Senarai);
    UpdateX(&Senarai, 'U', 'A');
    printf("List setelah diupdate U menjadi A: ");
    PrintList(Senarai);
    printf("\n");
    // Test Invers
    printf("===================== Test Invers ====================\n");
    InsertVFirst(&Senarai, 'A');
    InsertVLast(&Senarai, 'B');
    printf("List sebelum di invers: ");
    PrintList(Senarai);
    Invers(&Senarai);
    printf("List setelah di invers: ");
    PrintList(Senarai);
    printf("\n");
    // Test InsertVAfterX
    printf("================ Test InsertVAfterX ==================\n");
    printf("List sebelum insert C after B: ");
    PrintList(Senarai);
    InsertVAfterX(&Senarai, 'B', 'C');
    printf("List setelah insert C after B: ");
    PrintList(Senarai);
    printf("List setelah insert X after Z: ");
    InsertVAfterX(&Senarai, 'Z', 'X');
    PrintList(Senarai);
    printf("\n");
    // Test InsertVBeforeX
    printf("================ Test InsertVBeforeX =================\n");
    CreateList(&Senarai_2);
    InsertVLast(&Senarai_2, 'A');
    InsertVLast(&Senarai_2, 'B');
    InsertVLast(&Senarai_2, 'D');
    printf("List sebelum insert C before D: ");
    PrintList(Senarai_2);
    InsertVBeforeX(&Senarai_2, 'D', 'C');
    printf("List setelah insert C before C: ");
    PrintList(Senarai_2);
    printf("List setelah insert B before C: ");
    InsertVBeforeX(&Senarai_2, 'C', 'B');
    PrintList(Senarai_2);
    printf("\n");
    // Test DeleteVAfterX
    printf("================ Test DeleteVAfterX ==================\n");
    printf("List sebelum delete after C: ");
    PrintList(Senarai);
    DeleteVAfterX(&Senarai, 'C', &V);
    printf("List setelah delete after C: ");
    PrintList(Senarai);
    printf("\n");
    // Test DeleteVBeforeX
    printf("================= Test DeleteVBeforeX ================\n");
    InsertVFirst(&Senarai, 'A');
    InsertVFirst(&Senarai, 'B');
    printf("List sebelum delete before C: ");
    PrintList(Senarai);
    DeleteVBeforeX(&Senarai, 'C', &V);
    printf("List setelah delete before C: ");
    PrintList(Senarai);
    printf("\n");
    // Test CountX
    printf("==================== Test CountX =====================\n");
    printf("List sekarang: ");
    PrintList(Senarai);
    printf("Jumlah B: %d\n", CountX(Senarai, 'B'));
    printf("Jumlah Z: %d\n", CountX(Senarai, 'Z'));
    printf("Jumlah D: %d\n", CountX(Senarai, 'D'));
    printf("\n");
    // Test FrekuensiX
    printf("==================== Test FrekuensiX =================\n");
    printf("List sekarang: ");
    PrintList(Senarai);
    printf("Frekuensi B: %f\n", FrekuensiX(Senarai, 'B'));
    printf("Frekuensi Z: %f\n", FrekuensiX(Senarai, 'Z'));
    printf("Frekuensi D: %f\n", FrekuensiX(Senarai, 'D'));
    printf("\n");
    // Test MaxMember
    printf("=================== Test MaxMember ===================\n");
    printf("List sekarang: ");
    PrintList(Senarai);
    printf("Banyaknya huruf yang paling banyak muncul: %d\n", MaxMember(Senarai));
    printf("\n");
    // Test Modus
    printf("==================== Test Modus ======================\n");
    printf("List sekarang: ");
    PrintList(Senarai);
    printf("Huruf yang paling banyak muncul: %c\n", Modus(Senarai));
    printf("\n");
    // Test CountVocal
    printf("================== Test CountVocal ===================\n");
    printf("List sekarang: ");
    PrintList(Senarai);
    printf("Banyaknya huruf vokal: %d\n", CountVocal(Senarai));
    printf("\n");
    // Test CountNG
    printf("==================== Test CountNG ====================\n");
    printf("List sekarang: ");
    printf("\n");
    PrintList(Senarai);
    printf("Banyaknya huruf NG: %d\n", CountNG(Senarai));
    InsertVLast(&Senarai, 'N');
    InsertVLast(&Senarai, 'G');
    InsertVLast(&Senarai, 'N');
    InsertVLast(&Senarai, 'G');
    printf("List sekarang: ");
    printf("\n");
    PrintList(Senarai);
    printf("Banyaknya huruf NG: %d\n", CountNG(Senarai));
    printf("\n");
    // Test SearchAllX
    printf("=================== Test SearchAllX ==================\n");
    printf("List sekarang: ");
    printf("\n");
    PrintList(Senarai);
    printf("Search All C: ");
    SearchAllX(Senarai, 'C');
    printf("\n\n");
    // Test DeleteAllX
    printf("=================== Test DeleteAllX ==================\n");
    printf("List sebelum delete semua Z: ");
    printf("\n");
    PrintList(Senarai);
    DeleteAllX(&Senarai, 'Z');
    printf("List setelah delete semua Z: ");
    printf("\n");
    PrintList(Senarai);
    printf("\n");
    // Test ConcatList
    printf("================== Test ConcatList ==================\n");
    printf("List 1: ");
    PrintList(Senarai);
    printf("List 2: ");
    PrintList(Senarai_2);
    ConcatList(Senarai, Senarai_2, &Senarai_3);
    printf("List setelah di concat: ");
    printf("\n");
    PrintList(Senarai_3);
    printf("\n");
    // Test SplitList
    printf("================== Test SplitList ==================\n");
    printf("List sebelum di split: ");
    printf("\n");
    PrintList(Senarai_3);
    SplitList(Senarai_3, &Senarai_Split_1, &Senarai_Split_2);
    printf("List 1 setelah di split: ");
    PrintList(Senarai_Split_1);
    printf("List 2 setelah di split: ");
    PrintList(Senarai_Split_2);
    printf("\n");
    // Test CopyList
    printf("=================== Test CopyList ==================\n");
    printf("List 1 : ");
    printf("\n");
    PrintList(Senarai);
    CopyList(Senarai, &Senarai_Copy);
    printf("List Copy dari List 1: ");
    printf("\n");
    PrintList(Senarai_Copy);
    printf("\n");
    return 0;
}