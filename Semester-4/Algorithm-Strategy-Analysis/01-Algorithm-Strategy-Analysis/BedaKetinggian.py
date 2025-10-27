# Pak Dengklek sedang melakukan perjalanan mendaki gunung dan menuruni lembah, tak ingin perjalanannya hanya sekedar melihat pemandangan. Pak Dengklek juga mencatat data ketinggian pada beberapa titik tertentu. Data tersebut adalah bilangan-bilangan positif. Jalan kadang menaik, kadang menurun, kadang datar saja. Posisi di mana terjadi perubahan menaik kemudian menurun (boleh diselingi jalan datar) didefinisikan sebagai puncak dari suatu bukit. Sebaliknya, posisi terjadi perubahan dari menurun terus menaik (boleh diselingi bagian jalan yang datar) didefinisikan sebagai titik terbawah suatu lembah. Walaupun perubahan tersebut kecil saja, definisi itu tetap berlaku.

# Data ketinggian pertama dan terakhir juga dianggap sebagai bukit/lembah.

# Carilah beda ketinggian terbesar antara puncak bukit dengan titik terbawah lembah berikutnya atau sebaliknya antara titik terbawah lembah dengan puncak bukit berikutnya pada data perjalanan tersebut.

# Input Format

# Baris pertama merupakan banyaknya n data ketinggian Baris kedua berisi n buah data ketinggian yang masing-masing berisi sebuah bilangan bulat antara 0 sampai 100.

# Constraints

# 2 <= n <= 100

# Output Format

# Sebuah bilangan bulat yang menyatakan beda ketinggian maksimum yang diperoleh

# Sample Input 0

# 3
# 8 12 4
# Sample Output 0

# 8
# Sample Input 1

# 12
# 10 26 26 35 35 27 30 30 45 10 8 9
# # Sample Output 1

# # 37

# def BedaKetinggian(n, arr):
#     max_diff = 0

#     for i in range(1, n - 1):
#         # Cari puncak (peak)
#         if arr[i] > arr[i - 1] and arr[i] > arr[i + 1]:
#             max_diff = max(max_diff, arr[i] - min(arr[i - 1], arr[i + 1]))

#         # Cari lembah (valley)
#         elif arr[i] < arr[i - 1] and arr[i] < arr[i + 1]:
#             max_diff = max(max_diff, max(arr[i - 1], arr[i + 1]) - arr[i])

#     return max_diff

# # Input dan pemanggilan fungsi
# n = int(input())
# arr = list(map(int, input().split()))
# print(BedaKetinggian(n, arr))


# def BedaKetinggian(n, arr):
#     if n < 2:
#         return 0  

#     puncak = float('-inf') 
#     lembah = float('inf') 

#     for i in range(1, n - 1): 
#         if arr[i] > arr[i - 1] and arr[i] > arr[i + 1]:  # Puncak
#             puncak = max(puncak, arr[i])
#         if arr[i] < arr[i - 1] and arr[i] < arr[i + 1]:  # Lembah
#             lembah = min(lembah, arr[i])

#     if n == 3:
#         puncak = max(puncak, max(arr))  
#         lembah = min(lembah, min(arr)) 

#     if puncak != float('-inf') and lembah != float('inf'):
#         return puncak - lembah
#     else:
#         return 0

# n = int(input())
# arr = list(map(int, input().split()))
# print(BedaKetinggian(n, arr))


# def BedaKetinggian(n, arr):
#     if n < 2:
#         return 0  

#     puncakBukit = float('-inf') 
#     puncakLembah = float('inf') 

#     for i in range(1, n - 1):
#         if arr[i] > arr[i - 1] and arr[i] > arr[i + 1]:
#             puncakBukit = max(puncakBukit, arr[i])
#             for j in range(i + 1, n):
#                 if arr[j] < arr[j - 1]:
#                     puncakLembah = min(puncakLembah, arr[j])
#                     break
    
#     if puncakBukit != float('-inf') and puncakLembah != float('inf'):
#         return puncakBukit - puncakLembah
#     else:
#         return 0

# n = int(input())
# arr = list(map(int, input().split()))
# print(BedaKetinggian(n, arr))


# def BedaKetinggian(n, arr):
#     puncak = [] 
#     lembah = []

#     if arr[0] > arr[1]:
#         puncak.append(0)
#     elif arr[0] < arr[1]:
#         lembah.append(0)

#     for i in range(1, n - 1):
#         if arr[i] > arr[i - 1] and arr[i] > arr[i + 1]:
#             puncak.append(i)
#         elif arr[i] < arr[i - 1] and arr[i] < arr[i + 1]:
#             lembah.append(i)

#     if arr[n - 1] > arr[n - 2]:
#         puncak.append(n - 1)
#     elif arr[n - 1] < arr[n - 2]:
#         lembah.append(n - 1)

#     indexGabungan = sorted(puncak + lembah)

#     bedaMax = 0
#     for i in range(len(indexGabungan) - 1):
#         tinggi1 = arr[indexGabungan[i]]
#         tinggi2 = arr[indexGabungan[i + 1]]
#         bedaMax = max(bedaMax, abs(tinggi1 - tinggi2))

#     return bedaMax

# n = int(input().strip())
# arr = list(map(int, input().strip().split()))
# print(BedaKetinggian(n, arr))

def BedaKetinggian(n, arr):
    titikPenting = [] # Menyimpan bukit dan lembah
    if arr[0] > arr[1]:
        titikPenting.append(0)  # Bukit
    elif arr[0] < arr[1]:
        titikPenting.append(0)  # Lembah

    for i in range(1, n - 1):
        if arr[i] > arr[i - 1] and arr[i] >= arr[i + 1]:  # Bukit (mengatasi dataran)
            titikPenting.append(i)
        elif arr[i] < arr[i - 1] and arr[i] <= arr[i + 1]:  # Lembah (mengatasi dataran)
            titikPenting.append(i)

    if arr[n - 1] > arr[n - 2]:
        titikPenting.append(n - 1)  # Bukit
    elif arr[n - 1] < arr[n - 2]:
        titikPenting.append(n - 1)  # Lembah

    bedaMax = 0
    for i in range(len(titikPenting) - 1):
        tinggi1 = arr[titikPenting[i]]
        tinggi2 = arr[titikPenting[i + 1]]
        bedaMax = max(bedaMax, abs(tinggi1 - tinggi2))

    return bedaMax

n = int(input().strip())
arr = list(map(int, input().strip().split()))
print(BedaKetinggian(n, arr))

