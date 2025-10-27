#Nama File : Soal4.py
#Pembuat   : Mohamad Solkhan Nawawi
#Tanggal   : 13 November 2023
#Deskripsi : fungsi yang mengecek apakah sebuah teks merupakan palindrom 
#           (jika teks menghasilkan bunyi yang sama saat dibaca dari kiri atau kanan).

def Konso(e,L):
  if L == [] :
    return [e]
  else :
    return [e] + L

def FirstElmt(L) :
  return L[0]

def LastElmt(L):
  return L[-1]

def Tail(L):
  return L[1:]

def Head(L):
  return L[:-1]

def IsEmpty(L) :
  if L == [] :
    return True
  else :
    return False

def Inverse(L):
  if IsEmpty(L) :
    return []
  else :
    return Konso(LastElmt(L), Inverse(Head(L)))

def CekPalindrom(L) :
  if (L == '') :
    return True
  else :
    if FirstElmt(L) == LastElmt(L) :
      return CekPalindrom(Tail(Head(L)))
    else :
      return False

#APLIKASI
print(CekPalindrom('kodok'))
print(CekPalindrom('daspro'))
  

  