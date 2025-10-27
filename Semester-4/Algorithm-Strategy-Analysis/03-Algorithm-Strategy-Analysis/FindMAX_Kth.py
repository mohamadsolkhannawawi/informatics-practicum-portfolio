# Tom si kucing duduk di depan sekelompok tikus, perutnya keroncongan. Tapi dia bukan kucing sembarangan — dia ingin menghemat makanannya. Dia butuh tikus terberat ke-K, bukan yang terbesar atau terkecil, hanya yang cukup untuk memuaskannya saat ini. Matanya yang tajam tertuju pada kamu, tikus kecil yang gemetar. Dengan senyum licik, ia berkata, “Kau tampak cerdas. Temukan tikus terberat ke-K untukku, dan mungkin aku tidak akan memakanmu.”

# Otak kecilmu berpacu. Mengurutkan semua tikus terlalu lama — kesabaran Tom tipis. Dalam situasi yang menegangkan itu, kamu baru saja teringat solusi yang jauh lebih cepat, Divide and Conquer. Bantu Tom menemukan makanannya jika kamu menghargai nyawamu!

# Input Format

# Baris pertama berisi dua bilangan bulat N (banyak tikus) dan K (urutan tikus terberat ke-K).
# Baris kedua berisi N bilangan bulat yang merepresentasikan berat setiap tikus.
# Constraints


# 1 ≤ N ≤ 12
# 1 ≤ K ≤ 12
# 1 ≤ Ai ≤ 102
# Selesaikan menggunakan algoritma Divide and Conquer
# Output Format

# Sebuah bilangan bulat yang menunjukkan nilai tikus terberat ke-K.

# Sample Input 0

# 5 2  
# 3 1 4 1 5
# Sample Output 0

# 4
# Sample Input 1

# 7 3  
# 10 20 15 5 25 30 12
# Sample Output 1

# 20

def max2(a, b):
    if a > b:
        return a
    else:
        return b
    
def find_MAX(arr):
    if len(arr) == 1:
        return arr[0] 
    else:
        tengah = len(arr) // 2
        max_kiri = find_MAX(arr[:tengah])
        max_kanan = find_MAX(arr[tengah:])
        return max2(max_kiri, max_kanan)
    
def find_Kth_MAX(arr, k):
    hasil = []
    temp = arr.copy()
    while len(hasil) < k:
        nilai_max = find_MAX(temp)
        hasil.append(nilai_max)
        temp.remove(nilai_max)
    return hasil[-1]
    
n, k = map(int, input().split())
arr = list(map(int, input().strip().split()))
print(find_Kth_MAX(arr, k))


