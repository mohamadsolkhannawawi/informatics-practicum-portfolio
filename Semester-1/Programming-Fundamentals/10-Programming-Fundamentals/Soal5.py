def Point(a,b) :
    return [a,b]

def Absis(P) :
    return P[0]

def Ordinat(P) :
    return P[1]

def Jarak(P1,P2) :
    return ((Absis(P1)-Absis(P2))**2 + (Ordinat(P1)-Ordinat(P2))**2)**0.5

def FirstElmt(L) :
    if L == [] :
        return None
    else :
        return L[0]

def Tail(L):
    return L[1:]

def IsOneElmt(L) :
    return (Tail(L) == [])
  
def NearestPoint(P, LP):
    if IsOneElmt(LP):
        return FirstElmt(LP)
    else :
        if Jarak(P, NearestPoint(P, Tail(LP))) < Jarak(P, FirstElmt(LP)):
            return NearestPoint(P, Tail(LP))
        else:
            return FirstElmt(LP)

print(NearestPoint(Point(1,2),[Point(0,0),Point(3,4),Point(6,7),Point(1,1),Point(2,1)]))

