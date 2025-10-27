# Di sebuah kuil Palindoria terdapat scroll of symmetry, sebuah teks kuno yang memuat rahasia palindrom. Namun untuk mencegah dari pihak pihak yang tidak bertanggung jawab huruf-huruf ini diacak sedemikian rupa, dan hanya orang yang terpilih yang bisa mengembalikan ke bentuk semula.

# Kebetulan anda menemukan scroll of symmetry, dan terdapat harta karun yang dapat dibuka berdasarkan kode dari gulungan tersebut. Dapatkah Anda menentukan apakah huruf-huruf yang diacak pada gulungan tersebut dapat disusun ulang menjadi palindrom yang sempurna? Jika demikian, susun kembali satu atau lebih teks palindrom yang mungkin untuk mengungkap rahasia kuil tersebut!

# Jika ternyata tidak ada susunan huruf yang bisa terbentuk menjadi palindrom maka anda harus "Kabur!" karena ternyata hal tersebut adalah jebakan.

# Input Format

# String yang merupakan susunan kata yang hurufnya diacak

# Constraints

# String dipastikan ada (tidak kosong) dan berhuruf kecil

# Output Format

# Barisan string n semua kemungkinan palindrom yang dapat disusun ulang dipisahkan oleh spasi terurut naik abjad , bisa jadi "Kabur!".

# Sample Input 0

# racecar
# Sample Output 0

# acrerca arcecra carerac craearc racecar rcaeacr
# Sample Input 1

# rucioslkfr
# Sample Output 1

# Kabur!

def hitungFrekuensi(s, frekuensi=None, index=0):
    if frekuensi is None:
        frekuensi = {}
    if index == len(s):
        return frekuensi
    kepala = s[index]
    if kepala in frekuensi:
        frekuensi[kepala] += 1
    else:
        frekuensi[kepala] = 1
    return hitungFrekuensi(s, frekuensi, index + 1)

def ambilKunci(dictionary, kunciList=None, daftarKunci=None, index=0):
    if kunciList is None:
        kunciList = []
    if daftarKunci is None:
        daftarKunci = [kunci for kunci in dictionary]  # Ambil daftar kunci
    if index == len(daftarKunci):
        return kunciList
    kunciList.append(daftarKunci[index])
    return ambilKunci(dictionary, kunciList, daftarKunci, index + 1)

def cariKarakterGanjil(frekuensi, karakterGanjil=None, kunciList=None, index=0):
    if karakterGanjil is None:
        karakterGanjil = []
    if kunciList is None:
        kunciList = ambilKunci(frekuensi) 
    if index == len(kunciList):
        return karakterGanjil
    kunci = kunciList[index]
    if frekuensi[kunci] % 2 != 0:
        karakterGanjil.append(kunci)
    return cariKarakterGanjil(frekuensi, karakterGanjil, kunciList, index + 1)

def buatSetengahPalindrom(frekuensi, hasil=None, kunciList=None, index=0):
    if hasil is None:
        hasil = []
    if kunciList is None:
        kunciList = ambilKunci(frekuensi) 
        kunciList.sort()  

    if index == len(kunciList):
        return hasil
    kunci = kunciList[index]
    jumlah = frekuensi[kunci] // 2
    for _ in range(jumlah):
        hasil.append(kunci)
    return buatSetengahPalindrom(frekuensi, hasil, kunciList, index + 1)

def generatePalindrom(half, tengah, hasil=None, digunakan=None, index=0, hasilAkhir=None):
    if hasil is None:
        hasil = []
    if digunakan is None:
        digunakan = [False] * len(half)
    if hasilAkhir is None:
        hasilAkhir = []

    if len(hasil) == len(half):
        palindromLengkap = "".join(hasil) + tengah + "".join(hasil[::-1])
        if palindromLengkap not in hasilAkhir:  # Menghindari duplikasi
            hasilAkhir.append(palindromLengkap)
        return hasilAkhir

    i = 0
    while i < len(half):
        if not digunakan[i] and (i == 0 or half[i] != half[i - 1] or digunakan[i - 1]):
            digunakan[i] = True
            hasil.append(half[i])
            hasilAkhir = generatePalindrom(half, tengah, hasil, digunakan, i + 1, hasilAkhir)
            hasil.pop()
            digunakan[i] = False
        i += 1
    return hasilAkhir

def cariSemuaPalindrom(s):
    frekuensi = hitungFrekuensi(s)
    karakterGanjil = cariKarakterGanjil(frekuensi)

    if len(karakterGanjil) > 1:
        print("Kabur!")
        return
    
    tengah = karakterGanjil[0] if karakterGanjil else ""
    half = buatSetengahPalindrom(frekuensi)
    hasilAkhir = generatePalindrom(half, tengah)

    hasilAkhir.sort()
    print(" ".join(hasilAkhir))


s = input().strip()
cariSemuaPalindrom(s)
