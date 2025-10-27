#Nama File : Soal3.py
#Pembuat   : Mohamad Solkhan Nawawi
#Tanggal   : 13 November 2023
#Deskripsi : sebuah fungsi yang menghitung banyaknya kemunculan sebuah karakter X dalam sebuah teks

def FirstElmt(L) :
    return L[0]

def TailElmt(L) :
    return L[1:]

def NBElmtX(X, L) :
    if (L == '') :
        return 0
    elif X == FirstElmt(L) :
        return 1 + NBElmtX(X, TailElmt(L))
    else :
        return NBElmtX(X, TailElmt(L))
    
#APLIKASI
print(NBElmtX('a', 'alamat'))
print(NBElmtX('o', 'ilmu komputer dan informatika'))