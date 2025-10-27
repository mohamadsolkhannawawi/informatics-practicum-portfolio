def MakeTreeNAry(A, PN):
    return [A, PN]

def Akar(T):
    return T[0]

def Anak(T):
    return T[1]

def FirstElmt(L):
    return L[0]
  
def LastElmt(L):
    return L[-1]
  
def Head(L):
    return L[:-1]
  
def Tail(L):
    return L[1:]
  
def IsEmpty(L):
    return len(L) == 0

def PrintTreeNAryHelp(T, sisa, indent):
    print(indent + Akar(T))
    if not IsEmpty(Anak(T)):
        PrintTreeNAryHelp(FirstElmt(Anak(T)), Tail(Anak(T)), indent + '\t')
    if not IsEmpty(sisa):
        PrintTreeNAryHelp(FirstElmt(sisa), Tail(sisa), indent)

def PrintTreeNAry(T):
    PrintTreeNAryHelp(T, [], '')

def NbNElmtHelp(T, sisa):
    if IsEmpty(Anak(T)):
        if not IsEmpty(sisa):
            return 1 + NbNElmtHelp(FirstElmt(sisa), Tail(sisa))
        else:
            return 1
    else:
        if not IsEmpty(sisa): 
            return 1 + NbNElmtHelp(FirstElmt(Anak(T)), Tail(Anak(T))) + NbNElmtHelp(FirstElmt(sisa), Tail(sisa))
        else:
            return 1 + NbNElmtHelp(FirstElmt(Anak(T)), Tail(Anak(T)))
        
def NbNElmt(T):
    return NbNElmtHelp(T, [])
        
def NbNDaunHelp(T, sisa):
    if IsEmpty(Anak(T)):
        if not IsEmpty(sisa):
            return 1 + NbNDaunHelp(FirstElmt(sisa), Tail(sisa))
        else:
            return 1
    else:
        if not IsEmpty(sisa): 
            return NbNDaunHelp(FirstElmt(Anak(T)), Tail(Anak(T))) + NbNDaunHelp(FirstElmt(sisa), Tail(sisa))
        else:
            return NbNDaunHelp(FirstElmt(Anak(T)), Tail(Anak(T)))
        
def NbNDaun(T):
    return NbNDaunHelp(T, [])
        
T = MakeTreeNAry('Yuki', [MakeTreeNAry('Asuna', []), MakeTreeNAry('Akame', [MakeTreeNAry('Kuro', [MakeTreeNAry('Suzu', [])]), MakeTreeNAry('Frieren', []), MakeTreeNAry('Fren', [])]), MakeTreeNAry('Shiro', [])])
PrintTreeNAry(T)
print('Jumlah Elemen:', NbNElmt(T))
print('Jumlah Daun:', NbNDaun(T))