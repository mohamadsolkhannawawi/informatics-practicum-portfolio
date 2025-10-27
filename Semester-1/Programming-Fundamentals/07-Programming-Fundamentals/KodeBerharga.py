def Konso(e,L):
    if L == []:
        return [e]
    else:
        return [e] + L

def IsEmpty(L):
    return L == []

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
    
def IsMember(X,L):
    if IsEmpty(L):
        return False
    elif X == FirstElmt(L):
        return True
    else:
        return IsMember(X,Tail(L))



def ConvertSTOI(s):
    StringToList = list('0123456789')
    if not s:
        return []
    elif IsMember(FirstElmt(s), StringToList):
        if FirstElmt(s) == '1':
            return Konso(1, ConvertSTOI(Tail(s)))
        elif FirstElmt(s) == '2':
            return Konso(2, ConvertSTOI(Tail(s)))
        elif FirstElmt(s) == '3':
            return Konso(3, ConvertSTOI(Tail(s)))
        elif FirstElmt(s) == '4':
            return Konso(4, ConvertSTOI(Tail(s)))
        elif FirstElmt(s) == '5':
            return Konso(5, ConvertSTOI(Tail(s)))
        elif FirstElmt(s) == '6':
            return Konso(6, ConvertSTOI(Tail(s)))
        elif FirstElmt(s) == '7':
            return Konso(7, ConvertSTOI(Tail(s)))
        elif FirstElmt(s) == '8':
            return Konso(8, ConvertSTOI(Tail(s)))
        elif FirstElmt(s) == '9':
            return Konso(9, ConvertSTOI(Tail(s)))
        elif FirstElmt(s) == '0':
            return Konso(0, ConvertSTOI(Tail(s)))
    else:
        return ConvertSTOI(Tail(s))
    
def Increment(L):
    if IsEmpty(L):
        return []
    else:
        return FirstElmt(L) + Increment(Tail(L))
    
def SumKodeBerharga(L):
    return str(Increment(ConvertSTOI(L))) + " Milyar"

print(SumKodeBerharga('Inv35t4s1'))
        

        