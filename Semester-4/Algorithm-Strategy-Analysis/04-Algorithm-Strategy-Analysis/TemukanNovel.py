# Soobin memiliki koleksi novel Omniscient Reader yang ditata urut berdasarkan edisi volumenya pada rak yang berupa sebuah array. Bantu Soobin untuk menemukan dimana letak index awal dan akhir dari volume novel yang dicari menggunakan algoritma BINARY SEARCH!

# Jika edisi yang dicari tidak ditemukan akan mengeluarkan output berupa [-1, -1]

# Input Format

# baris pertama merupakan array of integer yang pasti terurut. baris kedua merupakan target volume yang dicari berupa integer.

# Output Format

# array yang berisi posisi awal dan akhir target. [awal, akhir]

# Sample Input 0

# 1 1 3 5 6 9 9
# 1
# Sample Output 0

# [0, 1]
# Explanation 0

# target = 1; dimana 1 paling awal ditemukan di index 0 dan 1 paling akhir ditemukan pada index 1

# Sample Input 1

# 1 2 3 4 5
# 8
# Sample Output 1

# [-1, -1]
# Explanation 1

# target = 8; tidak ditemukan pada array sehingga menggeluarkan [-1, -1]

def FindAwal(arr, kiri, kanan, target, indexAwal):
    if kiri > kanan: 
        return indexAwal
    
    tengah = (kiri + kanan) // 2  
    if arr[tengah] == target:
        indexAwal = tengah
        return FindAwal(arr, kiri, tengah - 1, target, indexAwal)
    else:
        if target < arr[tengah]:
            return FindAwal(arr, kiri, tengah - 1, target, indexAwal)
        else:
            return FindAwal(arr, tengah + 1, kanan, target, indexAwal)

def FindAkhir(arr, kiri, kanan, target, indexAkhir):
    if kiri > kanan: 
        return indexAkhir
    
    tengah = (kiri + kanan) // 2
    if arr[tengah] == target:
        indexAkhir = tengah
        return FindAkhir(arr, tengah + 1, kanan, target, indexAkhir)
    else:
        if target < arr[tengah]:
            return FindAkhir(arr, kiri, tengah - 1, target, indexAkhir)
        else:
            return FindAkhir(arr, tengah + 1, kanan, target, indexAkhir)
    
def TemukanNovel(arr, target):
    indexAwal = FindAwal(arr, 0, len(arr) - 1, target, -1)
    indexAkhir = FindAkhir(arr, 0, len(arr) - 1, target, -1)
    return [indexAwal, indexAkhir]

arr = list(map(int, input().split()))
target = int(input())
print(TemukanNovel(arr, target))