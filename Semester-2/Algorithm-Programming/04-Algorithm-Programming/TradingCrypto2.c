//Nama File         : TradingCrypto.c
//Deskripsi         : program untuk melakukan transaksi seminimal mungkin dari harga yang ada di tabel
//Pembuat           : Khoirul Nasid Furqon-24060123120042
//Tanggal Pembuatan : 20-03-2024

#include <stdio.h>
#include <stdlib.h>

int main(){
    //Kamus
    int N;
    int max;
    int h1;
    int h2;

    //Algoritma
    printf("Masukkan panjang Tabel : ");
    scanf("%d", &N);
    int T[N];

    for (int i = 0; i < N; i++) //perulangan untuk mengisi nilai elemen yang ada di tabel
    {
        printf("Nilai elemen ke %d : ", i+1);
        scanf("%d", &T[i]);
    }

    max = 0; // mengisialisasi nilai max = 0
    for (int i = 0; i < N; i++){ //  melakukan perulangan untuk mendapatkan elemen di hari ini
    
    for (int j = i+1; j < N; j++){ // melakukan perulangan untuk mendapatkan elemen di masa depan
      if (T[j] - T[i] > max){ // melakukan pengurangan antara nilai elemen masa depan dengan hari ini, lalu dibandingkan dengan nilai max
        max = T[j] - T[i]; // mengurangi elemen masa depan dengan elemen masa kini
        h1 = i; // merubah nilai h1 menjadi i
        h2 = j; // merubah nilai h2 menjadi j
      }
    }

    }
    if(max == 0){
      printf("Tidak bisa mendapatkan keuntungan :(");
    }
      else{
      printf("Beli di hari ke-%d dan jual di hari ke-%d dengan keuntungan sebesar %d",h1+1 ,h2+1, max);
    }

    return 0;
}