#include <stdio.h>
#include "tabel.c"
// Deskripsi : driver ADT tabel integer
// NIM/Nama : 24060123120020/Mohamad Solkhan Nawawi
// Tanggal : Jumat, 6 September 2024

int main() {
	// Kamus
	Tabel T1, T2;
	
	// Algoritma
	//Aplikasi penggunaan createTable
	createTable(&T1);
	createTable(&T2);

    //Test fungsi setelah di createTable
    printf("Setelah createTable\n");
    printf("T1 : ");
    printTable(T1);
    printf("\nT2 : ");
    printTable(T2);
    //Test getSize
    printf("\nUkuran dari T1 : %d\n", getSize(T1));
    printf("Ukuran dari T2 : %d\n", getSize(T2));
    //Test getMax
    printf("Maksimum elemen T1 : %d\n", getMaxEl(T1));
    printf("Maksimum elemen T2 : %d\n", getMaxEl(T2));
    //Test getMin
    printf("Minimum elemen T1 : %d\n", getMinEl(T1));
    printf("Minimum elemen T2 : %d\n", getMinEl(T2));
    //Test SumEl
    printf("Penjumlahan elemen T1 : %d\n", SumEl(T1));
    printf("Penjumlahan elemen T2 : %d\n", SumEl(T2));
    //Test AverageEl
    printf("Rata-rata elemen T1 : %.2f\n", AverageEl(T1));
    printf("Rata-rata elemen T2 : %.2f\n", AverageEl(T2));
    //Test Modus
    printf("Modus T1 : %d\n", Modus(T1));
    printf("Modus T2 : %d\n", Modus(T2));
    //Test SortAsc
    printf("T1 sebelum diurutkan : ");
    viewTable(T1);
    sortAsc(&T1);
    printf("\nT1 setelah diurutkan : ");
    viewTable(T1);
    //Test SortDesc
    printf("\nT2 sebelum diurutkan : ");
    viewTable(T2);
    sortDesc(&T2);
    printf("\nT2 setelah diurutkan : ");
    viewTable(T2);
    //isFullTable
    printf("\nApakah T1 penuh : %s\n", isFullTable(T1)? "Iya" : "Tidak");
    printf("Apakah T2 penuh : %s\n", isFullTable(T2)? "Iya" : "Tidak");
    //isEmptyTable
    printf("Apakah T1 kosong : %s\n", isEmptyTable(T1)? "Iya" : "Tidak");
    printf("Apakah T2 kosong : %s\n", isEmptyTable(T2)? "Iya" : "Tidak");

	// Menampilkan isi tabel sebelum diisi
    printf("\nTabel T1 sebelum di isi : ");
	printTable(T1);
    printf("\nTabel T2 sebelum di isi : ");
    printTable(T2);

    //Aplikasi penggunaan addXTable
    printf("\nMenambahkan 1 1 3 3 5 ke T1\n");
    addXTable(&T1, 1);
    addXTable(&T1, 1);
    addXTable(&T1, 3);
    addXTable(&T1, 3);
    addXTable(&T1, 5);
    printf("Isi T1 setelah di isi : ");
    printTable(T1);

    printf("\nMenambahkan 2 2 4 4 6 ke T2\n");
    addXTable(&T2, 2);
    addXTable(&T2, 2);
    addXTable(&T2, 4);
    addXTable(&T2, 4);
    addXTable(&T2, 6);
    printf("Isi T2 setelah di isi : ");
    printTable(T2);

    //Aplikasi penggunaan getSize
    printf("\nUkuran dari T1 : %d\n", getSize(T1));
    printf("Ukuran dari T2 : %d\n", getSize(T2));

    //Aplikasi penggunaan isEmptyTable
    printf("Apakah T1 kosong : %s\n", isEmptyTable(T1)? "Iya" : "Tidak");
    printf("Apakah T2 kosong : %s\n", isEmptyTable(T2)? "Iya" : "Tidak");
    
    //Aplikasi penggunaan isFullTable
    printf("Apakah T1 penuh : %s\n", isFullTable(T1)? "Iya" : "Tidak");
    printf("Apakah T2 penuh : %s\n", isFullTable(T2)? "Iya" : "Tidak");

    //Aplikasi penggunaan searchX
    printf("Angka 3 pada T1 ada pada index ke : %d\n", searchX(T1, 3));
    printf("Angka 6 ada pada index ke : %d\n", searchX(T2, 6));

    //Aplikasi penggunaan countX
    printf("Angka 1 ada sebanyak %d pada T1\n", countX(T1, 1));
    printf("Angka 6 ada sebanyak %d pada T2\n", countX(T2, 6));

    //Aplikasi penggunaan countEmpty
    printf("Banyaknya elemen yang belum terisi pada T1 : %d\n", countEmpty(T1));
    printf("Banyaknya elemen yang belum terisi pada T2 : %d\n", countEmpty(T2));

    //Aplikasi penggunaan delXTable
    printf("Aplikasi penggunaan delXTable\n");
    printf("T1 sebelum dihapus elemen 3 : ");
    printTable(T1);
    printf("\nMenghapus elemen 3 dari T1\n");
    delXTable(&T1, 3);
    printf("T1 setelah dihapus elemen 3 : ");
    printTable(T1);

    printf("\nT2 sebelum dihapus elemen 4 : ");
    printTable(T2);
    printf("\nMenghapus elemen 4 dari T2");
    delXTable(&T2, 4);
    printf("\nT2 setelah dihapus elemen 4 : ");
    printTable(T2);

    //Aplikasi penggunaan delAllXTabel
    printf("\nAplikasi penggunaan delAllXTabel\n");
    printf("T1 sebelum dihapus semua elemen 1 : ");
    printTable(T1);
    printf("\nMenghapus semua elemen 1 dari T1\n");
    delAllXTable(&T1, 1);

    printf("T2 sebelum dihapus semua elemen 2 : ");
    printTable(T2);
    printf("\nMenghapus semua elemen 2 dari T2\n");
    delAllXTable(&T2, 2);


    //Aplikasi printTable
    printf("Aplikasi printTable\n");
    printf("Print T1 : ");
    printTable(T1);
    printf("\nPrint T2 : ");
    printTable(T2);

    //Aplikasi viewTable
    printf("\nAplikasi viewTable");
    printf("\nView T1 : ");
    viewTable(T1);
    printf("\nView T2 : ");
    viewTable(T2);

    //Aplikasi populate1
    printf("\nAplikasi populate1");
    printf("\nMengisi T1 dengan 5 elemen\n");
    populate1(&T1, 5);
    printf("T1 setelah diisi : ");
    viewTable(T1);

    printf("\nMengisi T2 dengan 3 elemen\n");
    populate1(&T2, 3);
    printf("T2 setelah diisi : ");
    viewTable(T2);

    //Aplikasi populate2
    printf("\nAplikasi populate2\n");
    printf("Mengisi T1 dengan elemen positif\n");
    populate2(&T1);
    printf("T1 setelah diisi : ");
    viewTable(T1);

    printf("\nMengisi T2 dengan elemen positif\n");
    populate2(&T2);
    printf("T2 setelah diisi : ");
    viewTable(T2);

    //Aplikasi SumEl
    printf("\nPenjumlahan elemen T1 : %d\n", SumEl(T1));
    printf("Penjumlahan elemen T2 : %d\n", SumEl(T2));

    //Aplikasi AverageEl
    printf("Rata-rata elemen T1 : %.2f\n", AverageEl(T1));
    printf("Rata-rata elemen T2 : %.2f\n", AverageEl(T2));

    //Aplikasi getMaxEl
    printf("Maksimum elemen T1 : %d\n", getMaxEl(T1));
    printf("Maksimum elemen T2 : %d\n", getMaxEl(T2));

    //Aplikasi getMinEl
    printf("Minimum elemen T1 : %d\n", getMinEl(T1));
    printf("Minimum elemen T2 : %d\n", getMinEl(T2));

    //Aplikasi Modus
    printf("Modus T1 : %d\n", Modus(T1));
    printf("Modus T2 : %d\n", Modus(T2));

    //Aplikasi SortAsc
    printf("Aplikasi SortAsc\n");
    printf("T1 sebelum diurutkan : ");
    viewTable(T1);
    sortAsc(&T1);
    printf("\nT1 setelah diurutkan : ");
    viewTable(T1);

    printf("\nT2 sebelum diurutkan : ");
    viewTable(T2);
    sortAsc(&T2);
    printf("\nT2 setelah diurutkan : ");
    viewTable(T2);

    //Aplikasi SortDesc
    printf("\nAplikasi SortDesc\n");
    printf("T1 sebelum diurutkan : ");
    viewTable(T1);
    sortDesc(&T1);
    printf("\nT1 setelah diurutkan : ");
    viewTable(T1);

    printf("\nT2 sebelum diurutkan : ");
    viewTable(T2);
    sortDesc(&T2);
    printf("\nT2 setelah diurutkan : ");
    viewTable(T2);

    return 0;
}