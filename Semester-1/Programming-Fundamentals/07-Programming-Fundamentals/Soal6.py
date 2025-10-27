#Nama File : Soal6.py
#Pembuat   : Mohamad Solkhan Nawawi
#Tanggal   : 13 November 2023
#Deskripsi : sebuah fungsi yang mengembalikan nilai minimum dari atom-atom
#            yang ada pada sebuah list of list yang tidak kosong

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

def LastElmt(L):
    if  L == []:
        return None
    else:
        return L[-1]
    
def Tail(L):
    if L == [] :
        return []
    else:
        return L[1:]
    
def IsEmpty(L):
    return L == []
    
def IsOneElmt(L) :
  if Tail(L) == [] :
    return True
  else :
    return False
  
def Konkat(L1,L2) :
  if IsEmpty(L1) :
    return L2
  else :
    return Konso(FirstElmt(L1),Konkat(Tail(L1),L2))
    
def IsMember(X,L):
    if IsEmpty(L):
        return False
    elif X == FirstElmt(L):
        return True
    else:
        return IsMember(X,Tail(L))
    
def Rember(e, L):
    if IsEmpty(L):
        return []
    else:
        if FirstElmt(L) == e:
            return Tail(L)
        else:
            return Konso(FirstElmt(L), Rember(e, Tail(L)))

def KonsLo(L,S) :  
    if L == [] :
        return [S]
    else :
        return [S] + L
    
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
    

def IsAtom(S) :
    if isinstance(S, (int, float, str, bytes, bool, type(None))):
        return True
    else:
        return False
    
def IsList(S) :
    return isinstance(S, list)
        
def Max(a,b):
    if a >= b :
        return a
    else:
        return b
    
def KonkatAll(L):
    if IsEmpty(L):
        return []
    else:
        if IsList(FirstList(L)):
            return KonkatAll(Konkat(FirstList(L),TailList(L)))
        else:
            return Konkat(Konso(FirstElmt(L), []), KonkatAll(TailList(L)))
        
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

def DescendingUnik(L):
    if IsEmpty(L) :
        return []
    else:
        if IsMember(MaxList(L),Rember(MaxList(L),L)):
            return DescendingUnik(Rember(MaxList(L), L))
        else:
            return Konso(MaxList(L), DescendingUnik(Rember(MaxList(L), L)))
        
def MinList(L):
    return LastElmt(DescendingUnik(KonkatAll(L)))



#APLIKASI     
print(MinList([3, [2, 4, 5], [6, 3], [6, 4, 1, 2], 7, [2]]))
print(KonkatAll([3, [2, 4, 5], [6, 3], [6, 4, 1, 2], 7, [2]]))
print(MaxList(KonkatAll([3, [2, 4, 5], [6, 3], [6, 4, 1, 2], 7, [2]])))
