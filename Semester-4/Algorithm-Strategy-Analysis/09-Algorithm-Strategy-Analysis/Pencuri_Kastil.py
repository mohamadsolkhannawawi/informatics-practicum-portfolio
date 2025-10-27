# Di sebuah negeri kelam bernama Umbra, seorang pencuri legendaris sedang merencanakan 
# pencurian terbesar dalam hidupnya. Ia berhasil menyusup ke dalam kastil gelap 
# yang menyimpan banyak peti harta karun. Setiap peti memiliki berat dan nilai.

# Namun, kastil dijaga ketat. Ia hanya bisa membawa beban maksimal W agar 
# tidak terdeteksi oleh mantra pelindung. Pencuri harus memilih kombinasi 
# peti yang bisa ia bawa sehingga total nilainya maksimal, 
# namun tidak melebihi batas berat W.

# Gunakan algoritma Branch and Bound untuk menentukan nilai maksimal yang bisa ia curi tanpa ketahuan.

# Input Format

# Baris pertama berisi dua bilangan bulat n dan W — jumlah peti harta dan batas maksimum berat yang bisa dibawa.

# Baris kedua berisi n bilangan bulat, yaitu array weights, menunjukkan berat masing-masing peti.

# Baris ketiga berisi n bilangan bulat, yaitu array values, menunjukkan nilai masing-masing peti.

# Constraints

# 1 ≤ n ≤ 20

# 1 ≤ W ≤ 100

# 1 ≤ weights 𝑖 i, values 𝑖 i ≤ 100

# Output Format

# Cetak satu integer: nilai maksimum yang bisa dibawa pencuri.

# Sample Input 0
# 4 7
# 2 3 4 5
# 1 3 5 7
# Sample Output 0
# 8

# Sample Input 1
# 5 10
# 1 3 4 6 8
# 20 30 10 50 70
# Sample Output 1
# 100

# Sample Input 2
# 4 5
# 5 6 7 8
# 10 20 30 40
# Sample Output 2
# 10

def Bound(level, curr_value, curr_weight):
    if curr_weight > W:
        return 0

    total_value = curr_value
    total_weight = curr_weight

    i = level
    while i < n and total_weight + items[i][1] <= W:
        total_value += items[i][0]
        total_weight += items[i][1]
        i += 1

    if i < n:
        remain = W - total_weight
        total_value += items[i][0] * (remain / items[i][1])

    return total_value

def BnB_MaxValue(level, curr_value, curr_weight):
    if curr_weight > W:
        return 0

    if level == n:
        return curr_value

    est = Bound(level, curr_value, curr_weight)
    if est <= curr_value:
        return curr_value
    
    take = BnB_MaxValue(level + 1, curr_value + items[level][0], curr_weight + items[level][1])
    skip = BnB_MaxValue(level + 1, curr_value, curr_weight)

    return max(take, skip)

n, W = map(int, input().split())
weights = list(map(int, input().split()))
values = list(map(int, input().split()))

items = list(zip(values, weights))
items.sort(key=lambda x: x[0]/x[1], reverse=True)
print(BnB_MaxValue(0, 0, 0))
