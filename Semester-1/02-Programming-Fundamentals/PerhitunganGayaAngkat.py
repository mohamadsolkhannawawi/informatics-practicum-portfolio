#Nama File : PerhitunganGayaAngkat.py
#Pembuat   : Mohamad Solkhan Nawawi
#Tanggal   : 13 September 2023
#Deskripsi : Menghitung gaya angkat sayap pesawat terbang jika program diberikan masukan luas berupa integer [0...100], lajuAtas berupa integer [0...999], lajuBawah berupa integer [0...999]. Dengan massaJenis dengan nilai konstan berupa float (1.3) 

#Definisi dan Spesifikasi :
#Leana(luas,lajuAtas,lajuBawah) : 3 integer --> integer
#Leana(luas,lajuAtas,lajuBawah) : integer[0...100],integer[0...999],integer[0...999] --> integer
#    {Leana(luas,lajuAtas,lajuBawah) menghitung gaya angkat sayap pesawat terbang dengan syarat luas[0...100],lajuAtas[0...999],lajuBawah[0...999],masaJenis bernilai konstan setara dengan float(1.3),
#    dengan menggunakan perhitungan : (1/2*massaJenis * (lajuAtas**2 - lajuBawah**2) * luas)
#Realisasi
def Leana(luas,lajuAtas,lajuBawah) :
  return ((1/2*(1.3)) * (lajuAtas**2 - lajuBawah**2) * luas)

#Aplikasi
print(Leana(100,300,150))  
print(Leana(50,320,160))  
print(Leana(85,400,200))  
   