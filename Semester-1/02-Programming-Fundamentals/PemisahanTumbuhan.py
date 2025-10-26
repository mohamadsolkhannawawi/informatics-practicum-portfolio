#Nama File : PemisahanTumbuhan.py
#Pembuat   : Mohamad Solkhan Nawawi
#Tanggal   : 13 September 2023
#Deskripsi : Memisahkan tumbuhan monodikotil dan dikotil berdasarkan ciri-ciri fisiknya, dengan diberikan masukan akar,batang,kambium.

#Definisi dan Spesifikasi
#MonoDiko(akar,batang,kambium) : 3 String --> String
#     {MonoDiko(akar,batang,kambium) Memisahkan tumbuhan monokotil dan dikotil berdasarkan fisiknya, akar berupa string,batang berupa string,kambium berupa string,
#      dengan masukan akar berupa "tunggang" atau "berserabut",batang berupa "bercabang" atau "beruas",kambium berupa "berkambium" atau "tidak berkambium", 
#      masukan selain tersebut akan menghasilkan keluaran "Unknown"}
#Realisasi
def MonoDiko(akar,batang,kambium) :
  if akar == "tunggang" and batang == "bercabang" and kambium == "berkambium" :
    return "Dikotil"
  elif akar == "berserabut" and batang == "beruas" and kambium == "tidak berkambium" :
    return "Monodikotil"
  else :
    return "Unknown"
  
#Aplikasi
print(MonoDiko("tunggang","bercabang","berkambium"))
print(MonoDiko("berserabut","bercabang","berkambium"))
print(MonoDiko("berserabut","beruas","tidak berkambium"))