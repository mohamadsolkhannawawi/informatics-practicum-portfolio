#Nama File : PengecekanAir.py
#Pembuat   : Mohamad Solkhan Nawawi
#Tanggal   : 13 September 2023
#Deskripsi : Mengecek apakah air higienis atau tidak dari masukan air berupa integer[0...10000],bakteri berupa integer [0...100],parasite berupa integer [0...100].

#Definisi dan spesifikasi
#AirHigenis(air,bakteri,parasite) : 3 integer --> string
#AirHigenis(air,bakteri,parasite) : integer[0...1000],integer[0...100],integer[0...100] --> integer
#     {AirHigenis(air,bakteri,parasite) mengecek apakah air higenis atau tidak dari masukan air berupa integer [0...1000],bakteri berupa integer [0...100],parasite berupa integer [0...100] ,
#     dengan perhitungan akumulasi mikrobiota dengan menggunakan : akumulasi = (air)/(bakteri + parasite)**2}

#Realisasi
def AirHigenis(air,bakteri,parasite) :
  akumulasi = (air)/(bakteri + parasite)**2
  if air > 500 and akumulasi < 1:
    return "Air Steril"
  elif air > 250 and  akumulasi < 25 :
    return "Air Bersih"
  elif air > 100 and akumulasi < 50 :
    return "Air Kotor"
  elif air < 100 and akumulasi >50 :
    return "Air Toxic"
  else :
    return "Unknown"
  
#Aplikasi
print(AirHigenis(150,50,70))
print(AirHigenis(1000,40,80))
print(AirHigenis(500,30,90))