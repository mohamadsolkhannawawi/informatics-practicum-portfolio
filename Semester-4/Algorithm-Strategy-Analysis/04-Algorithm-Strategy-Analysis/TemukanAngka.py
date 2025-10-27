# si a mempunya input berupa list berisi bilangan integer secara terurut (entah dari terbesar ke terkecil atau terkecil ke terbesar). si a ingin mencari suatu bilangan apakah ada di dalam list tersebut atau tidak. jika tidak ada mengembalikan tidak ditemukan. jika ada mengembalikan index list yang ditemukan. note: gunakan algoritma binary search

# Input Format

# [1,2,3,4,5] 4

# Constraints

# integer

# Output Format

# 3

# Sample Input 0

# []
# 4
# Sample Output 0

# "Tidak ditemukan"
# Sample Input 1

# [1,2,3,4,5]
# 3
# Sample Output 1

# 2

def TemukanAngka(arr, target, kiri, kanan, ascending=True):
    if kiri > kanan:
        return '"Tidak ditemukan"'  

    tengah = (kiri + kanan) // 2

    if arr[tengah] == target:
        return tengah
    
    if ascending:  
        if arr[tengah] < target:
            return TemukanAngka(arr, target, tengah + 1, kanan, ascending)
        else:
            return TemukanAngka(arr, target, kiri, tengah - 1, ascending)
    else:  
        if arr[tengah] > target:
            return TemukanAngka(arr, target, tengah + 1, kanan, ascending)
        else:
            return TemukanAngka(arr, target, kiri, tengah - 1, ascending)

arr = eval(input()) 
target = int(input())
if len(arr) == 0:
    print('"Tidak ditemukan"')
else:
    ascending = arr[0] < arr[-1]
    print(TemukanAngka(arr, target, 0, len(arr) - 1, ascending))

