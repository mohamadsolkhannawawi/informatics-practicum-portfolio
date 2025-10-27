/* Nama File  : PesananKafe.c */
/* Deskripsi  : Mengecek dan menampilkan di layar serangkaian algoritma pemesanan menggunakan tipe query yang di inputkan*/
/* NIM & Nama : 24060123120020 & Mohamad Solkhan Nawawi*/
/* Tanggal    : 21 Maret 2024*/

#include <stdio.h>
#include <string.h>

int main() {
    int query_type; // menentukan tipe query yang akan di gunakan
    int num_orders; // menyimpan jumlah yang sudah di pesan
    int count; // menghitung jumlah pesanan
    int i; // counter
    const int MAX_NAME_LENGTH = 11; // batas jumlah karakter nama pemesan + Null
    const int MAX_ORDERS = 15; // batas maksimum order 
    char orders[MAX_ORDERS][MAX_NAME_LENGTH]; // array 2 dimensi untuk menyimpan nama pesanan
    int completed[MAX_ORDERS]; // menandai pesanan sudah selesai atau belum
    char new_order[MAX_NAME_LENGTH]; // menyimpan nama pesanan yang baru di inputkan

    int n; // jumlah query yang akan di inputkan
    printf("Masukkan jumlah query: ");
    scanf("%d", &n);

    num_orders = 0;
    for (i = 0; i < n; i++) {
        printf("Query %d: ", i + 1);
        scanf("%d", &query_type);
        if (query_type == 1) {
            scanf("%s", new_order);
            if (num_orders >= MAX_ORDERS) {
                printf("Maaf, kami sudah tidak mampu menampung pesanan lagi :(\n");
            }
            strcpy(orders[num_orders], new_order);
            completed[num_orders] = 0;
            num_orders++;
        } else if (query_type == 2) {
            if (num_orders == 0) {
                printf("Tidak terdapat pesanan OwO\n");
            } else {
                printf("Pesanan atas nama %s sudah selesai! ^^\n", orders[0]);
                // Geser antrian ke depan
                for (i = 0; i < num_orders - 1; i++) {
                    strcpy(orders[i], orders[i + 1]);
                    completed[i] = completed[i + 1];
                }
            }
            num_orders--;
        } else if (query_type == 3) {
            count = 0;
            for (i = 0; i < num_orders; i++) {
                if (completed[i] == 0) {
                    count++;
                }
            }
            if (count == 0) {
                printf("Kerja bagus, sudah tidak ada pesanan!\n");
            } else {
                printf("Ayo semangat, masih terdapat %d pesanan yang harus dikerjakan!\n", count);
            }
        }
    }

    return 0;
}
