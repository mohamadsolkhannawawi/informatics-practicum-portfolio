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
    
def FirstList(S):
    if S == [] :
        return None
    else:
        return S[0]
    
def TailList(S):
    if S == [] :
        return []
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

def NbElmt(L):
  if IsEmpty(L) :
    return 0
  else :
    return 1 + NbElmt(Tail(L))

def Konkat(L1,L2) :
  if IsEmpty(L1) :
    return L2
  else :
    return Konso(FirstElmt(L1),Konkat(Tail(L1),L2))
  
def ConcatAll(L):
    if IsEmpty(L):
        return []
    else:
        if IsList(FirstList(L)):
            return ConcatAll(Konkat(FirstList(L),TailList(L)))
        else:
            return Konkat(Konso(FirstList(L), []), ConcatAll(TailList(L)))
        
def NbElmt(L):
  if IsEmpty(L) :
    return 0
  else :
    return 1 + NbElmt(Tail(ConcatAll(L)))

def TotalList(L) :
    if IsEmpty(L):
        return 0
    else :
        return FirstList(ConcatAll(L)) + TotalList(TailList(ConcatAll(L)))
    
def Average(L) :
   if NbElmt(L) == 0 :
      return 0
   else :
      return TotalList(L) / NbElmt(L)

def hapusPasukanKuat(LoL, Avg):
    def hapusKuatList(L):
        if IsEmpty(L):
            return []
        elif FirstElmt(L) < Avg:
            return Konso(FirstElmt(L), hapusKuatList(Tail(L)))
        else:
            return hapusKuatList(Tail(L))

    def hapusKuatLoL(LoL):
        if IsEmpty(LoL):
            return []
        elif IsList(FirstList(LoL)):
            return Konso(hapusKuatList(FirstList(LoL)), hapusKuatLoL(TailList(LoL)))
        else:
            return Konso([], hapusKuatLoL(TailList(LoL)))

    return hapusKuatLoL(LoL)

import ast
LoL=ast.literal_eval(input())
Avg = Average(LoL)
print(hapusPasukanKuat(LoL,Avg))


