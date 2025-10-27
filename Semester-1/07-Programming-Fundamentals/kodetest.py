def Konso(e,L):
    if L == []:
        return [e]
    else:
        return [e] + L

def Konsi(L,e):
    if L == []:
        return [e]
    else:
        return L + [e] 

def FirstElmt(L):
    if L == [] :
        return None
    else:
        return L[0]
    
def LastElmt(L):
    if  L == []:
        return None
    else:
        return L[-1]

def Tail(L):
    if L == []:
        return []
    else:
        return L[1:]
    
def Head(L):
    if L == []:
        return []
    else:
        return L[:-1]

def IsEmpty(L):
    return L == []

def IsMember(X,L):
    if IsEmpty(L):
        return False
    elif X == FirstElmt(L):
        return True
    else:
        return IsMember(X,Tail(L))
    
def STLOI(s):
    integer = list('0123456789')
    if not s:
        return []
    elif IsMember(FirstElmt(s), integer):
        if FirstElmt(s) == '1':
            return Konso(1, STLOI(Tail(s)))
        elif FirstElmt(s) == '2':
            return Konso(2, STLOI(Tail(s)))
        elif FirstElmt(s) == '3':
            return Konso(3, STLOI(Tail(s)))
        elif FirstElmt(s) == '4':
            return Konso(4, STLOI(Tail(s)))
        elif FirstElmt(s) == '5':
            return Konso(5, STLOI(Tail(s)))
        elif FirstElmt(s) == '6':
            return Konso(6, STLOI(Tail(s)))
        elif FirstElmt(s) == '7':
            return Konso(7, STLOI(Tail(s)))
        elif FirstElmt(s) == '8':
            return Konso(8, STLOI(Tail(s)))
        elif FirstElmt(s) == '9':
            return Konso(9, STLOI(Tail(s)))
        elif FirstElmt(s) == '0':
            return Konso(0, STLOI(Tail(s)))
    else:
        return STLOI(Tail(s))

def Total_List(L):
    if not L:
        return 0
    else:
        return FirstElmt(L) + Total_List(Tail(L))
    
def Output_Final(x):
    return str(Total_List(STLOI(x))) + " Milyar"


input_data = input()
print(Output_Final(input_data))