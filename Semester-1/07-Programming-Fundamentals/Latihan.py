# Nama File : rekursif.py
# Deskripsi : Membuat modul terkait fungsi rekursif
# Pembuat   : Mohamad Solkhan Nawawi
# Tanggal   : 2 November 2023

#Plus:integer --> integer
#{Plus(x,y) mengembalikan nilai x dijumlahkan dengan
#y dengan fungsi rekursif}
#Realisasi dalam python
def Plus(x,y):
  if y == 0 :
    return x
  else :
    return 1 + Plus(x, y-1)
  
print(Plus(1,4))   

#Sub:integer --> integer
#{Sub(x,y) mengembalikan nilai x dikurangi dengan
# y dengan fungsi rekursif}
#Realisasi dalam python
def Min(x,y):
  if y == 0 :
    return x
  else :
    return Min(x,y-1) - 1
  
print(Min(8,5))

#Mul:integer --> integer
#{Mul(x,y) mengembalikan nilai x dikali dengan 
# y dengan fungsi rekursif}
#Realisasi dalam python
def Mul(x,y):
  if y == 0 :
    return 0
  else :
    return x + Mul(x,y-1)
  
print(Mul(6,5))

#Dis:integer --> integer
#{Dis(x,y) mengembalikan nilai x dibagi dengan
# y dengan fungsi rekursif}
#Realisasi dalam python
def Dis(x,y):
  if x < y :
    return 0
  else :
    return 1 + Dis(x-y,y)
  
print(Dis(7,1))

#Exp:integer --> integer
#{Exp(x,y) mengembalikan nilai x dipangkat dengan
# y dengan fungsi rekursif}
#Realisasi dalam python
def Exp(x,y):
  if y == 0 :
    return 1
  else :
    return x * Exp(x,y-1)
  
print(Exp(3,2))

#Deretint:integer --> integer
#{Deretint(n) mengembalikan jumlah deret integer
# Deretint(6) = 1+2+3+4+5+6 , output 21}
#Realisasi dalam python
def DeretInt(n):
  if n == 0 :
    return 0
  # elif n == 1:
  #   return 1
  else :
    return n + DeretInt(n-1)
  
print(DeretInt(1))

#Deretbeda3:integer --> integer
#{Deretbeda3(n) mengembalikan jumlah deret 
# aritmatika beda 3 dengan Deretbeda3(2) = 3+6, output 9}
#Realisasi dalam python

def Deretbeda3(n):
  if n == 0 :
    return 0
  else:
    return n*3 + Deretbeda3(n-1)
  
print(Deretbeda3(2))


#Deretgeo3:integer --> integer
#{Deretgeo3(n) mengembalikan jumlah deret 
# geometri r=3 dengan Deretgeo3(2) = 1+3, output 4}
#Realisasi dalam python
def Deretgeo3(n):
  if n == 0 :
    return 0
  # elif n == 1 :
  #   return 1
  else :
    return 3**(n-1) + Deretgeo3(n-1)
  
print(Deretgeo3(2))


#Deretkubik:integer --> integer
#{Deretkubik(n) mengembalikan jumlah deret 
# dengan Deretkubik(3) = 1+4+9, output 14}
#Realisasi dalam python
def Deretkubik(n):
  if n == 0 :
    return 0
  else :
    return n**2 + Deretkubik(n-1)
  

print(Deretkubik(3))
print(Deretkubik(4))
print(Deretkubik(8))
  