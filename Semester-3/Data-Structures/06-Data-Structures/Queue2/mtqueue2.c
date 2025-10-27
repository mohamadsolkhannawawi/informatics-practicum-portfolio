/* Program   : mtqueue2.h */
/* Deskripsi : Driver main untuk ADT Queue 2, 
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060123120020/Mohamad Solkhan Nawawi*/
/* Tanggal   : Jumat, 4 Oktober 2024*/
/***********************************/

// Include header file
#include <stdio.h>
#include "tqueue2.h"
#include "tqueue2.c"

// Main program
int main() {
    // Kamus
    tqueue2 Q1;
    tqueue2 Q2;
    tqueue2 Q3;
    tqueue2 Q4;
    tqueue2 Q5;
    char E;
    // Algoritma
    createQueue2(&Q1);
    createQueue2(&Q2);
    createQueue2(&Q3);
    printf("=================== Testing Fungsi createQueue2 ===================\n");
    printf("Q1: ");
    printQueue2(Q1);
    printf("\n");
    printf("Q2: ");
    printQueue2(Q2);
    printf("\n");
    printf("Q3: ");
    printQueue2(Q3);
    printf("\n");

    printf("=================== Testing Fungsi Enqueue dan Dequeue ===================\n");
    printf("Menguji Enqueue dan Dequeue pada Q1, Q2 dan Q3 :\n");
    printf("Menambahkan elemen A, B, C, D dan E ke Q1: \n");
    enqueue2(&Q1, 'A');
    enqueue2(&Q1, 'B');
    enqueue2(&Q1, 'C');
    enqueue2(&Q1, 'D');
    enqueue2(&Q1, 'E');
    printf("Q1: ");
    printQueue2(Q1);
    printf("\n");
    dequeue2(&Q1, &E);
    printf("Menghapus elemen %c dari Q1\n", E);
    printf("Q1: ");
    printQueue2(Q1);
    printf("\n");
    dequeue2(&Q1, &E);
    printf("Menghapus elemen %c dari Q1\n", E);
    printf("Q1: ");
    printQueue2(Q1);
    printf("\n");
    printf("Menambahkan elemen A ke Q2 \n");
    enqueue2(&Q2, 'A');
    printf("Q2: ");
    printQueue2(Q2);
    printf("\n");
    dequeue2(&Q2, &E);
    printf("Menghapus elemen %c dari Q2\n", E);
    printf("Q2: ");
    printQueue2(Q2);
    printf("\n");
    printf("Menambahkan elemen A ke Q2: \n");
    enqueue2(&Q2, 'A');
    printf("Q2: ");
    printQueue2(Q2);
    printf("\n");
    printf("Q3 adalah antrian kosong\n");
    printf("Q3: ");
    printQueue2(Q3);
    printf("\n");
    dequeue2(&Q3, &E);
    printf("Menghapus elemen %c dari Q3\n", E);
    printf("Q3: ");
    printQueue2(Q3);
    printf("\n");

    printf("=================== Testing Fungsi Predikat ===================\n");
    printf("Menguji fungsi isEmptyQueue2, isFullQueue2, isTailStop, isOneElement2 pada Q1, Q2 dan Q3:\n");

    printf("Q1: ");
    printQueue2(Q1);
    printf("\n");
    printf("Head Q1: %d\n", head2(Q1));
    printf("Tail Q1: %d\n", tail2(Q1));
    printf("Info Head Q1: %c\n", infoHead2(Q1));
    printf("Info Tail Q1: %c\n", infoTail2(Q1));
    printf("\n");
    printf("Q2: ");
    printQueue2(Q2);
    printf("\n");
    printf("Head Q2: %d\n", head2(Q2));
    printf("Tail Q2: %d\n", tail2(Q2));
    printf("Info Head Q2: %c\n", infoHead2(Q2));
    printf("Info Tail Q2: %c\n", infoTail2(Q2));
    printf("\n");
    printf("Q3: ");
    printQueue2(Q3);
    printf("\n");
    printf("Head Q3: %d\n", head2(Q3));
    printf("Tail Q3: %d\n", tail2(Q3));
    printf("Info Head Q3: %c\n", infoHead2(Q3));
    printf("Info Tail Q3: %c\n", infoTail2(Q3));
    printf("\n");
    printf("Apakah Q1 kosong? %s\n", isEmptyQueue2(Q1) ? "Ya" : "Tidak");
    printf("Apakah Q2 kosong? %s\n", isEmptyQueue2(Q2) ? "Ya" : "Tidak");
    printf("Apakah Q3 kosong? %s\n", isEmptyQueue2(Q3) ? "Ya" : "Tidak");
    printf("Apakah Q1 penuh? %s\n", isFullQueue2(Q1) ? "Ya" : "Tidak");
    printf("Apakah Q2 penuh? %s\n", isFullQueue2(Q2) ? "Ya" : "Tidak");
    printf("Apakah Q3 penuh? %s\n", isFullQueue2(Q3) ? "Ya" : "Tidak");
    printf("Apakah Tail Q1 sudah mencapai kapasitas? %s\n", isTailStop(Q1) ? "Ya" : "Tidak");
    printf("Apakah Tail Q2 sudah mencapai kapasitas? %s\n", isTailStop(Q2) ? "Ya" : "Tidak");
    printf("Apakah Tail Q3 sudah mencapai kapasitas? %s\n", isTailStop(Q3) ? "Ya" : "Tidak");
    printf("Apakah Q1 hanya memiliki satu elemen? %s\n", isOneElement2(Q1) ? "Ya" : "Tidak");
    printf("Apakah Q2 hanya memiliki satu elemen? %s\n", isOneElement2(Q2) ? "Ya" : "Tidak");
    printf("Apakah Q3 hanya memiliki satu elemen? %s\n", isOneElement2(Q3) ? "Ya" : "Tidak");

    printf("=================== Testing Fungsi lainnya ===================\n");
    printf("Menguji fungsi lainnya pada Q1, Q2 dan Q3:\n");
    enqueue2(&Q1, 'A');
    enqueue2(&Q1, 'B');
    printf("Q1: ");
    printQueue2(Q1);
    printf("\n");
    printf("Q2: ");
    printQueue2(Q2);
    printf("\n");
    printf("Q3: ");
    printQueue2(Q3);
    printf("\n");
    printf("Head Q1: %d\n", head2(Q1));
    printf("Tail Q1: %d\n", tail2(Q1));
    printf("Info Head Q1: %c\n", infoHead2(Q1));
    printf("Info Tail Q1: %c\n", infoTail2(Q1));
    printf("Panjang antrian Q1: %d\n", sizeQueue2(Q1));
    printf("Head Q2: %d\n", head2(Q2));
    printf("Tail Q2: %d\n", tail2(Q2));
    printf("Info Head Q2: %c\n", infoHead2(Q2));
    printf("Info Tail Q2: %c\n", infoTail2(Q2));
    printf("Panjang antrian Q2: %d\n", sizeQueue2(Q2));
    printf("Head Q3: %d\n", head2(Q3));
    printf("Tail Q3: %d\n", tail2(Q3));
    printf("Info Head Q3: %c\n", infoHead2(Q3));
    printf("Info Tail Q3: %c\n", infoTail2(Q3));
    printf("Panjang antrian Q3: %d\n", sizeQueue2(Q3));

    printf("=================== Testing Fungsi Enqueue2N ===================\n");
    printf("Menguji fungsi Enqueue2N pada Q3:\n");
    printf("Q3: ");
    printQueue2(Q3);
    printf("\n");
    enqueue2N(&Q3, 3);
    printf("Q3 setelah menambahkan 3 elemen: ");
    printQueue2(Q3);
    printf("\n");

    printf("=================== Testing Fungsi PrintQueue2 dan ViewQueue2 ===================\n");
    printf("Menguji fungsi PrintQueue2 pada Q1, Q2 dan Q3:\n");
    printf("Q1: ");
    printQueue2(Q1);
    printf("\n");
    printf("Q2: ");
    printQueue2(Q2);
    printf("\n");
    printf("Q3: ");
    printQueue2(Q3);
    printf("\n");
    printf("Menguji fungsi ViewQueue2 pada Q1, Q2 dan Q3:\n");
    printf("Q1: ");
    viewQueue2(Q1);
    printf("\n");
    printf("Q2: ");
    viewQueue2(Q2);
    printf("\n");
    printf("Q3: ");
    viewQueue2(Q3);
    printf("\n");
    printf("Menghapus elemen dari Q2: \n");
    dequeue2(&Q2, &E);
    printf("Menampilkan Q2 dengan ViewQueue2: ");
    printf("\n");
    printf("Q2: ");
    viewQueue2(Q2);
    printf("\n");

    printf("=================== Testing Fungsi Ekstra ===================\n");
    printf("Menguji pada Q4 dan Q5:\n");
    createQueue2(&Q4);
    createQueue2(&Q5);
    printf("Menambahkan elemen A, B, C ke Q4: \n");
    enqueue2(&Q4, 'P');
    enqueue2(&Q4, 'Q');
    enqueue2(&Q4, 'R');
    printQueue2(Q4);
    printf("\n");
    printf("Menambahkan elemen P, Q, R ke Q5: \n");
    enqueue2(&Q5, 'P');
    enqueue2(&Q5, 'Q');
    enqueue2(&Q5, 'R');
    printQueue2(Q5);
    printf("\n");
    printf("\n");
    printf("Mengecek apakah Q4 dan Q5 isEqualQueue :");
    printf("\n");
    printf("Apakah Q4 dan Q5 sama? %s\n", isEqualQueue2(Q4, Q5) ? "Tidak" : "Ya");

}