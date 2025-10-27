/* Program   : mtqueue.c */
/* Deskripsi : file main untuk menguji realiasi body dari tqueue.c */
/* NIM/Nama  : 24060123120020/Mohamad Solkhan Nawawi*/
/* Tanggal   : Jumat, 27 September 2024*/
/***********************************/


#include <stdio.h>

//Include tqueue.h
#include "tqueue.h"
#include "tqueue.c"


int main() {
    //Kamus Lokal
    tqueue Q1;
    tqueue Q2;
    tqueue Q3;
    char e;

    //Algortima
    createQueue(&Q1);
    createQueue(&Q2);
    createQueue(&Q3);

    //Testing createQueue
    printf("================== Menguji createQueue ==================\n");
    printf("Menambahkan elemen ke dalam Q1, Q2 dan Q3\n");
    enqueue(&Q1, 'A');
    enqueue(&Q1, 'B');
    enqueue(&Q1, 'C');
    enqueue(&Q1, 'D');
    enqueue(&Q1, 'E');
    enqueue(&Q1, 'F');
    enqueue(&Q1, 'G');
    enqueue(&Q1, 'H');
    enqueue(&Q1, 'I');
    enqueue(&Q1, 'J');

    enqueue(&Q2, 'K');

    printf("Isi dari Q1 adalah: ");
    printQueue(Q1);
    printf("\n");
    printf("Isi dari Q2 adalah: ");
    printQueue(Q2);
    printf("\n");
    printf("Isi dari Q3 adalah: ");
    printQueue(Q3);
    printf("\n");

    //Testing infoHead dan infoTail
    printf("================== Menguji infoHead dan infoTail==================\n");
    printf("Isi dari Q1 adalah: ");
    printQueue(Q1);
    printf("\n");
    printf("Posisi head dari Q1 adalah: %d\n", head(Q1));
    printf("Head dari Q1 adalah: %c\n", infoHead(Q1));
    printf("Posisi tail dari Q1 adalah: %d\n", tail(Q1));
    printf("Tail dari Q1 adalah: %c\n", infoTail(Q1));
    printf("\n");
    printf("Isi dari Q2 adalah: ");
    printQueue(Q2);
    printf("\n");
    printf("Posisi head dari Q2 adalah: %d\n", head(Q2));
    printf("Head dari Q2 adalah: %c\n", infoHead(Q2));
    printf("Posisi tail dari Q2 adalah: %d\n", tail(Q2));
    printf("Tail dari Q2 adalah: %c\n", infoTail(Q2));
    printf("\n");
    printf("Isi dari Q3 adalah: ");
    printQueue(Q3);
    printf("\n");
    printf("Posisi head dari Q3 adalah: %d\n", head(Q3));
    printf("Head dari Q3 adalah: %c\n", infoHead(Q3));
    printf("Posisi tail dari Q3 adalah: %d\n", tail(Q3));
    printf("Tail dari Q3 adalah: %c\n", infoTail(Q3));

    //Testing sizeQueue
    printf("================== Menguji sizeQueue ==================\n");
    printf("Panjang dari Q1 adalah: %d\n", sizeQueue(Q1));
    printf("Panjang dari Q2 adalah: %d\n", sizeQueue(Q2));
    printf("Panjang dari Q3 adalah: %d\n", sizeQueue(Q3));

    //Testing printQueue dan viewQueue
    printf("================== Menguji printQueue dan viewQueue ==================\n");
    printf("Dengan printQueue");
    printf("\n");
    printf("Isi dari Q1 adalah: ");
    printQueue(Q1);
    printf("\n");
    printf("Dengan viewQueue");
    printf("\n");
    printf("Isi dari Q1 adalah: ");
    viewQueue(Q1);
    printf("\n");
    printf("Dengan printQueue");
    printf("\n");
    printf("Isi dari Q2 adalah: ");
    printQueue(Q2);
    printf("\n");
    printf("Dengan viewQueue");
    printf("\n");
    printf("Isi dari Q2 adalah: ");
    viewQueue(Q2);
    printf("\n");
    printf("Dengan printQueue");
    printf("\n");
    printf("Isi dari Q3 adalah: ");
    printQueue(Q3);
    printf("\n");
    printf("Dengan viewQueue");
    printf("\n");
    printf("Isi dari Q3 adalah: ");
    viewQueue(Q3);
    printf("\n");

    //Testing fungsi Predikat
    printf("================== Menguji fungsi Predikat ==================\n");
    printf("Apakah Q1 kosong? %s\n", isEmptyQueue(Q1) ? "Iya" : "Tidak");
    printf("Apakah Q1 penuh? %s\n", isFullQueue(Q1) ? "Iya" : "Tidak");
    printf("Apakah Q1 hanya memiliki 1 elemen? %s\n", isOneElement(Q1) ? "Iya" : "Tidak");

    printf("Apakah Q2 kosong? %s\n", isEmptyQueue(Q2) ? "Iya" : "Tidak");
    printf("Apakah Q2 penuh? %s\n", isFullQueue(Q2) ? "Iya" : "Tidak");
    printf("Apakah Q2 hanya memiliki 1 elemen? %s\n", isOneElement(Q2) ? "Iya" : "Tidak");

    printf("Apakah Q3 kosong? %s\n", isEmptyQueue(Q3) ? "Iya" : "Tidak");
    printf("Apakah Q3 penuh? %s\n", isFullQueue(Q3) ? "Iya" : "Tidak");
    printf("Apakah Q3 hanya memiliki 1 elemen? %s\n", isOneElement(Q3) ? "Iya" : "Tidak");

    //Testing enqueue
    printf("================== Menguji enqueue ==================\n");
    printf("Isi dari Q2 sebelum enqueue adalah: ");
    printQueue(Q2);
    printf("\n");
    printf("Menambahkan elemen 'L' ke dalam Q2\n");
    enqueue(&Q2, 'L');
    printf("Isi dari Q2 setelah enqueue adalah: ");
    printQueue(Q2);
    printf("\n");

    //Testing dequeue
    printf("================== Menguji dequeue ==================\n");
    printf("Isi dari Q1 sebelum dequeue adalah: ");
    printQueue(Q1);
    printf("\n");
    dequeue(&Q1, &e);
    printf("Isi dari Q1 setelah dequeue adalah: ");
    printQueue(Q1);
    printf("\n");

    //Testing enqueue1
    printf("================== Menguji enqueue1 ==================\n");
    printf("Menambahkan elemen 'Z' ke dalam Q1 agar penuh.\n");
    enqueue(&Q1, 'Z');
    printf("Isi dari Q1 sebelum enqueue1 adalah: ");
    printQueue(Q1);
    enqueue1(&Q1, 'K');
    printf("\n");
    printf("Isi dari Q1 setelah enqueue1 adalah: ");
    printQueue(Q1);
    printf("\n");

    printf("Isi dari Q2 sebelum enqueue1 adalah: ");
    printQueue(Q2);
    printf("\n");
    enqueue1(&Q2, 'M');
    printf("Isi dari Q2 setelah enqueue1 adalah: ");
    printQueue(Q2);
    printf("\n");

    //Testing maxlength
    printf("================== Menguji maxlength ==================\n");
    printf("Panjang dari Q1 adalah : %d\n", sizeQueue(Q1));
    printf("Panjang dari Q2 adalah : %d\n", sizeQueue(Q2));
    printf("Panjang dari Q3 adalah : %d\n", sizeQueue(Q3));
    printf("maxLength dari Q1 dan Q2 adalah : %d\n", maxlength(Q1, Q2));
    printf("maxLength dari Q1 dan Q3 adalah : %d\n", maxlength(Q1, Q3));
    printf("maxLength dari Q2 dan Q3 adalah : %d\n", maxlength(Q2, Q3));

    //Testing enqueue2
    printf("================== Menguji enqueue2 ==================\n");
    printf("Isi dari Q1 sebelum enqueue2 adalah: ");
    printQueue(Q1);
    printf("\n");
    printf("Isi dari Q2 sebelum enqueue2 adalah: ");
    printQueue(Q2);
    printf("\n");
    enqueue2(&Q1, &Q2, 'Z');
    printf("Isi dari Q1 setelah enqueue2 adalah: ");
    printQueue(Q1);
    printf("\n");
    printf("Isi dari Q2 setelah enqueue2 adalah: ");
    printQueue(Q2);
    printf("\n");

    //Testing dequeue2
    printf("================== Menguji dequeue2 ==================\n");
    printf("Isi dari Q1 sebelum dequeue2 adalah: ");
    printQueue(Q1);
    printf("\n");
    printf("Isi dari Q2 sebelum dequeue2 adalah: ");
    printQueue(Q2);
    printf("\n");
    dequeue2(&Q1, &Q2, &e);
    printf("Isi dari Q1 setelah dequeue2 adalah: ");
    printQueue(Q1);
    printf("\n");
    printf("Isi dari Q2 setelah dequeue2 adalah: ");
    printQueue(Q2);

}