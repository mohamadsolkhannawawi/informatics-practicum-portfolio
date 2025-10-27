/* Nama File  : TradingCrypto.c */
/* Deskripsi  : Mengecek dan menampilkan di layar keuntungan maksimum yang bisa diperoleh ketika membeli crypto.*/
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 21 Maret 2024*/

#include <stdio.h>

int main() {
    //Kamus
    int i, j; // counter
    int n; // jumlah hari
    printf("=================== Trading Crypto =====================\n\n");
    printf("Masukkan jumlah hari: ");
    scanf("%d", &n);
    int prices[n]; // harga crypto

    int max_profit; // keuntungan maksimum
    int buy_day; // hari beli
    int sell_day; // hari jual

    //Algoritma
    printf("\n========================================================\n\n");
    if (n < 2) {
        printf("Harga crypto harus berisi minimal 2 hari untuk membandingkan keuntungan.\n");
    } else {
        printf("Masukkan harga crypto setiap harinya: \n");
        for (i = 0; i < n; i++) {
            printf("Hari ke-%d: ", i + 1);
            scanf("%d", &prices[i]);
        }

        max_profit = 0;
        for (i = 0; i < n; i++){ 
            for (j = i+1; j < n; j++){ 
                if (prices[j] - prices[i] > max_profit){ 
                    max_profit = prices[j] - prices[i]; 
                    buy_day = i;
                    sell_day = j;
                }
            }
        }

        printf("\n========================================================\n\n");

        if (max_profit > 0) {
            printf("Beli di hari ke-%d dan jual di hari ke-%d dengan keuntungan sebesar %d\n", buy_day + 1, sell_day + 1, max_profit);
        } else {
            printf("Tidak bisa mendapatkan keuntungan :(\n");
        }
    }
    printf("\n========================================================\n");

    return 0;
}
