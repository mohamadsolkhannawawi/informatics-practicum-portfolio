# Himmel, seorang petualang pemberani, baru saja menemukan dungeon yang penuh dengan harta karun berjumlah N. Setiap harta karun memiliki nilai yang berbeda, dan awas!

# Dungeon itu terjebak! Jika Himmel mencoba mengambil dua atau lebih harta karun yang tidak berderet, jebakan akan aktif, meruntuhkan seluruh dungeon. Dia harus mengambil harta karun secara berderet agar tidak memicu jebakan. Himmel ingin memaksimalkan pengumpulannya, jadi dia perlu menemukan rangkaian harta karun berderet yang memberinya nilai tertinggi. Bantu Himmel menemukan nilai harta maksimum yang bisa dikumpulkan dengan aman.

# Input Format

# Baris pertama berisi bilangan bulat N yang menunjukkan jumlah harta karun.
# Baris kedua berisi elemen-elemen array A berupa N bilangan bulat yang menunjukkan nilai setiap harta karun.
# Ai > 0 mewakili harta yang berharga.
# Ai < 0 mewakili harta terkutuk yang mengurangi nilai total.
# Constraints


# 1 ≤ N ≤ 10⁵
# -10⁴ ≤ Ai ≤ 10⁴
# Output Format

# Satu bilangan bulat yang menunjukkan nilai total maksimum yang dapat dikumpulkan Himmel dari rangkaian harta karun apa pun yang berderet.

# Sample Input 0

# 7
# -2 1 -3 4 -1 2 1 -5 4
# Sample Output 0

# 6
# Sample Input 1

# 4
# -1 -2 -3 -4
# Sample Output 1

# -1

def HimmelLooter(N, A):
    max_sum = A[0]
    current_sum = A[0]
    for i in range(1, N):
        current_sum = max(A[i], current_sum + A[i])
        max_sum = max(max_sum, current_sum)
    return max_sum

N = int(input())
A = [int (x) for x in input().split()]
print(HimmelLooter(N, A))