#Nama File : point.py
#Pembuat   : Abisatya Hastarangga Pradana-24060122120004
#Tanggal   : 29 September 2023

# DEFINISI DAN SPESIFIKASI TYPE
# type Pecahan : <a : real, b: real>
# <a,b> adalah sebuah Pecahan, dengan a adalah pembilang dan  b adalah penyebut
 
def pecahan(a,b):
  return [a,b]

def pembilang(P):
  return P[0]

def penyebut(P):
  return P[1]

def Add(p,q):
  return (pembilang(p)*penyebut(q) + pembilang(q)*penyebut(p)),penyebut(p)*penyebut(q)

def Sub(p,q):
  return (pembilang(p)*penyebut(q) - pembilang(q)*penyebut(p),penyebut(p)*penyebut(q))

def Mul(p,q):
  return (pembilang(p)*pembilang(q),penyebut(p)*penyebut(q))

def Div(p,q):
  return (pembilang(p)*penyebut(q),penyebut(p)*pembilang(p))

def Real(P):
  return (pembilang(P)/penyebut(P))

def IsEq(p,q):
  return (pembilang(p)/penyebut(p) == pembilang(q)/penyebut(q))

def IsLt(p,q):
  return (pembilang(p)/penyebut(p) < pembilang(q)/penyebut(q))

def IsGt(p,q):
  return (pembilang(p)/penyebut(p) > pembilang(q)/penyebut(q))


Pecahan1 = pecahan(1,2)
Pecahan2 = pecahan(1,2)

print(Add(Pecahan1,Pecahan2))
print(Sub(Pecahan1,Pecahan2))
print(Mul(Pecahan1,Pecahan2))
print(Div(Pecahan1,Pecahan2))
print(IsEq(Pecahan1,Pecahan2))
print(IsLt(Pecahan1,Pecahan2))
print(IsGt(Pecahan1,Pecahan2))
print(Real(Pecahan1))
