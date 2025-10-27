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
        
def NBOdds(S) :
    if IsEmpty(S) :
        return 0
    else :
        if FirstElmt(ConcatAll(S)) % 2 == 0 :
            return NBOdds(Tail(S))
        else :
            return 1 + NBOdds(Tail(ConcatAll(S)))
        
print(NBOdds([3, [2, 4, 5], [6, 3], [6, 4, 1, 2], 7, [2]]))

