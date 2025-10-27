def IsAtom(S):
    return isinstance(S, list) and len(S) == 1 and not isinstance(S[0], list)

def IsList(S):
    return not IsAtom(S)

def IsEmpty(S):
    return S == []

def KonsLo(L,S):
    if L == []:
        return [L]
    else:
        return [L] + S
    
def KonsLi(L,S):
    if L == []:
        return [L]
    else:
        return S + [L]
    
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
    
def LastList(S):
    if S == [] :
        return None
    else:
        return S[-1]
        
def HeadList(S):
    if S == [] :
        return None
    else:
        return S[:-1]