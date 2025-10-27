# si a punya berbagai angka di dalam kotak. si a ingin mencari apakah suatu angka ada di dalam kotak tersebut atau tidak (mengembalikan index list elemen yang ditemukan). note: gunakan fungsi rekursif untuk pengerjaan

# Input Format

# [1,2,3] 3

# Constraints

# -

# Output Format

# 2

# Sample Input 0

# [1,2,3]
# 2
# Sample Output 0

# 1
# Sample Input 1

# []
# 4
# Sample Output 1

# "Tidak ditemukan"
# Sample Input 2

# [1,3,4]
# 5
# Sample Output 2

# # "Tidak ditemukan

def CekAngka(arr, x, index=0):
    if len(arr) == 0:
        return '"Tidak ditemukan"'
    else:
        if arr[0] == x:
            return index
        else:
            return CekAngka(arr[1:], x, index + 1)

# Input
arr = eval(input())  # List angka
x = int(input())  # Angka yang dicari

# Output
print(CekAngka(arr, x))
