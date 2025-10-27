#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 20
#define QUEUE_SIZE 10

typedef struct {
    char name[20];
    int damage;
    int health; // Health karakter
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

// Menampilkan daftar karakter dalam queue
void viewQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Tidak ada karakter dalam antrian.\n");
    } else {
        printf("Karakter dalam antrian:\n");
        for (int i = 0; i < q->count; i++) {
            int index = (q->head + i) % QUEUE_SIZE;
            Character character = q->queue[index];
            if (character.active) { // Hanya tampilkan karakter yang masih aktif
                printf("%s (Damage: %d, Health: %d)\n", character.name, character.damage, character.health);
            }
        }
    }
}

// Memulai permainan
void startGame() {
    Character characters[MAX_CHARACTERS];
    CircularQueue queue;
    createQueue(&queue);

    // Menginisialisasi karakter
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        sprintf(characters[i].name, "Character %d", i + 1);
        characters[i].damage = (i + 1) * 10; // Damage karakter
        characters[i].health = 500; // Set health awal
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
        printf("3. Melanjutkan Pertempuran\n");
        printf("4. Melihat Daftar Karakter\n");
        printf("5. Keluar\n");

        int option;
        printf("Pilih opsi: ");
        scanf("%d", &option);

        if (option == 1) { // Menambahkan karakter
            printf("Pilih karakter dari 1 hingga 20:\n");
            for (int i = 0; i < MAX_CHARACTERS; i++) {
                printf("%d. %s (Damage: %d)\n", i + 1, characters[i].name, characters[i].damage);
            }
            int choice;
            printf("Masukkan nomor karakter yang ingin ditambahkan: ");
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
        } else if (option == 3) { // Melanjutkan pertempuran
            if (!isEmpty(&queue)) {
                // Proses serangan
                for (int i = 0; i < queue.count; i++) {
                    int targetIndex = (queue.head + i) % QUEUE_SIZE; // Target yang diserang
                    Character *target = &queue.queue[targetIndex];

                    if (target->active) {
                        for (int j = i + 1; j < queue.count; j++) { // Karakter setelah target
                            int attackerIndex = (queue.head + j) % QUEUE_SIZE; // Karakter yang menyerang
                            Character *attacker = &queue.queue[attackerIndex];
                            
                            if (attacker->active) {
                                target->health -= attacker->damage; // Target diserang
                                printf("%s diserang oleh %s! Sisa health: %d\n", target->name, attacker->name, target->health);
                            }
                        }
                    }

                    // Cek jika target sudah tidak aktif
                    if (target->health <= 0) {
                        target->active = 0; // Tandai karakter sebagai tidak aktif
                        printf("%s telah mati!\n", target->name);
                    }
                }

                // Cek jika hanya satu karakter yang tersisa
                int activeCount = 0;
                Character winner;
                for (int i = 0; i < queue.count; i++) {
                    if (queue.queue[(queue.head + i) % QUEUE_SIZE].active) {
                        activeCount++;
                        winner = queue.queue[(queue.head + i) % QUEUE_SIZE]; // Simpan pemenang
                    }
                }

                if (activeCount == 1) {
                    printf("Permainan berakhir! Pemenangnya adalah %s!\n", winner.name);
                    break; // Keluar dari permainan jika hanya satu karakter yang tersisa
                }

            } else {
                printf("Tidak ada karakter dalam antrian.\n");
            }
        } else if (option == 4) { // Melihat daftar karakter
            viewQueue(&queue);
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
