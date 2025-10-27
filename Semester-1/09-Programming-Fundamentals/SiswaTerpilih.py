def IsEmpty(S):
    return S == []

def FirstList(S):
    if S == [] :
        return None
    else:
        return S[0]
    
def LastList(S):
    if S == [] :
        return None
    else:
        return S[-1]
    
def TailList(S):
    if S == [] :
        return None
    else:
        return S[1:]

def SiswaTerpilih(Siswa,LoL) :
    if IsEmpty(LoL):
        return "Siswa itu tidak ada di kelas ini"
    elif Siswa == FirstList(FirstList(LoL)) :
        return LastList(FirstList((LoL)))
    else :
        return SiswaTerpilih(Siswa,(TailList(LoL)))

import ast
LoL = ast.literal_eval(input())
siswa = str(input())

print(SiswaTerpilih(siswa,LoL))