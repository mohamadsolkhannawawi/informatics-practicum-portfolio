def FirstElmt(L) :
  return L[0]

def Konso(e,L):
  if L == [] :
    return [e]
  else :
    return [e] + L
  
def Tail(L):
  return L[1:]
  
def IsEmpty(L) :
  if L == [] :
    return True
  else :
    return False
  
def NbElmt(L):
  if IsEmpty(L) :
    return 0
  else :
    return 1 + NbElmt(Tail(L))
  
def KaliList(L1,L2):
  if IsEmpty(L1) and IsEmpty(L2):
    return []
  elif NbElmt(L1) == NbElmt(L2):
    return Konso(FirstElmt(L1)*FirstElmt(L2),KaliList(Tail(L1),Tail(L2)))
  else :
    return None


print(KaliList([2, 4, 6], [1, 2, 3]))