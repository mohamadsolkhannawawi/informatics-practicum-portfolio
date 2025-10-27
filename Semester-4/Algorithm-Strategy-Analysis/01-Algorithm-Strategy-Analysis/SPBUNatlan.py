# Di wilayah Natlan, terdapat n SPBU yang tersebar di sepanjang rute melingkar. Setiap SPBU i memiliki jumlah bahan bakar yang tersedia sebesar gas[i].

# Traveler memiliki kendaraan dengan tangki bahan bakar yang tidak terbatas, tetapi untuk berpindah dari SPBU ke (i+1) dibutuhkan bahan bakar sebanyak cost[i]. Traveler memulai perjalanan dengan tangki kosong dari salah satu SPBU yang ada.

# Diberikan dua array bilangan bulat gas dan cost, tentukan indeks SPBU tempat Traveler harus memulai agar dapat menyelesaikan perjalanan mengelilingi seluruh Natlan sekali dalam arah searah jarum jam. Jika perjalanan tidak dapat diselesaikan, kembalikan -1. Jika ada solusi, dijamin hanya ada satu yang unik.

# Input Format

# Input: Array of integer

# Constraints

# n == gas.length == cost.length 1 <= n <= 105 0 <= gas[i], cost[i] <= 104

# Output Format

# Output: Integer

# Sample Input 0

# 1 2 3 4 5
# 3 4 5 1 2
# Sample Output 0

# 3
# Explanation 0

# Penjelasan:

# Mulai dari SPBU ke-3 (indeks 3) dengan 4 unit bahan bakar. Tangki = 4 Bergerak ke SPBU ke-4.

# Tangki = 4 - 1 + 5 = 8 Bergerak ke SPBU ke-0.

# Tangki = 8 - 2 + 1 = 7 Bergerak ke SPBU ke-1.

# Tangki = 7 - 3 + 2 = 6 Bergerak ke SPBU ke-2.

# Tangki = 6 - 4 + 3 = 5 Bergerak kembali ke SPBU ke-3.

# Tangki cukup untuk perjalanan kembali.

# Jadi, Traveler harus mulai dari SPBU ke-3 (indeks 3) untuk berhasil mengelilingi Natlan.

# Sample Input 1

# 5
# 4
# Sample Output 1

# 0
# Explanation 1

# Mulai dari SPBU 0 dengan 5 unit bahan bakar.

# Tangki awal: 0 + 5 = 5

# Bergerak ke SPBU 0 lagi (karena hanya ada satu SPBU). Bahan bakar yang digunakan: 4 unit Sisa bahan bakar: 5 - 4 = 1

# Berhasil kembali ke SPBU awal dengan sisa 1 unit bahan bakar.

# # Karena kendaraan tidak kehabisan bahan bakar dan berhasil menyelesaikan perjalanan, maka jawabannya adalah 0 (mulai dari SPBU indeks 0).

def SPBUNatlan(gas, cost):
    countSPBU = len(gas)
    start = 0
    total = 0
    tank = 0
    for i in range(countSPBU):
        total += gas[i] - cost[i]
        tank += gas[i] - cost[i]
        if tank < 0:
            start = i + 1
            tank = 0
    if total >= 0:
        return start
    else:
        return -1

gas = list(map(int, input().split()))
cost = list(map(int, input().split()))
print(SPBUNatlan(gas, cost))