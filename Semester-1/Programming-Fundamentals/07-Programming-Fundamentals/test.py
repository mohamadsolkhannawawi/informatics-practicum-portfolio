def konso(e,L):
    if L == []:
        return [e]
    else:
        return [e] + L

#Konsi(e,L): menambahkan elemen e kepada list sebagai last elemen list
#output : List
def konsi(e,L):
    if L == []:
        return [e]
    else:
        return L + [e]

#FirstElmt(L): mengembalikan elemen pertama dari sebuah list
#output : character
def FirstElmt(L):
    if L == [] :
        return None
    else:
        return L[0]
    
# LastElmt : List tidak kosong -> elemen
# {LastElmt(L) Menghasilkan elemen terakhir list L}
def LastElmt(L):
    if  L == []:
        return None
    else:
        return L[-1]

#tail(L): mengembalikan list selain first elemen list
#output : list
def tail(L):
    if L == []:
        return []
    else:
        return L[1:]
    
# Head : List tidak kosong -> List
# {Head(L) Menghilangkan list tanpa elemen terakhir list L, mungkin kosong}
def Head(L):
    if L == []:
        return []
    else:
        return L[:-1]
    
# IsEmpty : List -> boolean
# {IsEmpty(L) benar jika list kosong}   
def IsEmpty(L):
    return L == []

#ToString(L): mengembalikan list ke dalam bentuk string
#output : string
def ToString(L):
  return ''.join(L)
def konso(e,L):
    if L == []:
        return [e]
    else:
        return [e] + L
    
def DNA (a,b,c,d,e,f,g,h):
    return [a,b,c,d,e,f,g,h]

def nucleotideX (DNA,X):
    if X == 1 :
        return FirstElmt(DNA)
    else :
        return nucleotideX(X-1, tail(DNA))
    
def DNAtoRNA (DNA):
    if DNA == [] :
        return []
    elif FirstElmt(DNA) == 'A' :
        return konso('U', DNAtoRNA(tail(DNA)))
    elif FirstElmt(DNA) == 'C' :
        return konso('G', DNAtoRNA(tail(DNA)))
    elif FirstElmt(DNA) == 'G' :
        return konso('C', DNAtoRNA(tail(DNA)))
    elif FirstElmt(DNA) == 'T' :
        return konso('A', DNAtoRNA(tail(DNA)))
    else :
        return None
    
def StringDNAtoRNA (DNA):
    return ToString(DNAtoRNA(DNA))

def DNAtoBinary (DNA):
    if DNA == [] :
        return []
    elif FirstElmt(DNA) == 'A' :
        return konso('00', DNAtoBinary(tail(DNA)))
    elif FirstElmt(DNA) == 'C' :
        return konso('01', DNAtoBinary(tail(DNA)))
    elif FirstElmt(DNA) == 'G' :
        return konso('10', DNAtoBinary(tail(DNA)))
    elif FirstElmt(DNA) == 'T' :
        return konso('11', DNAtoBinary(tail(DNA)))
    else :
        return None
    
def StringDNAtoBinary(DNA):
    return ToString(DNAtoBinary(DNA))

# 0001101111011011
def NbNeuclotide(DNA):
    if (DNA == [] ) :
        return 0
    elif FirstElmt(DNA) == '' :
        return NbNeuclotide(tail(DNA))
    else:
        return 1 + NbNeuclotide(tail(DNA))
    
def ManyX(DNA,X):
    if (DNA == [] ) :
        return 0
    elif FirstElmt(DNA) == X :
        return 1 + ManyX(tail(DNA),X)
    else:
        return ManyX(tail(DNA),X)
    
def FrekuensiX(DNA,X):
    return ManyX(DNA,X) / NbNeuclotide(DNA)

def InversRNA(DNA):
    if IsEmpty(DNA):
        return []
    else:
        return konso(LastElmt(DNA),InversRNA(Head(DNA)))
  



    
print(DNA('A','C','G','T','T','C','G','T'))
print(nucleotideX(DNA('A','C','G','T','T','C','G','T'),1))
print(DNAtoRNA(DNA('A','C','G','T','T','C','G','T')))
print(StringDNAtoRNA(DNA('A','C','G','T','T','C','G','T')))
print(DNAtoBinary(DNA('A','C','G','T','T','C','G','T')))
print(StringDNAtoBinary(DNA('A','C','G','T','T','C','G','T'))
)
print(NbNeuclotide((DNA('','C','','T','T','C','G','T'))))
print(ManyX((DNA('A','C','C','T','T','C','G','T')),'T'))
print(FrekuensiX((DNA('A','C','C','T','T','C','G','T')),'T'))
print(InversRNA(DNA('A','C','G','T','T','C','G','T')))


    
