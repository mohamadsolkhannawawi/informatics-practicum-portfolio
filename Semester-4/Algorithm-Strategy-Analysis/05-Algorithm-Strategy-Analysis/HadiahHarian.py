# Game Kesukaan Pai

# Deskripsi
# Pada sebuah game bernama Power Creep Rail, sedang diadakan event dimana pemain harus mendapatkan
# skor sebanyak banyaknya pada tantangan harian untuk mendapat hadiah bernama Apocalyptic Black.
# Pada event ini hadiah akan di reset setiap hari, sehingga pemain harus mengerjakan tantangan harian agar
# terus mendapat hadiah. Dalam Apocalyptic Black ada N buah hadiah dan untuk mendapat hadiah ke-i
# pemain harus minimal mendapatkan skor sebanyak Ai dan pemain juga akan mendapatkan hadiah dengan
# skor minimal yang di bawah skor yang didapat oleh pemain.
# Pai adalah salah satu pecandu game Power Creep Rail yang juga mengikuti event Apocalyptic Black. Jika
# Pai telah bermain selama K hari dan mendapat skor sebesar Si maka berapakah total skor yang telah di
# dapat Pai selama dia bermain.
# Format Masukan
# Pada baris pertama berisi 2 buah bilangan N dan K dimana 1 ≤ N, K ≤ 100000.
# Pada baris kedua berisi N buah bilangan bulat yang merupakan skor minimal hadiah dengan 1 ≤ Ai ≤
# 10000.
# Pada baris ketiga berisi K buah bilangan bulat yang merupakan skor yang didapat oleh Pai perharinya
# dengan 1 ≤ Si ≤ 10000.
# Format Keluaran
# Berisi sebuah bilangan bulat yang merupakan jumlah hadiah yang didapat pai.

# Contoh masukan 1
# 5 4
# 3 10 8 6 11
# 9 11 3 11

# Contoh keluaran 1
# 14

# Penjelasan Masukan 1
# Pada hari pertama Pai mendapat 3 hadiah, pada hari kedua mendapat 5 hadiah, pada hari ketiga mendapat
# 1 buah hadiah, dan pada hari keempat mendapat 5 buah hadiah, yang jika di total Pai mendapat 14 buah
# hadiah.

def insertionSort(arr, n):
    for i in range(1, n):
        key = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key  

def binarySearch(arr, n, target):
    kiri, kanan = 0, n - 1

    while kiri <= kanan:
        tengah = (kiri + kanan) // 2
        if arr[tengah] <= target:
            kiri = tengah + 1
        else:
            kanan = tengah - 1
    return kiri  

def totalHadiah(n, k, hadiah, skorPai):
    insertionSort(hadiah, n)  

    total = 0
    for skor in skorPai:
        hadiahSekarang = binarySearch(hadiah, n, skor)
        if hadiahSekarang > n:
            hadiahSekarang = n
        total += hadiahSekarang 
    return total

n, k = map(int, input().split())
hadiah = list(map(int, input().split()))
skorPai = list(map(int, input().split()))
print(totalHadiah(n, k, hadiah, skorPai))

