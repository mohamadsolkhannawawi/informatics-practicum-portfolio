# Tersembunyi di dalam rimba luas Ixtal, terdapat kerajaan Ixaocan. Salah satu putrinya, Qiyana, adalah seorang putri yang bangga dan angkuh, yang hanya menuntut emas terbaik untuk hiasan kepala upacaranya. Ketika para pengrajin kerajaan mempersembahkan sebuah peti berisi N koin emas, dia mencibir. “Apa kalian menganggapku bodoh? Salah satu dari koin ini terasa… aneh.” Para penasihat ragu — siapa yang berani meragukan intuisi sang putri? Untuk membuktikan keunggulannya, Qiyana meraih Timbangan Ixtal, sebuah timbangan suci yang hanya dapat membandingkan berat, bukan mengukurnya.

# Qiyana adalah putri yang tidak sabaran. Menimbang koin satu per satu akan memakan terlalu banyak waktu. Untungnya, ada sebuah metode di mana setiap langkah akan mengurangi jumlah koin yang dicurigai, hingga akhirnya koin palsu ditemukan. Buatlah sebuah algoritma Decrease and Conquer untuk membantu Qiyana menemukannya!

# Input Format

# Baris pertama berisi bilangan bulat N yang menunjukkan jumlah murid.
# Baris kedua berisi N bilangan bulat di mana Ai menunjukkan berat koin ke-i.
# Constraints


# 1 ≤ N ≤ 20
# 0 ≤ Ai ≤ 20
# Selesaikan menggunakan pendekatan Decrease and Conquer!
# Output Format

# Sebuah bilangan bulat berupa index koin palsu.

# Sample Input 0

# 4
# 10 10 9 10
# Sample Output 0

# 2
# Explanation 0

# Koin palsu berada di index ke-2.

# Sample Input 1

# 7
# 10 10 10 9 10 10 10
# Sample Output 1

# 3
# Explanation 1

# Koin palsu berada di index ke-3.

def KoinPalsu(daftarKoin, index):
    jumlahKoin = len(daftarKoin)
    if jumlahKoin == 1:
        return index[0]

    if jumlahKoin % 2 == 1:
        koinSisa = daftarKoin[-1]  
        indexSisa = index[-1]  
        daftarKoin = daftarKoin[:-1] 
        index = index[:-1]
    else:
        koinSisa = None
        indexSisa = None

    tengah = len(daftarKoin) // 2
    subKiri = daftarKoin[:tengah]  
    subKanan = daftarKoin[tengah:]  
    indexKiri = index[:tengah]
    indexKanan = index[tengah:]

    sumSubKiri = sum(subKiri)
    sumSubKanan = sum(subKanan)

    if sumSubKiri < sumSubKanan:
        return KoinPalsu(subKiri, indexKiri)  
    elif sumSubKanan < sumSubKiri:
        return KoinPalsu(subKanan, indexKanan)  
    else:
        return indexSisa 

jumlahKoin = int(input())
daftarKoin = list(map(int, input().split()))
indexKoin = list(range(jumlahKoin))
hasil = KoinPalsu(daftarKoin, indexKoin)
print(hasil)
