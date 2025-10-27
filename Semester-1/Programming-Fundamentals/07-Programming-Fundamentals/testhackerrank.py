def Konso(e,L):
    if L == []:
        return [e]
    else:
        return [e] + L

def IsEmpty(S):
    return ( S == [])

def FirstElement(L):
    if L == [] :
        return None
    else:
        return L[0]
    
def Tail(L):
    if L == []:
        return []
    else:
        return L[1:]
    
def IsOneElmt(L):
    return Tail(L) == []

def IsMember(X,L):
    if IsEmpty(L):
        return False
    elif X == FirstElement(L):
        return True
    else:
        return IsMember(X,Tail(L))

def Max(a,b):
    if a >= b :
        return a
    else:
        return b
    
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
    
def TailList(S):
    if S == [] :
        return None
    else:
        return S[1:]

def maxList(S):
    if IsOneElmt(S):
        if IsAtom(FirstList(S)):
            return FirstList(S)
        else:
            return maxList(FirstList(S))
    else:
        if IsAtom(FirstList(S)):
            return Max(FirstList(S),maxList(TailList(S)))
        else:
            return Max(FirstList(S),maxList(TailList(S)))

def DescendingSortUnique(L):
    if IsEmpty(L) :
        return []
    else:
        if IsMember(maxList(L),Tail(L)) :
            return DescendingSortUnique(Tail(L))
        else:
            return Konso(maxList(L),DescendingSortUnique(Tail(L)))
        
print(DescendingSortUnique([2, 6, 10, 99, 100, 20]))


        