def adaPemimpin(kelompokBebek):
    jumlahBebek = len(kelompokBebek)
    
    for kiri in range(jumlahBebek):
        for kanan in range(kiri, jumlahBebek):
            subKelompok = kelompokBebek[kiri:kanan+1]
            if not pemimpinUnik(subKelompok):
                return "NO"
    
    return "YES"

def pemimpinUnik(kelompok):
    frekuensi = {}
    for nilai in kelompok:
        frekuensi[nilai] = frekuensi.get(nilai, 0) + 1
    
    nilaiUnik = [nilai for nilai, jumlah in frekuensi.items() if jumlah == 1]

    
    return len(nilaiUnik) > 0 or len(set(kelompok)) > 1


jumlahBebek = int(input().strip())
kelompokBebek = list(map(int, input().strip().split()))
print(adaPemimpin(kelompokBebek))