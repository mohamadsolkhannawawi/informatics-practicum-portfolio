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
        printf("Antrian penuh! Karakter tidak dapat ditambahkan.\n");
        return; // Keluar dari fungsi jika antrian penuh
    }
    if (isEmpty(Q)) {
        Q->head = 1;  // Set head ke 1 saat menambahkan elemen pertama
        Q->tail = 1;  // Set tail juga ke 1 saat menambahkan elemen pertama
    } else {
        Q->tail = (Q->tail % MAX_CAPACITY) + 1;  // Update tail secara sirkular
    }
    Q->wadah[Q->tail] = k; // Masukkan karakter ke antrian
    printf("Karakter %s berhasil ditambahkan ke dalam antrian.\n", k.nama); // Notifikasi karakter berhasil ditambahkan
}

// Hapus karakter dari antrian
// Hapus karakter dari antrian
void dequeue(tqueue3 *Q, karakter *E) {
    (*E) = Q->wadah[Q->head];
    if (isEmpty(Q)) {
        printf("Antrian kosong!\n");
        return;
    }

    // Nonaktifkan karakter di head
    Q->wadah[Q->head].aktif = false; 

    // Pindahkan head ke karakter aktif berikutnya
    while (!Q->wadah[Q->head].aktif) {
        Q->head = (Q->head % MAX_CAPACITY) + 1; // Pindahkan head ke depan

        // Jika head kembali ke posisi tail, berarti tidak ada karakter aktif
        if (Q->head == (Q->tail + 1) % (MAX_CAPACITY + 1)) {
            printf("Semua karakter sudah non-aktif. Antrian dikosongkan.\n");
            initQueue(Q); // Reset queue
            return;
        }
    }

    // Jika head kembali ke tail, reset queue
    if (Q->head == Q->tail) {
        initQueue(Q); // Reset queue jika hanya ada satu elemen
    }
}


// Tampilkan antrian dengan urutan 1 hingga 10 dan posisi head & tail
void displayQueueWithOrder(tqueue3 *Q) {
    printf("Daftar karakter dalam antrian (1-10):\n");

    for (int j = 1; j <= MAX_CAPACITY; j++) {
        karakter k = Q->wadah[j];

        // Memeriksa apakah karakter aktif dan menampilkan informasi yang sesuai
        if (k.aktif) {
            printf("%d. Nama: %s, Damage: %d, Health: %d, Status: Aktif", 
                   j, k.nama, k.damage, k.health);
        } else {
            printf("%d. Belum ada isi karakternya!", j);
        }

        // Tambahkan informasi jika itu posisi head atau tail
        if (j == Q->head) {
            printf(" (Head)");
        }
        if (j == Q->tail) {
            printf(" (Tail)");
        }
        printf("\n"); // Akhiri baris
    }
}

// Tampilkan daftar karakter yang disediakan oleh sistem
void displayAllCharacters(karakter all_characters[]) {
    printf("Daftar karakter yang tersedia:\n");
    for (int i = 0; i < TOTAL_CHARACTERS; i++) {
        printf("%d. Nama: %s, Damage: %d, Health: %d\n", 
               i + 1, all_characters[i].nama, all_characters[i].damage, all_characters[i].health);
    }
}

// Cek jika hanya satu karakter yang tersisa aktif
bool isOnlyOneActive(tqueue3 *Q) {
    int activeCount = 0;
    for (int i = 1; i <= MAX_CAPACITY; i++) {
        if (Q->wadah[i].aktif) {
            activeCount++;
        }
    }
    return activeCount == 1;
}

// Fungsi untuk pertempuran antar karakter, dengan statistik
void battle(tqueue3 *Q) {
    // Kamus Lokal
    karakter E;
    // Algoritma
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
                    int damage = Q->wadah[attackerIndex].damage;
                    Q->wadah[headIndex].health -= damage;
                    printf("%s menyerang %s! Sisa health %s: %d\n", 
                           Q->wadah[attackerIndex].nama, Q->wadah[headIndex].nama, 
                           Q->wadah[headIndex].nama, Q->wadah[headIndex].health);

                    // Statistik serangan
                    printf("Statistik: %s memberikan damage sebesar %d ke %s\n", 
                           Q->wadah[attackerIndex].nama, damage, Q->wadah[headIndex].nama);
                    
                    // Cek jika head kalah
                    if (Q->wadah[headIndex].health <= 0) {
                        Q->wadah[headIndex].aktif = false;
                        printf("%s telah kalah!\n", Q->wadah[headIndex].nama);
                        dequeue(Q, &E); // Karakter head mati, pindahkan head
                        printf("%s telah dihapus dari antrian.\n", E.nama);
                        break; // Lanjutkan dengan karakter berikutnya
                    }
                }
                attackerIndex = (attackerIndex + 1) % (MAX_CAPACITY + 1);
            }
        }
        headIndex = (headIndex + 1) % (MAX_CAPACITY + 1);
        
        // Cek apakah hanya ada satu karakter yang tersisa
        if (isOnlyOneActive(Q)) {
            printf("Hanya satu karakter yang tersisa! Pertempuran dihentikan.\n");
            break;
        }
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
    printf("===============================\n");
    printf("|| Menu - Pokemon Nawa  :    ||\n");
    printf("|| 1. Tambah karakter        ||\n");
    printf("|| 2. Hapus karakter         ||\n");
    printf("|| 3. Pertempuran            ||\n");
    printf("|| 4. Tampilkan antrian      ||\n");
    printf("|| 5. Keluar                 ||\n");
    printf("===============================\n");
}

int main() {
    karakter E;
    tqueue3 Q;
    initQueue(&Q);

    karakter all_characters[TOTAL_CHARACTERS] = {
        {"Pikachu", 20, 100, true},
        {"Charizard", 30, 120, true},
        {"Bulbasaur", 25, 150, true}, 
        {"Squirtle", 40, 70, true},
        {"Jigglypuff", 10, 90, true},
        {"Golem", 20, 110, true}, 
        {"Mewtwo", 30, 95, true},
        {"Snorlax", 35, 105, true},
        {"Gengar", 45, 120, true}, 
        {"Machamp", 55, 130, true},
        {"Vaporeon", 40, 70, true},
        {"Gardevoir", 10, 90, true},
        {"Lucario", 20, 110, true},
        {"Salamence", 30, 95, true},
        {"Dragonite", 35, 105, true},
        {"Alakazam", 45, 120, true},
        {"Lapras", 55, 130, true},
        {"Scizor", 40, 70, true},
        {"Clefable", 10, 90, true},
        {"Blissey", 20, 110, true}
    };

    int pilihan;

    do {
        menu();
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1: {
                displayAllCharacters(all_characters); // Tampilkan daftar karakter yang disediakan sistem
                karakter k;
                    printf("Pilih karakter untuk ditambahkan (1-20): ");
                int choice;
                scanf("%d", &choice);
    
                if (choice < 1 || choice > TOTAL_CHARACTERS) {
                    printf("Pilihan tidak valid!\n");
                } else {
                    // Cek jumlah elemen sebelum menambahkan karakter
                    if (countElements(&Q) >= MAX_CAPACITY) {
                        printf("Antrian penuh! Karakter tidak dapat ditambahkan.\n");
                    } else {
                        k = all_characters[choice - 1];
                        enqueue(&Q, k); // Cukup panggil enqueue, karena sudah ada pengecekan di dalamnya
                    }
                }
                break;
            }

            case 2:
                dequeue(&Q, &E);
                printf("Karakter di head telah dihapus dari antrian.\n");
                break;
            case 3:
                battle(&Q);
                break;
            case 4:
                displayQueueWithOrder(&Q);
                break;
            case 5:
                printf("Keluar dari program Pokemon Nawa.\n");
                printf("Jangan lupa latih Pokemonmu yaa!\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih lagi.\n");
                break;
        }
    } while (pilihan != 5);

    return 0;
}
