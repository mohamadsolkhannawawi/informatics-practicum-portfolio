# TYPE LIST OF LIST
# DEFINISI DAN SPESIFIKASI TYPE
# {Konstruktor menambahkan elemen di awal, notasi prefix}
# type List : [] atau [e o List]
# {Konstruktor menambahkan elemen di akhir, notasi postfix}
# type List : [] atau [List i(.) e]
# {Definisi List : sesuai dengan definisi rekursif di atas}

# DEFINISI DAN SPESIFIKASI KONSTRUKTOR
# Konso : element, List -> List
# {Konso(e,L): menghasilkan sebuah list dari e dan L, dengan e sebagai elemen pertama list : e o L -> L'}
def Konso(e,L):
    if L == []:
        return [e]
    else:
        return [e] + L

# Konsi : List,element -> List
# {Konsi(e,L): menghasilkan sebuah list dari L dan e, dengan e sebagai elemen terakhir list : L i(.) e -> L'}
def Konsi(L,e):
    if L == []:
        return [e]
    else:
        return L + [e] 

# DEFINISI DAN SPESIFIKASI SELEKTOR O
# FirstElmt : List tidak kosong -> elemen
# {FirstElmt(L) Mengakibatkan elemen pertama pada list L}
def FirstElmt(L):
    if L == [] :
        return None
    else:
        return L[0]

# LastElmt : List tidak kosong -> elemen
# {LastElmt(L) Menghasilkan elemen terakhir list L}
def LastElmt(L):
    if  L == []:
        return None
    else:
        return L[-1]

# Tail : List tidak kosong -> List
# {Tail(L) Menghilangkan list tanpa elemen pertama list L, mungkin kosong}
def Tail(L):
    if L == []:
        return []
    else:
        return L[1:]

# Head : List tidak kosong -> List
# {Head(L) Menghilangkan list tanpa elemen terakhir list L, mungkin kosong}
def Head(L):
    if L == []:
        return []
    else:
        return L[:-1]

# DEFINISI DAN SPESIFIKASI PREDIKAT DASAR {UNTUK BASIS ANALISA REKURENS}
# {Basis 0}
# IsEmpty : List -> boolean
# {IsEmpty(L) benar jika list kosong}
def IsEmpty(L):
    return L == []

print(IsEmpty([]))

# {Basis 1}
# IsOneElmt : List -> boolean
# {IsOneElmt(L) adalah benar jika list L hanya mempunyai satu elemen}
def IsOneElmt(L):
    return Head(L) == []    # Tail(L) == [] ini juga bisa

# DEFINISI DAN SPESIFIKASI PREDIKAT RELASIONAL
# IsEqual : 2 List -> boolean 
# {IsEqual(L1,L2) benar jika semua elemen list L1 sama dengan L2: sama urutan dan sama nilainya}
def IsEqual(L1,L2):
    if(IsEmpty(L1) and IsEmpty(L2)):
        return True
    else:
        if(FirstElmt(L1) == FirstElmt(L2)):
            return IsEqual(Tail(L1),Tail(L2))
        else:
            return False

# BERBERAPA DEFINISI DAN SPESIKASI FUNGSI LAIN
# NnElmt : List -> integer
# {NbElmt(L) : Menghasilkan banyaknya elemen list, nol jika kosong}
def NbElmt(L):
    if IsEmpty(L) :
        return 0
    else:
        return 1 + NbElmt(Tail(L))
    
# ElmtkeN : integer > 0 , List -> elemen
# {ElmtkeN(N,L) : Mengirimkan elemen list yang ke N, 0 < N <= NbElmt(L)}
def ElmtkeN(N,L):
    if N == 1:
        return FirstElmt(L)
    else:
        return ElmtkeN(N-1,Tail(L))
    
# Copy : List -> List
# {Copy(L) : Menghasilkan list yang identiik dengan list asal}
def Copy(L):
    if IsEmpty(L):
        return []
    else:
        return Konso(FirstElmt(L),Copy(Tail(L))) #L[|:|]
    
# Inverse : List -> List 
# {Inverse(L) : Menghasilkan list L yang dibalik, yaitu yang urutan}
def Inverse(L):
    if IsEmpty(L):
        return []
    else:
        return Konso(LastElmt(L),Inverse(Head(L)))

# Konkat : 2 List -> List
# {Konkat(L1,L2) : Menghasilkan konkatenasi 2 buah list, dengan list L2 "sesudah" List L1}
def Konkat(L1,L2):
    if IsEmpty(L2):
        return L1
    else:
        return Konkat(Konsi(L1,FirstElmt(L2)),Tail(L2))
    
# BERBERAPA DEFINISI DAN SPESIFIKASI PREDIKAT
# IsMember : elemen, List -> boolean
# {IsMember(X,L) adalah benar jika X adalah elemen list L}
def IsMember(X,L):
    if IsEmpty(L):
        return False
    elif X == FirstElmt(L):
        return True
    else:
        return IsMember(X,Tail(L))
    
# IsFirst : elemen, List (tidak kosong) -> boolean
# {IsFirst(X,L) adalah benar jika X adalah elemen pertama list L}
def IsFirst(X,L):
    if IsEmpty(L):
        return False
    elif X == FirstElmt(L):
        return True
    else:
        return False

# IsLast : elemen, List (tidak kosong) -> boolean
# {IsLast(X,L) adalah benar jika X adalah elemen terakhir list L}
def IsLast(X,L):
    if IsEmpty(L):
        return False
    elif X == LastElmt(L):
        return True
    else:
        return False
    
# IsNbElmtN : integer > 0 dan <= NBElmt(L), List -> integer
# {IsNbElmtN (N,L) true jika banyaknya elemen list sama dengan N}
def IsNbElmtN(N,L):
    if N == 0:
        return IsEmpty(L)
    elif (N > 0 and N <= NbElmt(L)):
        return True
    else:
        return False
        
    
# IsInverse : List, List -> boolean
# IsInverse(L1,L2) true jika L2 adakah list dengan urutan elemen terbalik dibandingkan L1}
def IsInverse(L1,L2):
    if NbElmt(L1) != NbElmt(L2):
        return False
    if IsEmpty(L1) and IsEmpty(L2):
        return True
    else:
        return (FirstElmt(L1) == LastElmt(L2)) and IsInverse(Tail(L1),Head(L2))
    
# IsXElmtkeN : integer >= 0 dan NBElmt(L), elemen, List -> boolean
# {IsXElmtkeN(N,X,L) adalah benar jika X adalah elemen list yang ke N}
def IsXElmtkeN(N,X,L):
    if (N < 1 or N > NbElmt (L)):
        return False
    elif N == 1 :
        return X == FirstElmt(L)
    else:
        return IsXElmtkeN(X,N-1,Tail(L))
    
# DEFNISI DAN SPESIFIKASI OPERATOR TERHADAP TYPE
# Rember : elemen, List -> list
# {Rember(e,L) menghilangkan sebuah elemen e di List L dari index awal}
def Rember(e, L):
    if IsEmpty(L):
        return []
    else:
        if FirstElmt(L) == e:
            return Tail(L)
        else:
            return Konso(FirstElmt(L), Rember(e, Tail(L)))
        
# MultiRember : elemen, list -> list
# {MultiRember(x,L) menghapus semua elemen bernilai x dari list}
# {list yang baru tidak lagi mempunyai elemen yang bernilai x}
# {List kosong tetap menjadi list kosong}
def MultiRember(x,L):
    if IsEmpty(L):
        return L
    else:
        if FirstElmt(L) == x :
            return MultiRember(x,Tail(L))
        else:
            return Konso(FirstElmt(L),MultiRember(x,Tail(L)))
        
        
  