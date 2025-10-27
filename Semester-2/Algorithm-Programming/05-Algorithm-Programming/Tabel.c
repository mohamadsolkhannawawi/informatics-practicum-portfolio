
/* Nama File : tabel.c */
/* Deskripsi : Body Abstract Data Type Tabel */


#ifndef TABEL_C
#define TABEL_C
#include "tabel.h"
#include <stdio.h>

/*Prototype*/
/***************************************************************/
/* */
/*                              KONSTRUCTOR */
/* */
/***************************************************************/

void CreateEmpty(TabInt* T);
/* Proses : Mengeset nilai T.Neff dengan nilai 0. */
/* I.S : Sembarang. */
/* F.S : Terbentuk tabel T kosong dengan kapasitas Nmax-Nmin+1.*/

//Kamus lokal
    int i;
//Algoritma
    for (i = IdxMin; i <= IdxMax; i++){
        T->TI[i] = ValUndef;
    }


/***************************************************************/

/***************************************************************/
/* */
/*                 OPERASI TERHADAP INDEKS TABEL */
/* */
/***************************************************************/ boolean IsIdxValid(TabInt T, IdxType i);

boolean IsIdxValid(TabInt T, IdxType i);
/* Mengirimkan true apabila i merupakan index yang valid bagi */
/* TabInt T, yaitu IdxMin <= i <= IdxMax. */

//Kamus Lokal
IdxMin = 1;
IdxMax = 100;

if (i >= IdxMin && i <= IdxMax){
    return true;
} else {
    return false;
}

boolean IsIdxEff(TabInt T, IdxType i);
/* Mengirimkan true apabila i merupakan indeks yang efektif */
/* berisi suatu nilai, yaitu idxmin <= i <= NEff. */

if (i >= IdxMin && i <= T.Neff){
    return true;
} else {
    return false;
}

/***************************************************************/
/* */
/*          PREDIKAT TABEL */
/* */
/***************************************************************/

boolean IsEmpty(TabInt T);
/* Mengirimkan true apabila T merupakan TabInt yang kosong, */
/* yaitu apabila T.NEff == 0. */

boolean IsFull(TabInt T);
/* Mengirimkan true apabila T merupakan TabInt yang penuh, */
/* yaitu apabila T.NEff == IdxMax. */

#endif
