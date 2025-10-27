/* Nama File  : MencariStokBarang.c */
/* Deskripsi  : Mencari stok ukuran sepatu yang sesuai, jika tidak ada diberikan
ukuran yang sepatu terkecil yang lebih besar dari yang di inginkan, jika ukuran sepatu
yang diminta melebihi maka berikan ukuran sepatu terbesar yang di miliki.*/
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 16 Mei 2024*/

#include <stdio.h>
#include <stdbool.h>

void mencariUkuranSepatu() {
    // Kamus lokal
    int stok;
    int pelanggan;
    int i;
    int kiri, kanan, tengah;
    bool ketemu;

    //Algoritma
    printf("Masukkan jumlah sepatu dalam stok: ");
    scanf("%d", &stok);

    int ukuran[stok];

    printf("Masukkan ukuran sepatu (terurut): ");
    for (i = 0; i < stok; i++) {
        scanf("%d", &ukuran[i]);
    }

    printf("Masukkan jumlah pelanggan: ");
    scanf("%d", &pelanggan);

    int permintaan[pelanggan];

    printf("Masukkan ukuran sepatu yang diminta: ");
    for (i = 0; i < pelanggan; i++) {
        scanf("%d", &permintaan[i]);
    }

    for (i = 0; i < pelanggan; i++) {
        kiri = 0;
        kanan = stok - 1;
        ketemu = false;

        while (kiri <= kanan && !ketemu) {
            tengah = (kiri + kanan) / 2;

            if (permintaan[i] == ukuran[tengah]) {
                ketemu = true;
            } else if (permintaan[i] < ukuran[tengah]) {
                kanan = tengah - 1;
            } else {
                kiri = tengah + 1;
            }
        }

        if (ketemu) {
            printf("%d\n", ukuran[tengah]);
        } else if (kanan == -1) {
            printf("%d\n", ukuran[0]);
        } else if (kiri > kanan && tengah != stok - 1) {
            printf("%d\n", ukuran[tengah + 1]);
        } else {
            printf("%d\n", ukuran[stok - 1]);
        }
    }
}

int main() {
    mencariUkuranSepatu();
    return 0;
}
