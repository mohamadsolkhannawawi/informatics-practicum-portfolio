#Nama File : Soal7.py
#Pembuat   : Mohamad Solkhan Nawawi
#Tanggal   : 13 November 2023
#Deskripsi : sebuah fungsi yang mengembalikan banyaknya elemen atom bernilai ganjil
#            yang ada pada sebuah list of list. Jika list kosong, maka akan mengembalikan nilai 0.

def Konso(e,L):
  if L == [] :
    return [e]
  else :
    return [e] + L

def FirstElmt(L) :
    if L == [] :
        return None
    else :
        return L[0]
    
def Tail(L):
    if L == [] :
        return []
    else:
        return L[1:]
    
def Konkat(L1,L2) :
  if IsEmpty(L1) :
    return L2
  else :
    return Konso(FirstElmt(L1),Konkat(Tail(L1),L2))
  
def FirstList(S):
    if S == [] :
        return None
    else:
        return S[0]
    
def TailList(S):
    if S == [] :
        return None
    else:
        return S[1:]

def IsEmpty(S):
    return S == []

def IsAtom(S):
    if isinstance(S, (int, float, str, bytes, bool, type(None))):
        return True
    else:
        return False

def IsList(S) :
    return isinstance(S, list)

  
def KonkatAll(L):
    if IsEmpty(L):
        return []
    else:
        if IsList(FirstList(L)):
            return KonkatAll(Konkat(FirstList(L),TailList(L)))
        else:
            return Konkat(Konso(FirstList(L), []), KonkatAll(TailList(L)))
        
def NBOdds(S) :
    if IsEmpty(S) :
        return 0
    else :
        if FirstElmt(KonkatAll(S)) % 2 == 0 :
            return NBOdds(Tail(S))
        else :
            return 1 + NBOdds(Tail(KonkatAll(S)))

#APLIKASI       
print(NBOdds([3, [2, 4, 5], [6, 3], [6, 4, 1, 2], 7, [2]]))
print(NBOdds([3, [2, 4, 5], [6, 3], [6, 4, 1, 2], 7, [21]]))
