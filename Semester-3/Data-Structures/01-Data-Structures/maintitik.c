/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060123120020/Mohamad Solkhan Nawawi*/
/* Tanggal   : Kamis, 29 Agustus 2024*/
/***********************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "titik.h"

int main() {
	//kamus main
	Titik A;
    Titik B;

	// algoritma
	printf("\nDriver main titik berhasil dijalankan... \n\n");

	makeTitik(&A);
    printf("\nNilai absis sebelum di set = %d", getAbsis(A));
    printf("\nNilai ordinat sebelum di set = %d", getOrdinat(A));
    printf("\nApakah titik A berada di titik origin? %s", isOrigin(A)?"Ya":"Tidak");

	setAbsis(&A,3);
	printf("\nNilai absis setelah di set = %d", getAbsis(A));
    setOrdinat(&A,4);
    printf("\nNilai ordinat setelah di set = %d", getOrdinat(A));
    
    printf("\nApakah titik A berada di titik origin? %s", isOrigin(A)?"Ya":"Tidak");
    printf("\nTitik A sebelum di geser berada di kuadran = %d", Kuadran(A));

    geserXY(&A, 2, 3);
    printf("\nSetelah digeser (2,3), nilai absis = %d dan ordinat = %d", getAbsis(A), getOrdinat(A));
    refleksiSumbuX(&A);
    printf("\nSetelah direfleksi thd sumbu X, nilai absis = %d dan ordinat = %d", getAbsis(A), getOrdinat(A));
    refleksiSumbuY(&A);
    printf("\nSetelah direfleksi thd sumbu Y, nilai absis = %d dan ordinat = %d", getAbsis(A), getOrdinat(A));
    printf("\nTitik A sekarang berada di kuadran = %d", Kuadran(A));
    printf("\nTitik A, absis = %d, ordinat = %d", getAbsis(A), getOrdinat(A));

    makeTitik(&B);
    setAbsis(&B, 1);
    setOrdinat(&B, 1);
    printf("\nTitik B, absis = %d, ordinat = %d", getAbsis(B), getOrdinat(B));
    printf("\nJarak titik A ke titik B adalah %.2f\n\n", Jarak(A,B));
	return 0;
}