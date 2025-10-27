# si A punya koin favorit prasejarah 2 perak. ia selalu menyimpan koinnya di sakunya. suatu ketika, koin di kantongnya terjatuh di tumpukkan koin lainnya. si A segera mencari satu per satu, dimanakah letak koin 2 perak diantara tumpukan koin lainnya.

# Input Format

# [1,2,3,4,5,6,7,8,9] 2

# Constraints

# list berisi nilai integer, output mengembalikan index list tempat angka ditemukan. jika tidak ada, mengembalikan output "Tidak ditemukan"

# Output Format

# 1

# Sample Input 0

# [1,2,3,4,5,6,7,8,9]
# 2
# Sample Output 0

# 1
# Sample Input 1

# []
# 2
# Sample Output 1

# "Tidak ditemukan"
# Sample Input 2

# [1,2,3,4,5]
# 6
# Sample Output 2

# "Tidak ditemukan"

import time
def KoinPerak(arr, x):
    if x in arr:
        return arr.index(x)
    else:
        return '"Tidak ditemukan"'

arr = eval(input())
x = int(input())
print(KoinPerak(arr, x))

# import time
# def KoinPerak(arr, x):
#     for i in range(len(arr)):
#         if arr[i] == x:
#             return i
#         else:
#             return "Tidak ditemukan"
        
# arr = 1,2,3,4,5,6,7,8,9
# x = 2
# print(KoinPerak(arr, x))
# print(time.process_time())
    