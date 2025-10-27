#Nama File : Soal1.py
#Pembuat   : Mohamad Solkhan Nawawi
#Tanggal   : 13 November 2023
#Deskripsi : fungsi yang menghasilkan nilai maksimum kedua dari sebuah list.

def Konso(e,L):
  if L == [] :
    return [e]
  else :
    return [e] + L

def FirstElmt(L) :
  return L[0]

def Tail(L):
    if (L == []):
        return []
    else:
        return L[1:]

def IsEmpty(L):
    if (L == []) :
        return True
    else :
        return False
    
def IsOneElmt(L) :
  if Tail(L) == [] :
    return True
  else :
    return False

def NbElmt(L):
    if IsEmpty(L) :
        return 0
    else:
        return 1 + NbElmt(Tail(L))
 
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
    
def IsAtom(S):
    if isinstance(S, (int, float, str, bytes, bool, type(None))):
        return True
    else:
        return False

def Max(a,b):
    if a >= b :
        return a
    else:
        return b

def Rember(e, L):
    if IsEmpty(L):
        return []
    else:
        if FirstElmt(L) == e:
            return Tail(L)
        else:
            return Konso(FirstElmt(L), Rember(e, Tail(L)))

# def MaxList(S):
#     if IsOneElmt(S):
#         if IsAtom(FirstList(S)):
#             return FirstList(S)
#         else:
#             return MaxList(FirstList(S))
#     else:
#         if IsAtom(FirstList(S)):
#             return Max(FirstList(S),MaxList(TailList(S)))
#         else:
#             return Max(FirstList(S),MaxList(TailList(S)))
def MaxList(L):
    if IsEmpty(L):
        return 0
    elif IsOneElmt(L):
        return FirstElmt(L)
    else:
        return Max(FirstElmt(L),MaxList(TailList(L)))

def MaxList2(S):
    return MaxList(Rember(MaxList(S),S))

#APLIKASI
print(MaxList2([2, 6, 10, 99, 100, 20]))
print(MaxList2([70, 67, 13, 98, 10, 20]))

