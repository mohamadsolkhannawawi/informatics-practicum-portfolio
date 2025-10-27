#include "tqueue2.h"
#include <stdio.h>

/*function isEqualQueue2(Q1:tQueue2, Q2:tQueue2) -> boolean
{mengembalikan true jika Q1 dan Q2 memiliki elemen yang sama} */
boolean isEqualQueue2(tqueue2 Q1, tqueue2 Q2) {
    // Kamus Lokal
    tqueue2 TempQ1, TempQ2; // Queue sementara untuk perbandingan
    char elemenQ1;
    boolean found;
    
    // Membuat salinan dari Q1 dan Q2
    createQueue2(&TempQ1);
    createQueue2(&TempQ2);
    
    // Menyalin elemen dari Q1 ke TempQ1
    for (int i = head2(Q1); i <= tail2(Q1); i++) {
        enqueue2(&TempQ1, Q1.wadah[i]);
    }

    // Menyalin elemen dari Q2 ke TempQ2
    for (int i = head2(Q2); i <= tail2(Q2); i++) {
        enqueue2(&TempQ2, Q2.wadah[i]);
    }

    // Algoritma
    while (!isEmptyQueue2(TempQ1)) {
        elemenQ1 = infoHead2(TempQ1); // Ambil elemen dari TempQ1
        found = false;

        // Cek apakah elemenQ1 ada di TempQ2
        for (int i = head2(TempQ2); i <= tail2(TempQ2); i++) {
            if (TempQ2.wadah[i] == elemenQ1) {
                found = true;
                // Hapus elemen dari TempQ2
                TempQ2.wadah[i] = '#'; // Tandai elemen yang sudah ditemukan
                break;
            }
        }

        if (!found) {
            return false; // Jika elemen tidak ditemukan di TempQ2, queue tidak sama
        }

        dequeue2(&TempQ1, &elemenQ1); // Hapus elemen yang telah diproses dari TempQ1
    }

    // Pastikan tidak ada elemen tersisa di TempQ2
    for (int i = head2(TempQ2); i <= tail2(TempQ2); i++) {
        if (TempQ2.wadah[i] != '#') {
            return false; // Jika ada elemen yang tersisa, berarti tidak sama
        }
    }

    return true; // Kedua queue memiliki elemen yang sama
}
