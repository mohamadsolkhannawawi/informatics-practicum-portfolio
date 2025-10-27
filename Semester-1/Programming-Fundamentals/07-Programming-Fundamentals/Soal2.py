#Nama File : Soal2.py
#Pembuat   : Mohamad Solkhan Nawawi
#Tanggal   : 13 November 2023
#Deskripsi : sebuah fungsi yang menerima masukan berupa list of integer berdimensi sama,
#            lalu menghasilkan list baru yang merupakan hasil perkalian setiap elemen
#            di list pertama dan list kedua

def Konso(e,L):
  if L == [] :
    return [e]
  else :
    return [e] + L

def FirstElmt(L) :
  return L[0]

def Tail(L):
  return L[1:]

def IsEmpty(L) :
  if L == [] :
    return True
  else :
    return False

def NbElmt(L):
  if IsEmpty(L) :
    return 0
  else :
    return 1 + NbElmt(Tail(L))

def KaliList(L1,L2):
  if IsEmpty(L1) and IsEmpty(L2):
    return []
  elif NbElmt(L1) == NbElmt(L2):
    return Konso(FirstElmt(L1)*FirstElmt(L2),KaliList(Tail(L1),Tail(L2)))
  else :
    return None

#APLIKASI
print(KaliList([2, 4, 6], [1, 2, 3]))
print(KaliList([1, 2, 3, 4], [1, 2, 3, 4]))