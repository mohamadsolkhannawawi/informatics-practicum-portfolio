#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CAPACITY 10
#define TOTAL_CHARACTERS 20

typedef struct {
    char nama[20];
    int damage;
    int health;
    bool aktif;  // True jika masih aktif
} karakter;

typedef struct {
    karakter wadah[MAX_CAPACITY + 1]; // kapasitas 10 elemen (index 1 sampai 10)
    int head;
    int tail;
} tqueue3;

// Inisialisasi antrian
void initQueue(tqueue3 *Q) {
    Q->head = 0;
    Q->tail = 0;

    // Inisialisasi semua karakter sebagai kosong
    for (int i = 1; i <= MAX_CAPACITY; i++) {
        strcpy(Q->wadah[i].nama, ""); // Set nama menjadi string kosong
        Q->wadah[i].damage = 0;        // Set damage ke 0
        Q->wadah[i].health = 0;        // Set health ke 0
        Q->wadah[i].aktif = false;     // Set status menjadi tidak aktif
    }
}

// Cek apakah antrian kosong
bool isEmpty(tqueue3 *Q) {
    return Q->head == 0 && Q->tail == 0;
}

// Cek apakah antrian penuh
bool isFull(tqueue3 *Q) {
    return (Q->tail + 1) % (MAX_CAPACITY + 1) == Q->head;
}

// Tambahkan karakter ke antrian
void enqueue(tqueue3 *Q, karakter k) {
    if (isFull(Q)) {
        printf("Antrian penuh!\n");
        return;
    }
    if (isEmpty(Q)) {
        Q->head = 1;  // Set head ke 1 saat menambahkan elemen pertama
    }
    Q->tail = (Q->tail % MAX_CAPACITY) + 1;  // Update tail
    Q->wadah[Q->tail] = k; // Masukkan karakter ke antrian
}

// Hapus karakter dari antrian
void dequeue(tqueue3 *Q) {
    if (isEmpty(Q)) {
        printf("Antrian kosong!\n");
        return;
    }
    // Jika hanya ada satu elemen
    if (Q->head == Q->tail) {
        initQueue(Q); // Reset queue jika hanya ada satu elemen
    } else {
        Q->head = (Q->head % MAX_CAPACITY) + 1; // Pindahkan head ke depan
    }
}

// Tampilkan antrian dengan urutan 1 hingga 10
void displayQueueWithOrder(tqueue3 *Q) {
    printf("Daftar karakter dalam antrian (1-10):\n");

    // Menghitung panjang antrian
    int index = Q->head;
    for (int j = 1; j <= MAX_CAPACITY; j++) {
        if (index != (Q->tail + 1) % (MAX_CAPACITY + 1)) {
            karakter k = Q->wadah[index];
            // Memeriksa apakah karakter aktif dan menampilkan informasi yang sesuai
            if (k.aktif) {
                printf("%d. Nama: %s, Damage: %d, Health: %d, Status: Aktif\n", 
                       j, k.nama, k.damage, k.health);
            } else {
                printf("%d. Belum ada isi karakternya!\n", j);
            }
        }
        index = (index % MAX_CAPACITY) + 1; // Pindahkan indeks ke depan
    }
}

// Tampilkan karakter yang disediakan oleh sistem
void displayAvailableCharacters(karakter *all_characters) {
    printf("Daftar karakter yang tersedia:\n");
    for (int i = 0; i < TOTAL_CHARACTERS; i++) {
        printf("%d. Nama: %s, Damage: %d, Health: %d\n", 
               i + 1, all_characters[i].nama, all_characters[i].damage, all_characters[i].health);
    }
}

// Fungsi untuk memulai pertempuran
void battle(tqueue3 *Q) {
    if (isEmpty(Q)) {
        printf("Antrian kosong, tidak ada pertempuran.\n");
        return;
    }
    
    printf("Pertempuran dimulai!\n");
    int headIndex = Q->head;
    
    // Iterasi dari head hingga tail
    while (headIndex != (Q->tail + 1) % (MAX_CAPACITY + 1)) {
        if (Q->wadah[headIndex].aktif) {
            int attackerIndex = (headIndex + 1) % (MAX_CAPACITY + 1);
            // Setiap karakter setelah head menyerang head
            while (attackerIndex != (Q->tail + 1) % (MAX_CAPACITY + 1)) {
                if (Q->wadah[attackerIndex].aktif) {
                    Q->wadah[headIndex].health -= Q->wadah[attackerIndex].damage;
                    printf("%s menyerang %s! Sisa health %s: %d\n", 
                           Q->wadah[attackerIndex].nama, Q->wadah[headIndex].nama, 
                           Q->wadah[headIndex].nama, Q->wadah[headIndex].health);
                    // Cek jika head kalah
                    if (Q->wadah[headIndex].health <= 0) {
                        Q->wadah[headIndex].aktif = false;
                        printf("%s telah kalah!\n", Q->wadah[headIndex].nama);
                        break;
                    }
                }
                attackerIndex = (attackerIndex + 1) % (MAX_CAPACITY + 1);
            }
        }
        headIndex = (headIndex + 1) % (MAX_CAPACITY + 1);
    }
    
    // Cek pemenang
    printf("Pertempuran selesai!\n");
}

// Menghitung jumlah elemen dalam antrian
int countElements(tqueue3 *Q) {
    if (isEmpty(Q)) {
        return 0; // Jika antrian kosong, jumlah elemen adalah 0
    }

    int count = 0;
    int index = Q->head;

    // Menghitung jumlah elemen dari head hingga tail
    while (index != (Q->tail + 1) % (MAX_CAPACITY + 1)) {
        if (Q->wadah[index].aktif) {
            count++; // Hanya menghitung elemen yang aktif
        }
        index = (index + 1) % (MAX_CAPACITY + 1); // Pindah ke elemen berikutnya
    }

    return count; // Mengembalikan jumlah elemen yang dihitung
}


// Menu utama
void menu() {
    printf("Menu:\n");
    printf("1. Tambah karakter\n");
    printf("2. Hapus karakter\n");
    printf("3. Pertempuran\n");
    printf("4. Tampilkan antrian\n");
    printf("5. Keluar\n");
}

int main() {
    tqueue3 Q;
    initQueue(&Q);

    karakter all_characters[TOTAL_CHARACTERS] = {
        {"Char1", 20, 100, true}, {"Char2", 30, 120, true}, {"Char3", 25, 150, true}, 
        {"Char4", 40, 70, true}, {"Char5", 10, 90, true}, {"Char6", 20, 110, true}, 
        {"Char7", 30, 95, true}, {"Char8", 35, 105, true}, {"Char9", 45, 120, true}, 
        {"Char10", 55, 130, true}, {"Char11", 40, 70, true}, {"Char12", 10, 90, true},
        {"Char13", 20, 110, true}, {"Char14", 30, 95, true}, {"Char15", 35, 105, true},
        {"Char16", 45, 120, true}, {"Char17", 55, 130, true}, {"Char18", 40, 70, true},
        {"Char19", 10, 90, true}, {"Char20", 20, 110, true}
    };

    int pilihan;

    do {
        menu();
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1: {
                karakter k;
                displayAvailableCharacters(all_characters);
                printf("Pilih karakter untuk ditambahkan (1-20): ");
                int choice;
                scanf("%d", &choice);
                if (choice < 1 || choice > TOTAL_CHARACTERS) {
                    printf("Pilihan tidak valid!\n");
                } else {
                    k = all_characters[choice - 1];
                    enqueue(&Q, k);
                    printf("%s telah ditambahkan ke antrian!\n", k.nama);
                }
                break;
            }
            case 2:
                dequeue(&Q);
                break;
            case 3:
                battle(&Q);
                break;
            case 4:
                displayQueueWithOrder(&Q);
                break;
            case 5:
                printf("Keluar...\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    } while (pilihan != 5);

    return 0;
}
