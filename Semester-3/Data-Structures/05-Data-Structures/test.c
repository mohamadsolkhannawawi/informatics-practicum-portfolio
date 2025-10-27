#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 20
#define QUEUE_SIZE 10

typedef struct {
    char name[20];
    int damage;
    int health;
    int active; // 1 untuk aktif, 0 untuk tidak aktif
} Character;

typedef struct {
    Character queue[QUEUE_SIZE];
    int head;
    int tail;
    int count;
} CircularQueue;

// Fungsi untuk membuat queue
void createQueue(CircularQueue *q) {
    q->head = 0;
    q->tail = 0;
    q->count = 0;
}

// Memeriksa apakah queue kosong
int isEmpty(CircularQueue *q) {
    return q->count == 0;
}

// Memeriksa apakah queue penuh
int isFull(CircularQueue *q) {
    return q->count == QUEUE_SIZE;
}

// Menambahkan karakter ke queue
void enqueue(CircularQueue *q, Character character) {
    if (!isFull(q)) {
        q->queue[q->tail] = character;
        q->tail = (q->tail + 1) % QUEUE_SIZE;
        q->count++;
    } else {
        printf("Queue sudah penuh!\n");
    }
}

// Menghapus karakter dari queue
Character dequeue(CircularQueue *q) {
    Character emptyCharacter = {"", 0, 0, 0}; // Karakter kosong
    if (!isEmpty(q)) {
        Character character = q->queue[q->head];
        q->head = (q->head + 1) % QUEUE_SIZE;
        q->count--;
        return character;
    } else {
        printf("Queue kosong!\n");
        return emptyCharacter;
    }
}

// Menampilkan daftar karakter dalam queue dengan damage dan health
void viewQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Tidak ada karakter dalam antrian.\n");
    } else {
        printf("Karakter dalam antrian (dari head ke tail):\n");
        for (int i = 0; i < q->count; i++) {
            int index = (q->head + i) % QUEUE_SIZE;
            printf("%d. %s (Sisa Darah: %d, Damage: %d)\n", i + 1, q->queue[index].name, q->queue[index].health, q->queue[index].damage);
        }
    }
}

// Fungsi untuk memulai pertempuran: Setiap karakter menyerang karakter di depannya
void battle(CircularQueue *q) {
    if (q->count < 2) {
        printf("Tidak cukup karakter untuk bertarung.\n");
        return;
    }

    // Elemen head diserang oleh elemen setelahnya hingga tail
    for (int i = 0; i < q->count - 1; i++) {
        int attackedIndex = (q->head + i) % QUEUE_SIZE;
        Character *attacked = &q->queue[attackedIndex];

        printf("\n%s diserang oleh karakter setelahnya:\n", attacked->name);

        // Setiap elemen setelah attackedIndex menyerang attacked
        for (int j = i + 1; j < q->count; j++) {
            int attackerIndex = (q->head + j) % QUEUE_SIZE;
            Character *attacker = &q->queue[attackerIndex];

            if (attacked->active) {
                printf("%s menyerang %s dengan damage %d\n", attacker->name, attacked->name, attacker->damage);
                attacked->health -= attacker->damage;

                if (attacked->health <= 0) {
                    printf("%s kalah!\n", attacked->name);
                    attacked->active = 0;
                    attacked->health = 0; // Pastikan health tidak negatif
                    break; // Karakter mati, hentikan serangan berikutnya
                }
            }
        }
    }

    // Hapus karakter yang kalah dari antrian
    while (!isEmpty(q) && q->queue[q->head].health <= 0) {
        dequeue(q);
    }
}

// Memulai permainan
void startGame() {
    Character characters[MAX_CHARACTERS];
    CircularQueue queue;
    createQueue(&queue);

    // Menginisialisasi karakter dengan health awal yang lebih besar
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        sprintf(characters[i].name, "Pokemon %d", i + 1);
        characters[i].damage = (i + 1) * 10; // Damage karakter
        characters[i].health = 500; // Health awal yang lebih besar
        characters[i].active = 1; // Semua karakter aktif pada awalnya
    }

    printf("Pilih 10 karakter dari berikut:\n");
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        printf("%d. %s (Damage: %d)\n", i + 1, characters[i].name, characters[i].damage);
    }

    // Memilih karakter
    while (queue.count < QUEUE_SIZE) {
        int choice;
        printf("Masukkan nomor karakter yang ingin dipilih (0 untuk selesai): ");
        scanf("%d", &choice);
        if (choice == 0) break;
        if (choice >= 1 && choice <= MAX_CHARACTERS) {
            enqueue(&queue, characters[choice - 1]);
            printf("%s ditambahkan ke antrian.\n", characters[choice - 1].name);
        } else {
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }

    // Menu utama
    while (1) {
        printf("\nMenu Utama:\n");
        printf("1. Menambahkan Karakter\n");
        printf("2. Menghapus Karakter\n");
        printf("3. Melihat Daftar Karakter\n");
        printf("4. Melanjutkan Pertempuran\n");
        printf("5. Keluar\n");

        int option;
        printf("Pilih opsi: ");
        scanf("%d", &option);

        if (option == 1) { // Menambahkan karakter
            int choice;
            printf("Masukkan nomor karakter yang ingin ditambahkan (1-20): ");
            scanf("%d", &choice);
            if (choice >= 1 && choice <= MAX_CHARACTERS) {
                enqueue(&queue, characters[choice - 1]);
                printf("%s ditambahkan ke antrian.\n", characters[choice - 1].name);
            } else {
                printf("Pilihan tidak valid.\n");
            }
        } else if (option == 2) { // Menghapus karakter
            Character removedCharacter = dequeue(&queue);
            if (removedCharacter.active) {
                printf("%s telah dikeluarkan dari antrian.\n", removedCharacter.name);
            }
        } else if (option == 3) { // Melihat daftar karakter
            viewQueue(&queue);
        } else if (option == 4) { // Melanjutkan pertempuran
            battle(&queue);
        } else if (option == 5) { // Keluar
            printf("Terima kasih telah bermain!\n");
            break;
        } else {
            printf("Pilihan tidak valid.\n");
        }
    }
}

int main() {
    startGame(); // Memulai permainan
    return 0;
}
