#Nama File : Soal1.py
#Pembuat   : Mohamad Solkhan Nawawi
#Tanggal   : 12 November 2023
#Deskripsi : fungsi yang menghasilkan nilai maksimum kedua dari sebuah list


a = [1,2,3,4,5,6,7,8,9,10]


def Konso(e,L):
  if L == [] :
    return [e]
  else :
    return [e] + L

def FirstElmt(L) :
  return L[0]

def IsEmpty(L):
    if (L == []) :
        return True
    else :
        return False

def Tail(L):
    if (L == []):
        return []
    else:
        return L[1:]

def NbElmt(L):
    if IsEmpty(L) :
        return 0
    else:
        return 1 + NbElmt(Tail(L))

def TailList(S):
    if S == [] :
        return None
    else:
        return S[1:]

def IsAtom(S):
    if isinstance(S, (int, float, str, bytes, bool, type(None))):
        return True
    else:
        return False

def FirstList(S):
    if S == [] :
        return None
    else:
        return S[0]
    
def IsOneElmt(L) :
  if Tail(L) == [] :
    return True
  else :
    return False

def Max(a,b):
    if a >= b :
        return a
    else:
        return b

def MaxList(S):
    if IsOneElmt(S):
        if IsAtom(FirstList(S)):
            return FirstList(S)
        else:
            return MaxList(FirstList(S))
    else:
        if IsAtom(FirstList(S)):
            return Max(FirstList(S),MaxList(TailList(S)))
        else:
            return Max(FirstList(S),MaxList(TailList(S)))
print(MaxList([1,2,3,4,5,6,7,8,9]))       

def Rember(e, L):
    if IsEmpty(L):
        return []
    else:
        if FirstElmt(L) == e:
            return Tail(L)
        else:
            return Konso(FirstElmt(L), Rember(e, Tail(L)))


def MaxList2(S):
    return MaxList(Rember(MaxList(S),S))

print(MaxList2(a))
