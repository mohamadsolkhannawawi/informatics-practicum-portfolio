def cariPembagi(n):
    pembagi = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            pembagi.append(i)
            if i != n // i:
                pembagi.append(n // i)
    return urutGabung(pembagi)  # Gunakan pengurutan gabung untuk mengurutkan

def urutGabung(arr):
    if len(arr) <= 1:
        return arr
    tengah = len(arr) // 2
    kiri = urutGabung(arr[:tengah])
    kanan = urutGabung(arr[tengah:])
    return gabung(kiri, kanan)

def gabung(kiri, kanan):
    hasil = []
    i = j = 0
    while i < len(kiri) and j < len(kanan):
        if kiri[i] < kanan[j]:
            hasil.append(kiri[i])
            i += 1
        else:
            hasil.append(kanan[j])
            j += 1
    hasil.extend(kiri[i:])
    hasil.extend(kanan[j:])
    return hasil

def cariKombinasi(arr, target, indeks=0, saatIni=[]):
    if target == 0:
        return [saatIni]
    if indeks >= len(arr) or target < 0:
        return []
    
    ikut = cariKombinasi(arr, target - arr[indeks], indeks + 1, saatIni + [arr[indeks]])
    tidakIkut = cariKombinasi(arr, target, indeks + 1, saatIni)
    
    return ikut + tidakIkut

def cariPembagiValid(n):
    pembagi = cariPembagi(n)
    kemungkinan = cariKombinasi(pembagi, 13)
    
    if kemungkinan:
        return " ".join(map(str, urutGabung(min(kemungkinan))))
    else:
        return "-1"

jumlahAngka = int(input().strip())  # Baca jumlah angka yang dicek
angkaDiperiksa = [int(input().strip()) for _ in range(jumlahAngka)]  # Baca angka

for angka in angkaDiperiksa:
    print(cariPembagiValid(angka))