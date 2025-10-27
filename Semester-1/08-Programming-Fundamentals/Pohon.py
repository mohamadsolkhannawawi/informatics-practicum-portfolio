#DEFINISI DAN SPESIFIKASI 
#Type PohonBiner : <A : elemen, L : PohonBiner, R : PohonBiner >
#<A,L,R> adalah type bentukan pohon biner dimana A adalah akar, l adalah daun kiri, R adalah daun kanan
class PohonBiner :
    def __init__(self,A,L,R):
        self.A = A
        self.L = L
        self.R = R

#DEFINISI DAN SPESIFIKASI 
#MakePB : 3 integer ---> PohonBiner
#MakePB(A,L,R) : menghasilkan pohon biner dengan A adalah akar, L adalah dan kiri, R adalah daun kanan
def MakePB(A,L,R):
    return PohonBiner((A,L,R))

# #IsTreeEmpty : Pohon biner --> boolean
# #  {IsTreeEmpty(P) true jika P adalah Pohon biner kosong}
# def IsTreeEmpty(P):
#     if P == ():
#         return True
#     else:
#         return False

#Fungsi akar 
#DEFINISI DAN SPESIFIKASI
#Akar(P) pohon biner tak kosong --> pohon biner
def Akar(P) :
    return P.A

#Fungsi Left
#DEINITI DAN SPESIFIKASI
#Left : pohon biner tak kosong --> pohon biner
#Left(P) : sub pohon kiri dari P jika /L,A,R\ maka left(P) adalah L
def Left(P) :
    return P.L
    
