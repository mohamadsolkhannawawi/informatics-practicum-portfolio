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
    
def IsOneElmt(L) :
  if Tail(L) == [] :
    return True
  else :
    return False
  
def IsEmpty(L):
    if (L == []) :
        return True
    else :
        return False
    
def IsList(S):
    return isinstance(S, list)
  
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
    
def MaxList(S):
    if IsOneElmt(S):
        if IsAtom(FirstList(S)):
            return FirstList(S)
        else:
            return MaxList(FirstList(S))
    else:
      return Max(FirstList(S),MaxList(TailList(S)))
      

def levelMax(L) :
    if IsEmpty(L) :
        return []
    elif IsList(FirstList(L)) :
        return Konso(MaxList(FirstList(L)), levelMax(TailList(L)))
    else :
        return levelMax(TailList(L))
    
def totalLevel(L) :
    if IsEmpty(L) :
        return 0
    else :
        return FirstList(L) + totalLevel(Tail(L))

def biaya(LoL,inp,inp2) :
    return totalLevel(levelMax(LoL)) * 1000000

import ast
list_of_list = ast.literal_eval(input())
inp = int(input())
inp2 = int(input())
print(biaya(list_of_list, inp, inp2))