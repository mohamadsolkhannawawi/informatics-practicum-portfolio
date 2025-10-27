#include <stdio.h>

int main() {
    // Input batas alto, batas mezzo-sopran, dan jumlah nada
    int batasAlto, batasMezzoSopran, jumlahNada;
    scanf("%d", &jumlahNada);
    scanf("%d", &batasAlto);
    scanf("%d", &batasMezzoSopran);

    // Variabel untuk menyimpan urutan nada
    int altoCount, mezzoSopranCount, sopranCount;

    // Input urutan nada
    printf("Masukkan urutan nada: ");
    int urutan_nada[jumlahNada];
    for (int i = 0; i < jumlahNada; i++) {
        scanf("%d", &urutan_nada[i]);
    }

    // Variabel untuk menyimpan jenis suara dan menghitung anggota yang sudah dicetak
    altoCount = 0;
    mezzoSopranCount = 0;
    sopranCount = 0;

    // Loop melalui urutan nada dan menentukan jenis suara masing-masing anggota
    printf("Output:\n");
    for (int i = 0; i < jumlahNada; i++) {
        if (urutan_nada[i] < batasAlto) {
            // Jika anggota memiliki suara alto
            if (altoCount == 0) {
                printf("Alto: ");
            }
            printf("%d ", urutan_nada[i]);
            altoCount++;
        } else if (urutan_nada[i] >= batasAlto && urutan_nada[i] < batasMezzoSopran) {
            // Jika anggota memiliki suara mezzo-sopran
            if (mezzoSopranCount == 0) {
                printf("\nMezzo-sopran: ");
            }
            printf("%d ", urutan_nada[i]);
            mezzoSopranCount++;
        } else {
            // Jika anggota memiliki suara sopran
            if (sopranCount == 0) {
                printf("\nSopran: ");
            }
            printf("%d ", urutan_nada[i]);
            sopranCount++;
        }
    }

    return 0;
}
