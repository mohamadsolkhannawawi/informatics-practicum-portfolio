/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060123120020/Mohamad Solkhan Nawawi*/
/* Tanggal   : Jumat, 20 September 2024*/
/***********************************/

#include <stdio.h>
#include <string.h>
/* include tstack+boolean */
#include "tstack.c"
#include "boolean.h"


int main() {	/* kamus main */
	Tstack A, B, C, D; // stack A, B, C, D
    int i; // iterator
    char X; //variabel untuk menyimpan hasil pop
    int N; //variabel untuk menyimpan jumlah stack yang ingin di-push
    char PALIN[11]; //variabel untuk menyimpan kata palindrom
	
	/* algoritma */
	createStack(&A);
    createStack(&B);
    createStack(&C);
    createStack(&D);

    // TESTING FUNGSI
    //TESTING CREATESTACK
    //TESTING isEmptyStack dan isFullStack
    printf("================== APLIKASI CreateStack ==================\n");
    printf("Membuat stack kosong pada Stack A\n");
    createStack(&A);
    printf("Isi Stack A saat ini :\n");
    printStack(A);
    printf("\nStack A kosong ? %s\n", isEmptyStack(A) ? "Ya" : "Tidak");
    printf("Stack A penuh ? %s\n", isFullStack(A) ? "Ya" : "Tidak");

    //TESTING PUSH
    printf("================== APLIKASI push ==================\n"); 
    printf("Push 'A' pada Stack A :\n");
    push(&A, 'A');
    printf("Isi Stack A saat ini :\n");
    printStack(A);

    //TESTING ISFULLSTACK
    printf("\n================== APLIKASI PREDIKAT========\n");
    printf("Menambahkan isi dari stack A hingga penuh\n");
    push(&A, 'B');
    push(&A, 'C');
    push(&A, 'D');
    push(&A, 'E');
    push(&A, 'F');
    push(&A, 'G');
    push(&A, 'H');
    push(&A, 'I');
    push(&A, 'J');
    printf("Stack A saat ini :\n");
    printStack(A);
    printf("\nStack A kosong ? %s\n", isEmptyStack(A) ? "Ya" : "Tidak");
    printf("Stack A penuh ? %s\n", isFullStack(A) ? "Ya" : "Tidak");

    //TESTING POP
    printf("================== APLIKASI pop ==================\n");
    printf("Isi stack A sebelum di-pop :\n");
    printStack(A);
    printf("\nPop stack A\n");
    pop(&A, &X);
    printf("Elemen yang di-pop: %c\n", X);
    printf("Isi Stack A setelah di-pop :\n");
    printStack(A);

    //TESTING print dan view
    printf("\n================== APLIKASI PRINT DAN VIEW ==================\n");
    printf("Print Stack A :\n");
    printStack(A);
    printf("\nView Stack A :\n");
    viewStack(A);

    //Test infoTOP dan TOP
    printf("\n================== APLIKASI INFOTOP DAN TOP ==================\n");
    printf("View Stack A :\n");
    viewStack(A);
    printf("\nNilai dari Top Stack A : %c\n", infotop(A));
    printf("Top Stack A : %d\n", top(A));

    //TESTING pushN
    printf("================== APLIKASI PushN ==================\n");
    printf("Masukan jumlah stack yang ingin di-push pada Stack B (Maksimal 10): ");
    scanf ("%d", &N);
    pushN(&B, N);
    printf("Isi Stack B saat ini : \n");
    printStack(B);

    //TESTING pushBabel1
    printf("\n================== APLIKASI PushBabel1 ==================\n");
    printf("Print stack B :\n");
    printStack(B);
    printf("\nMenambahkan char 'Z' pada stack B\n");
    pushBabel1(&B, 'Z');
    printStack(B);

    //TESTING pushZuma
    printf("\n================== APLIKASI PushZuma ==================\n");
    printf("Mengisi stack C dengan 'A', 'B', 'C'\n");
    push(&C, 'A');
    push(&C, 'B');
    push(&C, 'C');
    printf("Print stack C : \n");
    printStack(C);
    printf("\nMenambahkan 'C' pada stack C\n");
    pushZuma(&C, 'C');
    printf("Print stack C saat ini : \n");
    printStack(C);
    printf("\nMenambahkan 'D' pada stack C\n");
    pushZuma(&C, 'D');
    printf("Print stack C saat ini : \n");
    printStack(C);

    // TUGAS PALINDROM
    printf("\n================== APLIKASI PALINDROM ==================\n");
    printf("Masukan kata PALINDROM : ");
    scanf(" %s", &PALIN);
    for (i = 0; i < strlen(PALIN); i++) {
        push(&D, PALIN[i]);
    }
    for (i = 0; i < strlen(PALIN); i++) {
        pop(&D, &X);
        if (X != PALIN[i]) {
            printf("Kata %s bukan palindrom\n", PALIN);
            return 0;
        }
    }
    printf("Kata %s adalah palindrom\n", PALIN);
	return 0;
}