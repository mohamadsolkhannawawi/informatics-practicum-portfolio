# Nama File : segitiga.py
# Deskripsi : membuat tipe bentukan segitiga beserta konstruksi dan selektornya
# Pembuat   : 
# Tanggal   : 

from math import sqrt
import point

# DEFINISI TYPE
# type segitiga : <a:point, b:point, c:point>
# {<a, b, c> adalah sebuah segitiga, dengan a, b, dan c adalah titik sudut segitiga}

# DEFINISI DAN SPESIFIKASI KONSTRUKTOR
# MakeSegitiga: 3 point --> segitiga
# { segitiga(a, b, c) membentuk sebuah segitiga dari titik (point) a, b, dan c } 
# Realisasi dalam Python
def make_segitiga(a,b,c):
  return [a,b,c]


# DEFINISI DAN SPESIFIKASI SELEKTOR
# getA: segitiga --> point
# { getA(S) mengembalikan titik A dari segitiga S }
# Realisasi dalam Python
def getA(S):
  return S[0]


# getB: segitiga --> point
# { getB(S) mengembalikan titik B dari segitiga S }
# Realisasi dalam Python
def getB(S):
  return S[1]


# getC: segitiga --> point
# { getC(S) mengembalikan titik C dari segitiga S }
# Realisasi dalam Python
def getC(S):
  return S[2]


# SisiA: segitiga --> real
# { SisiA(S) mengembalikan panjang sisi yang berseberangan dengan titik a }
# Realisasi dalam Python
def SisiA(S):
  return jarak(getB(S),getC(S))



# SisiB: segitiga --> real
# { SisiB(S) mengembalikan panjang sisi yang berseberangan dengan titik b }
# Realisasi dalam Python
def SisiB(S):
  return jarak(getA(S),getC(S))


# SisiC: segitiga --> real
# { SisiC(S) mengembalikan panjang sisi yang berseberangan dengan titik c }
# Realisasi dalam Python
def SisiC(S):
  return jarak(getA(S),getB(S))


# DEFINISI DAN SPESIFIKASI OPERATOR
# Keliling: segitiga --> real
# { keliling(S) menghitung keliling segitiga S }
# Realisasi dalam Python
def keliling(S):
  return SisiA(S) + SisiB(S) + SisiC(S)


# SemiPerimeter: segitiga --> real
# { SemiPerimeter(S) menghitung setengah dari keliling segitiga S }
# Realisasi dalam Python
def SemiPerimeter(S):
  return 0.5* keliling(S)


# Luas: segitiga --> real
# { Luas(S) menghitung luas segitiga S }
# Realisasi dalam Python
def Luas(S):
  return sqrt(SemiPerimeter(S)*SemiPerimeter(S)-SisiA(S)*SemiPerimeter(S)-SisiB(S)*SemiPerimeter(S)-SisiC(S))

   
# Aplikasi
S1 = make_segitiga(point.makePoint(1,3),point.makePoint(2,3),point.makePoint(3,4))
