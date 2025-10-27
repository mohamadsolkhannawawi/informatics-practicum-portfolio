/* Program   : tqueue3.c */
/* Deskripsi : Body realisasi ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060123120020/Mohamad Solkhan Nawawi*/
/* Tanggal   : Jumat, 4 Oktober 2024*/
/***********************************/

#include "tqueue3.h"
#include <stdio.h>

/*function isEmptyQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue3(tqueue3 Q) {
    return (Q.head == 0 && Q.tail == 0);
}

/*function isFullQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue3(tqueue3 Q) {
    return (Q.head == 1 && Q.tail == 5) || (Q.head == Q.tail + 1);
}

/*function isOneElement3(Q:tQueue3) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement3(tqueue3 Q) {
    if (!isEmptyQueue3(Q)) {
        return (Q.head == Q.tail);
    } else {
        return false;
    }
}

/*procedure createQueue3 ( output Q:tQueue3)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='#'}*/ 
void createQueue3(tqueue3 *Q) {
    //Kamus Lokal
    int i;
    //Algoritma
    for (i = 1; i <= 5; i++) {
        (*Q).wadah[i] = '#';
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

/*Function Head3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terdepan} */
int head3(tqueue3 Q) {
    return Q.head;
}

/*Function Tail3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terakhir} */
int tail3(tqueue3 Q) {
    return Q.tail;
}

/*Function InfoHead3(Q:tqueue3) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead3(tqueue3 Q) {
    if (!isEmptyQueue3(Q)) {
        return Q.wadah[head3(Q)];
    } else {
        return '@';
    }
}

/*Function InfoTail3(Q:tqueue3) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail3(tqueue3 Q) {
    if (!isEmptyQueue3(Q)) {
        return Q.wadah[tail3(Q)];
    } else {
        return '@';
    }
}

/*function sizeQueue3(Q:tQueue3)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue3(tqueue3 Q) {
    if (isEmptyQueue3(Q)) {
        return 0;
    } else {
        if (isOneElement3(Q)) {
            return 1;
        } else {
            if (head3(Q) < tail3(Q)) {
                return tail3(Q) - head3(Q) + 1;
            } else {
                return 6 - head3(Q) + tail3(Q);
            }
        }
    }
}

/*procedure printQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak isi wadah ke layar, berisi atau kosong}*/
//Kesepakatan di kelas, elemen diprint mulai dari head hingga tail, lalu sisanya '#
void printQueue3(tqueue3 Q) {
    //Kamus Lokal
    int i;
    //Algoritma
    if (!isEmptyQueue3(Q)) {
        for (i = head3(Q); i <= 5; i++) {
            printf("%c ", Q.wadah[i]);
        }
        for (i = 1; i < head3(Q); i++) {
            printf("%c ", Q.wadah[i]);
        }
    } else {
        for (i = 1; i <= 5; i++) {
            printf("%c ", Q.wadah[i]);
        }   
    }
}

/*procedure viewQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
//Kesepakatan di kelas, elemen diview mulai dari head hingga tail
void viewQueue3(tqueue3 Q) {
    //Kamus Lokal
    int i;
    //Algoritma
    if (!isEmptyQueue3(Q)) {
        if (head3(Q) < tail3(Q)) {
            for (i = head3(Q); i <= tail3(Q); i++) {
                printf("%c ", Q.wadah[i]);
            }
        } else {
            for (i = head3(Q); i <= 5; i++) {
                printf("%c ", Q.wadah[i]);
            }
            for (i = 1; i <= tail3(Q); i++) {
                printf("%c ", Q.wadah[i]);
            }
        }
    }
}

/*procedure enQueue3( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 } */
void enqueue3(tqueue3 *Q, char E) {
    // Kamus Lokal
    // Algoritma
    if (!isFullQueue3(*Q)) {
        if (isEmptyQueue3(*Q)) {
            (*Q).head = 1;
            (*Q).tail = 1;
        } else {
            if ((*Q).tail == 5) {
                (*Q).tail = 1;
            } else {
                (*Q).tail++;
            }
        }
        (*Q).wadah[tail3(*Q)] = E;
    }
}

/*procedure deQueue3( input/output Q:tQueue3,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q), bila kosong E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue3(tqueue3 *Q, char *E) {
    //Kamus Lokal
    //Algoritma
    if (!isEmptyQueue3(*Q)) {
        *E = (*Q).wadah[head3(*Q)];
        if (isOneElement3(*Q)) {
            (*Q).wadah[head3(*Q)] = '#';
            (*Q).head = 0;
            (*Q).tail = 0;
        } else {
            if ((*Q).head == 5) {
                (*Q).wadah[head3(*Q)] = '#';
                (*Q).head = 1;    
            } else {
                (*Q).wadah[head3(*Q)] = '#';
                (*Q).head++;
            }
        }
    } else {
        *E = '@';
    }
}

/*EKSTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*function isTailOverHead(Q:tQueue3) -> boolean
{mengembalikan true jika tail berada di depan head}*/
boolean isTailOverHead(tqueue3 Q) {
    return (Q.head > Q.tail);
}

/*function countMember(Q:tQueue3, E:character) -> integer
{mengembalikan banyaknya nilai E dalam antrian Q}*/
int countMember(tqueue3 Q, char E) {
    //Kamus Lokal
    int i, count;
    //Algoritma
    count = 0;
    if (head3(Q) < tail3(Q)) {
        for (i = head3(Q); i <= tail3(Q); i++) {
            if (Q.wadah[i] == E) {
                count++;
            }
        }
    } else {
        for (i = head3(Q); i <= 5; i++) {
            if (Q.wadah[i] == E) {
                count++;
            }
        }
        for (i = 1; i <= tail3(Q); i++) {
            if (Q.wadah[i] == E) {
                count++;
            }
        }
    }
    return count;
}

/*procedure enQueue3E( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh dan E belum ada di Q}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 dengan syarat nilai E belum ada di Q} */
void enqueue3E(tqueue3 *Q, char E) {
    // Kamus Lokal
    if (!isFullQueue3(*Q)) {
        if (isEmptyQueue3(*Q)) {
            (*Q).head = 1;
            (*Q).tail = 1;
        } else {
            if (countMember(*Q, E) == 0) {
                if ((*Q).tail == 5) {
                    (*Q).tail = 1;
                } else {
                    (*Q).tail++;
                }
            }
        }
        (*Q).wadah[tail3(*Q)] = E;
    }
}