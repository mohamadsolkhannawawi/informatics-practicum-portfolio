#Nama File : point.py
#Pembuat   : Abisatya Hastarangga Pradana-24060122120004
#Tanggal   : 29 September 2023

from math import sqrt

#DEFINISI TYPE
#type point : <x:real, y:real>
#<x,y> adalah sebuah point, dengan x adalah absis dan y adalah ordinat

#DEFINISI DAN SPESIFIKASI KONSTRUKTOR
#MakePoint: 2 real --> point
#MakePoint (x,y) membentuk sebuah point dari a dan b dengan a sebagai 
# absis dan b sebagai ordinat
def make_point(a,b,):
        return [a,b]
#DEFINISI DAN SPESIFIKASI SELEKTOR
#Absis: point --> real
#Absis(P) memberikan absis point P
def absis(P):
    return P[0]

#Ordinat: point --> real
#Ordinat(P) memberikan ordinat point P
def ordinat(P):
    return P[1]

#DEFINISI DAN SPESIFIKASI PREDIKAT
#IsOrigin?: point --> boolean
#IsOrigin? (P) benar jika P adalah titik <0,0>
def is_origin(P):
    return absis(P)==0 and ordinat(P)==0

#DEFINISI DAN SPESIFIKASI OPREATOR/FUNGSI
#Jarak: 2 point --> real
#Jarak(P1,P2) menghitung jarak antara 2 point P1 dan P2
def jarak(P1,P2):
    return sqrt((absis(P1)-absis(P2))**2 + (ordinat(P1)-ordinat(P2))**2)

#Jarak0: point --> real
#jarak(P) menghitung jarak antara point p dengan titik origin
def jarak0(P):
    return sqrt((absis(P))**2 + (ordinat(P))**2)

#kuadran: point --> integer
#kuadrab (P) mengembalikan kudran dimana point P berada
def kuadran(P):
    if (absis(P)>0) and (ordinat(P)>0):
        return 1
    elif (absis(P)<0) and (ordinat(P)>0):
        return 2
    elif(absis(P)<0) and (ordinat(P)<0):
        return 3
    elif(absis(P)>0) and (ordinat(P)<0):
        return 4
    else:
        return 0

#Aplikasi
T = make_point(6,8)
P = make_point(1,-9)
print(absis(T))
print(ordinat(T))
print(is_origin(T))
print(jarak0(T))
print(kuadran(T))
print(jarak(T,P))