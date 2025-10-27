# def cekKemampuanAgen(waktu, peringkat, petunjuk):
#     totalPetunjuk = 0
#     for posisi in peringkat:
#         n = 0
#         while posisi * (n + 1) ** 2 <= waktu: 
#             n += 1
#             totalPetunjuk += 1
#             if totalPetunjuk >= petunjuk: 
#                 return True
#     return totalPetunjuk >= petunjuk 

# def waktuMinimum(kiri, kanan, peringkat, petunjuk):
#     if kiri >= kanan:
#         return kiri 
    
#     tengah = (kiri + kanan) // 2    
#     if cekKemampuanAgen(tengah, peringkat, petunjuk):  
#         return waktuMinimum(kiri, tengah, peringkat, petunjuk)  
#     else:
#         return waktuMinimum(mid + 1, kanan, peringkat, petunjuk)  


# peringkat = list(map(int, input().split()))
# petunjuk = int(input())
# kiri, kanan = 1, min(peringkat) * petunjuk ** 2 
# print(waktuMinimum(kiri, kanan, peringkat, petunjuk))


def hitungWaktuMinimum(daftarAgen,jumlahPetunjuk):
    kiri = 1
    kanan = max(daftarAgen)*jumlahPetunjuk*jumlahPetunjuk
    temp = kanan
    
    while kiri <= kanan:
        tengah = (kiri + kanan) // 2
        totalPetunjuk = 0
        for r in daftarAgen:
            if r == 0:
                continue
            maxPetunjuk = int((tengah/r)**0.5)
            totalPetunjuk += maxPetunjuk
        if totalPetunjuk >= c:
            temp = tengah
            kanan = tengah - 1
        else:
            kiri = tengah + 1
    return temp

daftarAgen = list(int, input().split())
c = int(input())   
print(hitungWaktuMinimum(daftarAgen,c))
print()