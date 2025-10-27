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

def Head(L):
    if L == []:
        return []
    else:
        return L[:-1]
    
def Tail(L):
    if L == []:
        return []
    else:
        return L[1:]

def IsEmpty(L):
    return L == []

def IsOneElmt(L):
    return Head(L) == [] 

def Max(a,b):
    if a >= b :
        return a
    else:
        return b
    
def DeleteElm(L1, X):
    if IsEmpty(X):
        return []
    else:
        if FirstElmt(X) == L1:
            return Tail(X)
        else:
            return Konso(FirstElmt(X), DeleteElm(L1,Tail(X)))
    
def IsMember(X,L):
    if IsEmpty(L):
        return False
    elif X == FirstElmt(L):
        return True
    else:
        return IsMember(X,Tail(L))
          
def maxList(S):
    if IsOneElmt(S):
        return FirstElmt(S)
    else:
        return Max(FirstElmt(S),maxList(Tail(S)))
            
  
def DescendingSortUnique(L):
    if IsEmpty(L) :
        return []
    else:
        if IsMember(maxList(L),DeleteElm(maxList(L),L)):
            return DescendingSortUnique(DeleteElm(maxList(L), L))
        else:
            return Konso(maxList(L), DescendingSortUnique(DeleteElm(maxList(L), L)))
        
print(DescendingSortUnique([70, 67, 13, 98, 10, 20]))
  

  
# def DeleteElm(L1, X):
#     if IsEmpty(X):
#         return []
#     else:
#         if FirstElmt(X) == L1:
#             return Tail(X)
#         else:
#             return Konso(FirstElement(X), DeleteElm(L1,Tail(X)))
        
# def IsMember(X,L):
#     if IsEmpty(L):
#         return False
#     elif X == FirstElement(L):
#         return True
#     else:
#         return IsMember(X,Tail(L))

# def IsAtom(S):
#     if isinstance(S, (int, float, str, bytes, bool, type(None))):
#         return True
#     else:
#         return False
    
# def FirstList(S):
#     if S == [] :
#         return None
#     else:
#         return S[0]
    
# def TailList(S):
#     if S == [] :
#         return None
#     else:
#         return S[1:]

# def Max(a,b):
#     if a >= b :
#         return a
#     else:
#         return b
          
# def maxList(S):
#     if IsOneElmt(S):
#         return FirstElement(S)
#     else:
#         return Max(FirstElement(S),maxList(Tail(S)))
            
  
# def DescendingSortUnique(L):
#     if IsEmpty(L) :
#         return []
#     else:
#         if IsMember(maxList(L),DeleteElm(maxList(L),L)):
#             return DescendingSortUnique(DeleteElm(maxList(L), L))
#         else:
#             return Konso(maxList(L), DescendingSortUnique(DeleteElm(maxList(L), L)))
        
# print(DescendingSortUnique([70, 67, 13, 98, 10, 20]))
  
