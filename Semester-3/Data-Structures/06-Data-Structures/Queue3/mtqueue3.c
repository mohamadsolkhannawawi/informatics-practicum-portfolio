/* Program   : tqueue3.h */
/* Deskripsi : Driver main ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060123120020/Mohamad Solkhan Nawawi*/
/* Tanggal   : Jumat, 4 Oktober 2024*/
/***********************************/

#include "tqueue3.h"
#include "tqueue3.c"
#include <stdio.h>

int main () {
    //Kamus Lokal
    tqueue3 Q1;
    tqueue3 Q2;
    tqueue3 Q3;
    tqueue3 Q4;
    tqueue3 Q5;
    tqueue3 Q6;
    char E;
    //Algoritma
    printf("================== Testing createQueue3 ===================\n");
    createQueue3(&Q1);
    createQueue3(&Q2);
    createQueue3(&Q3);
    printf("Q1: ");
    printQueue3(Q1);
    printf("\nQ2: ");
    printQueue3(Q2);
    printf("\nQ3: ");
    printQueue3(Q3);
    printf("\n");
    printf("================== Testing enQueue3 dan deQueue3 ===================\n");
    printf("Menambahkan elemen A, B, C, D, E : \n");
    enqueue3(&Q1, 'A');
    enqueue3(&Q1, 'B');
    enqueue3(&Q1, 'C');
    enqueue3(&Q1, 'D');
    enqueue3(&Q1, 'E');
    printf("Q1: ");
    printQueue3(Q1);
    printf("\n");
    printf("Menghapus elemen Q1\n");
    dequeue3(&Q1, &E);
    printf("Elemen yang dihapus: %c\n", E);
    printf("Q1: ");
    printQueue3(Q1);
    printf("\n");
    printf("Menambahkan Q1 dengan elemen 'F' :\n");
    enqueue3(&Q1, 'F');
    printf("Q1: ");
    printQueue3(Q1);
    printf("\n");
    printf("Menambahkan Q1 dengan elemen 'G' :\n");
    enqueue3(&Q1, 'G');
    printf("Q1: ");
    printQueue3(Q1);
    printf("\n");
    printf("Tidak bisa menambah elemen lagi karena penuh\n");
    printf("Menguji fungsi deQueue3 pada Q2 yang kosong\n");
    dequeue3(&Q2, &E);
    printf("Elemen yang dihapus: %c\n", E);
    printf("Q2: ");
    printQueue3(Q2);
    printf("\n");
    printf("================== Testing fungsi Predikat ===================\n");
    printf("Q1 :");
    printQueue3(Q1);
    printf("\n");
    printf("Q2 :");
    enqueue3(&Q2, 'Z');
    printQueue3(Q2);
    printf("\n");
    printf("Q3 :");
    printQueue3(Q3);
    printf("\n");
    printf("Apakah Q1 kosong? %s\n", isEmptyQueue3(Q1) ? "Iya" : "Tidak");
    printf("Apakah Q2 kosong? %s\n", isEmptyQueue3(Q2) ? "Iya" : "Tidak");
    printf("Apakah Q3 kosong? %s\n", isEmptyQueue3(Q3) ? "Iya" : "Tidak");

    printf("Apakah Q1 penuh? %s\n", isFullQueue3(Q1) ? "Iya" : "Tidak");
    printf("Apakah Q2 penuh? %s\n", isFullQueue3(Q2) ? "Iya" : "Tidak");
    printf("Apakah Q3 penuh? %s\n", isFullQueue3(Q3) ? "Iya" : "Tidak");

    printf("Apakah Q1 1 elemen? %s\n", isOneElement3(Q1) ? "Iya" : "Tidak");
    printf("Apakah Q2 1 elemen? %s\n", isOneElement3(Q2) ? "Iya" : "Tidak");
    printf("Apakah Q3 1 elemen? %s\n", isOneElement3(Q3) ? "Iya" : "Tidak");

    printf("================== Testing fungsi lainnya ===================\n");
    printf("createQueue3(&Q4)\n");
    createQueue3(&Q4);
    printf("Q4: ");
    printQueue3(Q4);
    printf("\n");
    printf("Mengisi Q4 dengan 'A', 'B', 'C', 'D', 'E'\n");
    enqueue3(&Q4, 'A');
    enqueue3(&Q4, 'B');
    enqueue3(&Q4, 'C');
    enqueue3(&Q4, 'D');
    enqueue3(&Q4, 'E');
    printf("Q4: ");
    printQueue3(Q4);
    printf("\n");
    printf("Menguji fungsi head3, tail3, infohead3, infotail3 dan sizeQueue3\n");
    printf("Head Q4: %d\n", head3(Q4));
    printf("Tail Q4: %d\n", tail3(Q4));
    printf("InfoHead Q4: %c\n", infoHead3(Q4));
    printf("InfoTail Q4: %c\n", infoTail3(Q4));
    printf("Size Q4: %d\n", sizeQueue3(Q4));
    printf("Menghapus elemen Q4\n");
    dequeue3(&Q4, &E);
    printf("Q4: ");
    printQueue3(Q4);
    printf("\n");
    printf("Menghapus elemen Q4\n");
    dequeue3(&Q4, &E);
    printf("Q4: ");
    printQueue3(Q4);
    printf("\n");
    printf("Menguji kembali fungsi head3, tail3, infohead3, infotail3 dan sizeQueue3\n");
    printf("Head Q4: %d\n", head3(Q4));
    printf("Tail Q4: %d\n", tail3(Q4));
    printf("InfoHead Q4: %c\n", infoHead3(Q4));
    printf("InfoTail Q4: %c\n", infoTail3(Q4));
    printf("Size Q4: %d\n", sizeQueue3(Q4));

    printf("Menambahkan elemen saat Q4 mencapai tail = 5\n");
    enqueue3(&Q4, 'F');
    printf("Q4: ");
    printQueue3(Q4);
    printf("\n");
    printf("Menguji kembali fungsi head3, tail3, infohead3, infotail3 dan sizeQueue3\n");
    printf("Head Q4: %d\n", head3(Q4));
    printf("Tail Q4: %d\n", tail3(Q4));
    printf("InfoHead Q4: %c\n", infoHead3(Q4));
    printf("InfoTail Q4: %c\n", infoTail3(Q4));
    printf("Size Q4: %d\n", sizeQueue3(Q4));

    printf("================== Testing fungsi EKSTRA ===================\n");
    printf("createQueue3(&Q5)\n");
    createQueue3(&Q5);
    printf("Q5: ");
    printQueue3(Q5);
    printf("\n");
    printf("Mengisi Q5 dengan 'A', 'A', 'B', 'B', 'C'\n");
    enqueue3(&Q5, 'A');
    enqueue3(&Q5, 'A');
    enqueue3(&Q5, 'B');
    enqueue3(&Q5, 'B');
    enqueue3(&Q5, 'C');
    printf("Q5: ");
    printQueue3(Q5);
    printf("\n");
    printf("Menguji fungsi countMember\n");
    printf("Jumlah elemen 'A' di Q5: %d\n", countMember(Q5, 'A'));
    printf("Jumlah elemen 'B' di Q5: %d\n", countMember(Q5, 'B'));
    printf("Jumlah elemen 'C' di Q5: %d\n", countMember(Q5, 'C'));
    printf("Jumlah elemen 'D' di Q5: %d\n", countMember(Q5, 'D'));

    printf("Menguji fungsi isTailOverHead\n");
    printf("Q5: ");
    printQueue3(Q5);
    printf("\n");
    printf("Apakah tail berada di depan head? %s\n", isTailOverHead(Q5) ? "Iya" : "Tidak");
    printf("Melakukan operasi agar tail berada di depan head\n");
    dequeue3(&Q5, &E);
    printf("Menghapus elemen %c\n", E);
    dequeue3(&Q5, &E);
    printf("Menghapus elemen %c\n", E);
    printf("Q5: ");
    printQueue3(Q5);
    printf("\n");
    printf("Menambahkan elemen 'D' ke Q5\n");
    enqueue3(&Q5, 'D');
    printf("Q5: ");
    printQueue3(Q5);
    printf("\n");
    printf("Head Q5: %d\n", head3(Q5));
    printf("Tail Q5: %d\n", tail3(Q5));
    printf("InfoHead Q5: %c\n", infoHead3(Q5));
    printf("InfoTail Q5: %c\n", infoTail3(Q5));
    printf("Apakah tail berada di depan head? %s\n", isTailOverHead(Q5) ? "Iya" : "Tidak");
    printf("Menguji fungsi enqueue3E\n");
    printf("Q5: ");
    printQueue3(Q5);
    printf("\n");
    printf("Menambahkan elemen 'E' ke Q5\n");
    enqueue3E(&Q5, 'E');
    printf("Q5: ");
    printQueue3(Q5);
    printf("\n");
    printf("Menghapus elemen %c\n", E);
    dequeue3(&Q5, &E);
    printf("Q5: ");
    printQueue3(Q5);
    printf("\n");
    printf("Menambahkan elemen 'E' ke Q5\n");
    enqueue3E(&Q5, 'E');
    printf("Q5: ");
    printQueue3(Q5);
    printf("\n");
    printf("Tidak bisa menambahkan elemen 'E' ke Q5, karena 'E' sudah ada.\n");

    printf("================== Menguji printQueue3 dan viewQueue3 ====================\n");
    printf("Menampilkan Q5 dengan printQueue3\n");
    printf("Sesuai dengan kesepakatan dikelas, Elemen ditampilkan dari head ke tail, lalu yang kosong ditampilkan setelahnya\n");
    printf("Q5: ");
    printQueue3(Q5);
    printf("\n");
    printf("Menampilkan Q5 dengan viewQueue3\n");
    printf("Q5: ");
    viewQueue3(Q5);
    printf("\n");
    printf("Dalam kasus Q6 adalah antrian kosong\n");
    printf("createQueue3(&Q6)\n");
    createQueue3(&Q6);
    printf("Menampilkan Q6 dengan printQueue3\n");
    printf("Q6: ");
    printQueue3(Q6);
    printf("\n");
    printf("Menampilkan Q6 dengan viewQueue3\n");
    printf("Q6: ");
    viewQueue3(Q6);
    printf("\n");
    printf("Dengan viewQueue3, elemen yang kosong tidak ditampilkan\n");
    return 0;
}