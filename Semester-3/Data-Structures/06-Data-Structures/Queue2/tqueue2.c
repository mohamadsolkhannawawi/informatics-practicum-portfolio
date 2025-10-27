/* Program   : tqueue2.c */
/* Deskripsi : Body realisasi untuk ADT Queue 2, 
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060123120020/Mohamad Solkhan Nawawi*/
/* Tanggal   : Jumat, 4 Oktober 2024*/
/***********************************/

// Include header file
#include "tqueue2.h"
#include <stdio.h>

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q) {
    // Algoritma
    return (Q.head == 0 && Q.tail == 0);
}

/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q) {
    // Algoritma
    return (Q.head == 1 && Q.tail == 5);
}

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q) {
    // Algoritma
    if (!isEmptyQueue2(Q)) {
        return (Q.head == Q.tail);
    } else {
        return false;
    }
}

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi head dan tail dengan 0, elemen kosong='#'}*/ 
void createQueue2(tqueue2 *Q) {
    // Kamus Lokal
    int i;
    // Algoritma
    for (i = 1; i <= 5; i++) {
        (*Q).wadah[i] = '#';
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head2(tqueue2 Q) {
    // Algoritma
    return Q.head;
}

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail2(tqueue2 Q) {
    // Algoritma
    return Q.tail;
}

/*Function InfoHead2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead2(tqueue2 Q) {
    // Algoritma
    if (!isEmptyQueue2(Q)) {
        return Q.wadah[head2(Q)];
    } else {
        return '@';
    }
}

/*Function InfoTail2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail2(tqueue2 Q) {
    // Algoritma
    if (!isEmptyQueue2(Q)) {
        return Q.wadah[tail2(Q)];
    } else {
        return '@';
    }
}

/*function sizeQueue2(Q:tQueue2)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q) {
    if (!isEmptyQueue2(Q)) {
        return tail2(Q) - head2(Q) + 1;
    } else {
        return 0;
    }
}

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
//Kesepakatan di kelas
{proses: mencetak semua isi wadah ke layar, mulai dari head hingga tail, lalu sisanya di tampilkan '#'}*/
void printQueue2(tqueue2 Q) {
    // Kamus Lokal
    int i;
    // Algoritma
    if (head2(Q) > 1) {
        for (i = head2(Q); i <= 5; i++) {
            printf("%c ", Q.wadah[i]);
        }
        for (i = 1; i < head2(Q); i++) {
            printf("%c ", Q.wadah[i]);
        }
    } else {
        for (i = 1; i <= 5; i++) {
            printf("%c ", Q.wadah[i]);
        }
    }
}

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q) {
    // Kamus Lokal
    int i;
    // Algoritma
    if (!isEmptyQueue2(Q)) {
        for (i = head2(Q); i <= tail2(Q); i++) {
            printf("%c ", Q.wadah[i]);
        }
    }
}

/*Function IsTailStop(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop(tqueue2 Q) {
    return tail2(Q) == 5;
}

/*Procedure ResetHead(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead(tqueue2 *Q){
    //Kamus Lokal
    int i, temp;
    //Algoritma
    temp = head2(*Q)-1;
    if (isTailStop(*Q) && head2(*Q) > 1) {
        for (i = head2(*Q) ; i <= tail2(*Q); i++) {
            (*Q).wadah[i-temp] = (*Q).wadah[i];
            (*Q).wadah[i] = '#';
        }
        (*Q).head = 1;
        (*Q).tail = tail2(*Q)-temp;
    }
}

/*procedure enQueue2( input/output Q:tQueue2, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, char E) {
    // Kamus Lokal
    int i;
    // Algoritma
    if (!isFullQueue2(*Q)){
        if (isTailStop(*Q)){
            resetHead(Q);
        } else if (isEmptyQueue2(*Q)) {
            (*Q).head = head2(*Q) + 1;
        }
        (*Q).tail = tail2(*Q) + 1;
        (*Q).wadah[tail2(*Q)] = E;
    }
}

/*procedure deQueue2( input/output Q:tQueue2, output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
{proses: mengurangi elemen wadah Q, bila 1 elemen, 
maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, char *E){
    //Kamus Lokal
    int tempHead;
    //Algoritma
    if (isEmptyQueue2(*Q)){
        *E = '@';
    } else {
        *E = infoHead2(*Q);
        (*Q).wadah[head2(*Q)] = '#';
        if (isOneElement2(*Q)) {
            (*Q).head = 0;
            (*Q).tail = 0;
        } else {
            (*Q).head = head2(*Q)+1;
        }
    }
}

/*procedure enQueue2N( input/output Q:tQueue2, input N:integer )
{I.S.: Q terdefinisi, mungkin kosong, N <= kapasitas - panjang antrean}
{F.S.: elemen wadah Q bertambah <= N elemen bila belum penuh}
{proses: mengisi elemen dari keyboard, jika tail(Q) mencapai kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2N(tqueue2 *Q, int N){
    //Kamus Lokal
    int i;
    char E;
    //Algoritma
    if (N <= 5 - sizeQueue2(*Q)) {    
        for (i = 1; i <= N; i++) {
            if (isTailStop(*Q)){
                resetHead(Q);
            }
            printf("Masukan elemen ke %d ke dalam Queue : ", i);
            scanf(" %c", &E);
            enqueue2(Q, E);
        }
    }
}

/*EXTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*Function isEqualQueue2(Q1:TQueue2,Q2:TQueue2) -> boolean
{mengembalikan true jika Q1 dan Q2 berisi elemen yang sama}
{ingat, kondisi head Q1 dan Q2 mungkin tidak sama} */
// Asumsi panjang queue sama dan tidak kosong, elemen queue tidak ada yang sama
boolean isEqualQueue2(tqueue2 Q1,tqueue2 Q2){
    //Kamus Lokal
    int i, j, count;
    //Algoritma
    if (sizeQueue2(Q1) != sizeQueue2(Q2) && (isEmptyQueue2(Q1) && isEmptyQueue2(Q2))) {
        return false;
    } else {
        i = head2(Q1);
        j = head2(Q2);
        count = 0;
        while (i <= tail2(Q1) && j <= tail2(Q2)) {
            if (Q1.wadah[i] == Q2.wadah[j]) {
                count = count + 1;
            }
            i++;
            j++;
        }
        if (count == sizeQueue2(Q1)) {
            return true;
        }
    }
}