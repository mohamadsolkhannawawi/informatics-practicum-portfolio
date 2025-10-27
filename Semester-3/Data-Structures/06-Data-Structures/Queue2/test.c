#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 100 // Ukuran maksimum dari queue

typedef struct {
    char wadah[MAX_SIZE]; // Array untuk menyimpan elemen
    int head;             // Indeks elemen pertama
    int tail;             // Indeks elemen terakhir
} tqueue2;

// Fungsi untuk memeriksa apakah queue kosong
bool isEmptyQueue2(tqueue2 Q) {
    return (Q.head > Q.tail);
}

// Fungsi untuk menambahkan elemen ke queue
void addQueue2(tqueue2* Q, char elemen) {
    if (Q->tail < MAX_SIZE - 1) {
        Q->wadah[++(Q->tail)] = elemen;
    }
}

// Fungsi untuk menghapus elemen dari queue (head)
char delQueue2(tqueue2* Q) {
    if (!isEmptyQueue2(*Q)) {
        return Q->wadah[(Q->head)++];
    }
    return '\0'; // Kembalikan karakter null jika queue kosong
}

// Fungsi untuk menghapus elemen dari indeks tertentu
void delQueueAtIndex(tqueue2* Q, int index) {
    for (int i = index; i < Q->tail; i++) {
        Q->wadah[i] = Q->wadah[i + 1]; // Geser elemen ke kiri
    }
    Q->tail--; // Kurangi tail
}

// Fungsi untuk membandingkan dua queue
bool isEqualQueue2(tqueue2 Q1, tqueue2 Q2) {
    // Kamus Lokal
    int i, j;
    bool found;
    tqueue2 TempQ1, TempQ2; // Queue sementara untuk perbandingan

    // Inisialisasi TempQ1 dan TempQ2 sebagai salinan dari Q1 dan Q2
    TempQ1.head = 0;
    TempQ1.tail = -1; // Queue kosong
    TempQ2.head = 0;
    TempQ2.tail = -1; // Queue kosong

    // Salin semua elemen dari Q1 ke TempQ1
    for (i = Q1.head; i <= Q1.tail; i++) {
        addQueue2(&TempQ1, Q1.wadah[i]);
    }

    // Salin semua elemen dari Q2 ke TempQ2
    for (i = Q2.head; i <= Q2.tail; i++) {
        addQueue2(&TempQ2, Q2.wadah[i]);
    }

    // Algoritma
    // Periksa setiap elemen di TempQ1 apakah ada di TempQ2
    while (!isEmptyQueue2(TempQ1)) {
        char elemenQ1 = delQueue2(&TempQ1); // Ambil elemen dari TempQ1
        found = false;

        // Cek apakah elemenQ1 ada di TempQ2
        for (i = TempQ2.head; i <= TempQ2.tail; i++) {
            if (TempQ2.wadah[i] == elemenQ1) {
                found = true;
                // Hapus elemen dari TempQ2
                delQueueAtIndex(&TempQ2, i); // Hapus elemen dari indeks i
                break;
            }
        }

        if (!found) {
            return false; // Jika elemen tidak ditemukan di TempQ2, queue tidak sama
        }
    }

    // Pastikan TempQ2 kosong setelah semua elemen dibandingkan
    return isEmptyQueue2(TempQ2);
}

// Contoh penggunaan
int main() {
    tqueue2 Q4, Q5;

    // Inisialisasi queue Q4 dan Q5
    Q4.head = 0; Q4.tail = -1;
    Q5.head = 0; Q5.tail = -1;

    // Menambahkan elemen A, B, C ke Q4
    addQueue2(&Q4, 'A');
    addQueue2(&Q4, 'B');
    addQueue2(&Q4, 'C');

    // Menambahkan elemen C, B, A ke Q5
    addQueue2(&Q5, 'C');
    addQueue2(&Q5, 'B');
    addQueue2(&Q5, 'A');

    // Mengecek apakah Q4 dan Q5 isEqualQueue
    if (isEqualQueue2(Q4, Q5)) {
        printf("Q4 dan Q5 sama.\n");
    } else {
        printf("Q4 dan Q5 tidak sama.\n");
    }

    return 0;
}
