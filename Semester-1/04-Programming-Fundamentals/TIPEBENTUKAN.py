#Nama File : Mohamad Solkhan Nawawi_24060123120020_Tugas 3_C2.py
#Pembuat   : Mohamad Solkhan Nawawi - 24060123120020
#Tanggal   : 26 September 2023

#DEFINISI DAN SPESIFIKASI
def make_point(a,b):
  return [a,b]

def absis(P):
  return P[0]

def ordinat(P):
  return P[1]

def is_origin(P):
    return absis(P)==0 and ordinat(P)==0

def jarak(P1,P2):
    return sqrt((absis(P1)-absis(P2))**2 + (ordinat(P1)-ordinat(P2))**2)
