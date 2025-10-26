import List2
# TYPE LIST-OF-LIST
# DEFINSI DAN SPESIFIKASI PREDIKAT KHUSUS UNTUK LIST OF LIST 
# IsEmpty : list of list -> boolean
# {IsEmpty(S) benar jika S adalah list of list kosong}
def IsEmpty(S):
    return S == []

# IsAtom : list of list -> boolean
# {IsAtom(S) menghasilkan true jika list adalah atom, yaitu terdiri dari sebuah atom}
def IsAtom(S):
    if isinstance(S, (int, float, str, bytes, bool, type(None))):
        return True
    else:
        return False

# IsList : list of list -> boolean
# {IsList(S) menghasilkan true jika S adalah sebuah list (bukan atom)}
def IsList(S):
    return isinstance(S, list)

# DEFINISI DAN SPESIFIKASI KONSTRUKTOR
# KonsLo: List, List of list -> List of list
# {KonsLo(L,S) diberikan sebuah List L dan sebuah List of List S. membentuk list baru 
# dengan List yang diberikan sebagai elemen pertama List of list: L o S → S'}
def KonsLo(L,S):
    if L == []:
        return [S]
    else:
        return [S] + L

def s(k):
    if kon
    
# KonsLi : List of list, List -> List of list
# {KonsLi(S,L) diberikan sebuah List of list S dan sebuah list L, membentuk list baru 
# dengan List yang diberikan sebagai elemen terakhir list of List: S i(.) L -> S']
def KonsLi(L,S):
    if L == []:
        return [S]
    else:
        return L + [S]
    
# DEFINISI DAN SPESIFIKASI SELEKTOR 
# FirstList: List of list tidak kosong -> List 
# {FirstList(S) Menghasilkan elemen pertama list, mungkin sebuah list atau atom}
def FirstList(S):
    if S == [] :
        return None
    else:
        return S[0]
    
# TailList: List of list tidak kosong -> List of list 
# {TailList(S) Menghasilkan "sisa" list of list S tanpa elemen pertama list S}
def TailList(S):
    if S == [] :
        return None
    else:
        return S[1:]
    
# LastList: List of list tidak kosong -> List of list
# {LastList(S) Menghasilkan elemen terakhir list of list S. mungkin list atau atom}
def LastList(S):
    if S == [] :
        return None
    else:
        return S[-1]
    
# HeadList List of list tidak kosong -> List of list
# {HeadList(S) Menghasilkan "sisa" list of list tanpa elemen terakhir list}
def HeadList(S):
    if S == [] :
        return None
    else:
        return S[:-1]
    
# DEFINISI PREDIKAT
# IsEqs : 2 List of list -> boolean
# {IsEqs(S1,S2) true jika S1 identik dengan S2 : semua elemennya sama}
def IsEqs(S1,S2):
    if IsEmpty(S1) and IsEmpty(S2):
        return True
    elif not IsEmpty(S1) and IsEmpty(S2):
        return False
    elif IsEmpty(S1) and not IsEmpty(S2):
        return False
    elif not IsEmpty(S1) and not IsEmpty(S2):
        if IsAtom(FirstList(S1)) and IsAtom(FirstList(S2)):
            return FirstList(S1) == FirstList(S2) and IsEqs(TailList(S1),TailList(S2))
        elif IsList(FirstList(S1)) and IsList(FirstList(S2)):
            return FirstList(S1) == FirstList(S2) and IsEqs(TailList(S1),TailList(S2))
        else :
            return False
        
# IsMemberS : elemen, List of list -> boolean
# {IsMemberS(A,S) true jika A adalah anggota S}
def IsMemberS(A,S):
    if IsEmpty(S) :
        return False
    elif not IsEmpty(S):
        if IsAtom(FirstList(S)):
            return A == FirstList(S)
        elif IsList(FirstList(S)):
            return List.IsMember(A,FirstList(S)) or IsMemberS(A,TailList(S))


# IsMemberLS : List, List of list -> boolean
# {IsMemberLS(L,S) true jika L adalah anggota S}
def IsMemberLS(L,S):
    if IsEmpty(L) and IsEmpty(S):
        return False
    elif not IsEmpty(L) and IsEmpty(S):
        return False
    elif IsEmpty(L) and not IsEmpty(S):
        return False
    elif not IsEmpty(L) and not IsEmpty(S):
        if (IsAtom(FirstList(S))) :
            return IsMemberLS(L,TailList(S))
        elif (IsList(FirstList(S))) :
            if List.IsEqual(L,FirstList):
                return True
            else:
                return IsMemberLS(L,TailList(S))
    
# DEFINISI DAN SPESIFIKASI OPERATOR TERAHADAP LIST OS LIST
# Rember : elemen, List of list -> List of list
# {Rember(a,S) menghapus sebuah elemen bernilai a dari semua list S}
def Rember(a,S):
    if IsEmpty(S):
        return S
    elif IsList(FirstList(S)):
        return KonsLo(Rember(a,FirstList(S)), Rember(a,TailList(S)))
    else:
        if List.FirstElmt(S) == a :
            return Rember(a,TailList(S))
        else:
            return KonsLo(List.FirstElmt(S), Rember(a,TailList(S)))
        
# Max : List of list tidak kosong -> integer
# {Max(S) menghasilkan nilai elemen (atom) yang maksimum dari S}
def Max(S):
    if List.IsOneElmt(S):
        if IsAtom(FirstList(S)):
            return FirstList(S)
        else:
            return Max(FirstList(S))
    else:
        if IsAtom(FirstList(S)):
            return Max2(FirstList(S),Max(TailList(S)))
        else:
            return Max2(FirstList(S, Max(TailList(S))))


# Fungsi Perantara
# Max2 : 2 integer -> integer
# {Max2(a,b) menghasilkan nilai maksimum dari a dan b}
def Max2(a,b):
    if a >= b :
        return a
    else:
        return b


