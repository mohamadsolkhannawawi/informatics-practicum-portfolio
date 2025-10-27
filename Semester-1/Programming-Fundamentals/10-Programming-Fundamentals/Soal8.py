def Konso(e,L):
    if L == []:
        return [e]
    else:
        return [e] + L
    
def FirstElmt(L):
    if L == [] :
        return None
    else:
        return L[0]
    
def Tail(L):
    if L == []:
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

def IsList(S):
    return isinstance(S, list)

def IsAtom(S):
    if isinstance(S, (int, float, str, bytes, bool, type(None))):
        return True
    else:
        return False

def SumAtomOfList(S) :
    if IsEmpty(S):
        return 0
    else :
        return FirstElmt(S) + SumAtomOfList(Tail(S))
    
def MakeListAtom(S) :
    if IsEmpty(S):
        return []
    elif IsList(FirstElmt(S)) :
        return Konso(SumAtomOfList(FirstList(S)), MakeListAtom(Tail(S)))
    else : 
        return Konso(FirstElmt(S), MakeListAtom(Tail(S)))
        
print(MakeListAtom(([3, [2, 4, 5], [1, 3], [6, 4, 1, 2], 7, [2]])))

