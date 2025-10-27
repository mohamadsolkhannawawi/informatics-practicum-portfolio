def FirstElmt(L) :
    return L[0]

def TailElmt(L) :
    return L[1:]

def NBElmtX(X, L) :
    if (L == '') :
        return 0
    elif X == FirstElmt(L) :
        return 1 + NBElmtX(X, TailElmt(L))
    else :
        return NBElmtX(X, TailElmt(L))
    

print(NBElmtX('a', 'alamat'))
print(NBElmtX('o', 'ilmu komputer dan informatika'))