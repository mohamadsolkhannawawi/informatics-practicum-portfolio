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
  
def IsEmpty(L) :
  if L == [] :
    return True
  else :
    return False
  
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
        
def IsPrima(n,i=2) :
  if n < 2 :
    return False
  elif n == 2 :
    return True
  elif n % i == 0 :
    return False
  elif i*i > n :
    return True
  else :
    return IsPrima(n,i+1)
  
def jumlahPrima(L):
   if IsEmpty(L) :
      return 0
   elif IsPrima(FirstElmt(ConcatAll(L))):
      return FirstElmt(ConcatAll(L)) + jumlahPrima(Tail(ConcatAll(L)))
   else :
      return jumlahPrima(Tail(ConcatAll(L)))
    
import ast
list_of_list = ast.literal_eval(input())
print(jumlahPrima(list_of_list))