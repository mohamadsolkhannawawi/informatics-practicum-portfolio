# Nomor 1
def konversiDetik(jam,menit,detik):
    return((jam*60*60) + (menit*60) + +detik)

print(konversiDetik(1,2,3),"detik")
print(konversiDetik(2,3,4),"detik")
print(konversiDetik(3,4,5),"detik")

# Nomor 2
def akarKuadrat(a,b,c):
    return((-b**2 + (b**2 - 4*a*c))/2*a**2)
    
print(konversiDetik(1,2,3))
print(konversiDetik(2,3,4))
print(konversiDetik(3,4,5))

def akarKuadrat(a,b,c):
    return((-b/a)**2 - (2*(a/c)))

print(konversiDetik(1,2,3))
print(konversiDetik(2,3,4))
print(konversiDetik(3,4,5))

# Nomor 3
#Realisasi
def cumlaude(bulan,nilai):
    if bulan <= 54 and nilai >= 3.5 :
        return True
    else:
        return False

#Aplikasi    
print(cumlaude(48,3.7))
print(cumlaude(56,2.3))
print(cumlaude(48,3.2))

# Nomor 4
def tahunKabisat(tahun):
    if tahun % 400 == 0 or (tahun % 4 == 0 and tahun % 100 != 0):
        return True
    else :
        return False

print(tahunKabisat(2100))
print(tahunKabisat(2000))
print(tahunKabisat(1999))

    