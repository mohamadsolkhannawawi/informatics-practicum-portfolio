#Nama File : List.py
#Pembuat   : Mohamad Solkhan Nawawi
#Tanggal   : 12 November 2023
#Deskripsi : Kumpulan fungsi yang terdapat pada List

a = [1,2,3,4]
b = [1,2,3]


# TYPE LIST
# DEFINISI DAN SPESIFIKASI TYPE
# {Konstruktor menambahkan elemen di awal, notasi prefix}
# type List : [] atau [e o List]
# {Konstruktor menambahkan elemen di akhir, notasi postfix}
# type List : [] atau [List i(.) e]
# {Definisi List : sesuai dengan definisi rekursif di atas}

#DEFINISI DAN SPESIFIKASI KONSTRUKTOR
#Konso : elemen, List ---> List
# {Konso(e,L) : menghasilkan sebuah list dari e dan L,
#  dengan e sebagai elemen pertama e : e o L ---> L}
def Konso(e,L):
  if L == [] :
    return [e]
  else :
    return [e] + L
  
# Konsi : List, elemen ---> list
#{Konsi(L,e) : menghasilkan sebuah list dari L dan e,
#  dengan e sebagai elemen terakhir list : L i(.) e ---> L'}
def Konsi(L,e) :
  if L == []:
    return [e]
  else :
    return L + [e]



#DEFINISI DAN SPESIFIKASI SELEKTOR 0
#FirstElmt : List tidak kosong ---> elemen
# {FirstElmt(L) : Menghasilkan element pertama list L}
def FirstElmt(L) :
  return L[0]

#LastElmt : List tidak kosong ---> elemen
# {LastElmt(L) : Menghasilkan list elment terakhir list L}
def LastElmt(L):
  return L[-1]

#Tail : List tidak kosong ---> List
# {Tail(L) : Menghasilkan list tanpa element pertama list L, mungkin kosong }
def Tail(L):
  return L[1:]

#Head : List tidak kosong ---> List
# {Head(L) : Menghasilkan list tanpa element terakhir list L, mungkin kosong }
def Head(L):
  return L[:-1]



#DEFINISI DAN SPESIFIKASI PREDIKAT DASAR
#IsEmpty : List  ---> Boolean
# {IsEmpty(L) : Benar jika list kosong}
def IsEmpty(L) :
  if L == [] :
    return True
  else :
    return False
  
#IsOneElmt : List ---> Boolean
#{IsOneElmt(L) : benar jika list hanya memiliki satu elemen}
def IsOneElmt(L) :
  if Tail(L) == [] :
    return True
  else :
    return False

#DEFINISI DAN SPESIFIKASI PREDIKAT RELASIONAL
#IsEqual : 2 List ---> Boolean
#{IsEqual(L1,L2)} : benar jika semua elemen list L1 sama dengan list L2 : sama urutan dan sama nilainya
def IsEqual(L1,L2):
  if IsEmpty(L1) and IsEmpty(L2):
    return True
  else :
    if FirstElmt(L1) == FirstElmt(L2) :
      return IsEqual(Tail(L1),Tail(L2))
    else :
      return False
    
#DEFINSI DAN SPESIFIKASI FUNGSI LAIN
#NbElmt : list ---> integer
#  {NbElmt(L) : menghasilkan banyak elemen list,nol jika list kosong}
def NbElmt(L):
  if IsEmpty(L) :
    return 0
  else :
    return 1 + NbElmt(Tail(L))
  
#ElmtkeN : integer >= 0, list ---> elemen 
#  {ElmtkeN(N,L) : mengirimkan elemen list yang ke N, N <= NbElmt(L) dan N > 0}
def ElmtkeN(N,L):
  if N == 1 :
    return FirstElmt(N)
  else :
    return ElmtkeN(N-1,Tail(L))
  
#Copy : list ---> list 
# {Copy(L) : menghasilkan list yang identik dengan list asal}
def Copy(L):
  if IsEmpty(L):
    return []
  else :
    return Konso(FirstElmt(L), Copy(Tail(L)))

#Inverse : list ---> list 
#  {Inverse(L) : menghasilkan list l yang dibalik , yaitu yang urutan elemennya kebalikan dari list asal}
def Inverse(L):
  if IsEmpty(L) :
    return []
  else :
    return Konso(LastElmt(L), Inverse(Head(L)))
  
#Konkat : 2list ---> list
#  {Konkat(L1,L2) : menghasilkan konkatenasi 2 buah list, dengan list L2 "sesudah" list L1}
def Konkat(L1,L2) :
  if IsEmpty(L1) :
    return L2
  else :
    return Konso(FirstElmt(L1),Konkat(Tail(L1),L2))
  

#DEFINISI DAN SPESIFIKASI PREDIKAT
#IsMember : elemen,list --> boolean
#  {IsMember(X,L) : benar jika X adalah elemen dari list L}
def IsMember(X,L) :
  if IsEmpty(L):
    return False
  elif X == FirstElmt(L) :
    return True
  else :
    return IsMember(X,Tail(L))
  

#IsFirst : elemen,list tidak kosong ---> boolean
#  {IsFirst(X,L) : benar jika elemen X adalah elemen pertama dari list L}
def IsFirst(X,L) : 
  if IsEmpty(L) :
    return False
  elif X == FirstElmt(L) :
    return True
  else :
    return False
  
#IsLast : elemen,list tidak kosong ---boolean
#  {IsLast(X,L) : benar jika X adalah elemen terakhir dari list L}
def IsLast(X,L) :
  if IsEmpty(L) :
    return False
  elif X == LastElmt(L) :
    return True
  else : 
    return False
  
#IsNbElmtN : integer >= 0 dan <= NbElmtN(L) , list ---> integer
#  {IsNbElmtN(N,L) : benar jik banyaknya elemen list L sama dengan N}
def IsNbElmtN(N,L) :
  if N == 0 :
    if IsEmpty(L) :
      return True
    else :
      return False 
  else :
    return IsNbElmtN(N-1, Tail(L))
  
#IsInverse : list , list --> boolean
#  {IsInverse(L1,L2) : benar jika jika L2 adalah list dengan urutan element terbalik dari L1}
def IsInverse(L1,L2) :
  if NbElmt(L1) == NbElmt(L2) :
    if IsEmpty(L1) and IsEmpty(L2) :
      return True
    else :
      return FirstElmt(L1) == LastElmt(L2) and IsInverse(Head(Tail(L1),Head(Tail(L2))))
  else :
    return False
  
#IsXElmtkeN : integer >= 0 dan <= NbElmt(l) , elemen , list ---> boolean
#  {IsXElmtkeN(N,X,L) : benar jika X adalah elemnt list yang ke N }
def IsXElmtkeN(N,X,L) :
  if IsMember(X,L) :
    if N == 1 and FirstElmt(L) == X :
      return True
    else :
      return False or IsXElmtkeN(X,N-1,Tail(L))
  else :
    return False


print(IsXElmtkeN(3,3,a))
