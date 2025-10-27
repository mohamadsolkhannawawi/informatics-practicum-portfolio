// Angka kuat adalah sebuah angka dimana jumlah faktorial dari digit-digitnya
// sama dengan angka itu sendiri.
// Sebagai contoh, 145 adalah angka kuat, karena 1! + 4! + 5! = 1 + 24 + 120 = 145.
// Tugas Diberikan sebuah angka positif, temukan apakah angka tersebut termasuk angka kuat
// atau tidak, dan print "KUAT" atau "lemah".

// Contoh 1 adalah angka kuat, karena 1! = 1, sehingga print "KUAT". 
// 123 bukanlah angka kuat, karena 1! + 2! + 3! = 9 tidak sama dengan 123, 
// sehingga kembalikan "lemah".


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    // Kamus
    int i ; // Counter
    int n; // Angka yang akan diperiksa
    int asli; // Menyimpan n asli
    int sisa; // Menyimpan sisa pembagian n dengan 10
    int total; // Menyimpan jumlah faktorial
    int faktorial; // Menyimpan hasil faktorial

    // Membaca masukan n
    scanf("%d", &n);

    // Algoritma
    asli = n;
    while (n != 0) {
        sisa = n % 10; // Mengambil digit terakhir dari n
        faktorial = 1;
        for (i = 1; i <= sisa; i++) {
            faktorial *= i;
        }
        total += faktorial;
        n /= 10; // Menghapus digit terakhir dari n
    }

    // Memeriksa apakah jumlah faktorial sama dengan n asli
    if (total == asli) {
        printf("KUAT");
    } else {
        printf("lemah");
    }

    return 0;
}

//Input: 1
//Output: KUAT
//Input: 123
//Output: lemah
//Input: 145
//Output: KUAT
//Input: 999
//Output: lemah
//Input: 40585
//Output: KUAT
//Input: 44
//Output: lemah