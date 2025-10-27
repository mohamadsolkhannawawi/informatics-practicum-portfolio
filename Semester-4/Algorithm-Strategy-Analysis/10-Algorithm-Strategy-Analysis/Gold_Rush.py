# Di kerajaan Eldoria, terdapat n tambang emas. 
# Setiap tambang memiliki dua atribut: - Emas yang dapat dikumpulkan (gold[i]) - Waktu yang dibutuhkan untuk menambang (time[i]) 
# Para penambang hanya memiliki T satuan waktu total untuk bekerja. 
# Mereka harus memilih tambang secara cerdas untuk memaksimalkan total emas 
# yang dikumpulkan tanpa melebihi waktu yang tersedia. 
# Setiap tambang hanya boleh diambil sekali. 
# Gunakan algoritma Greedy dengan memilih tambang yang efisien 
# (emas terbanyak per satuan waktu) terlebih dahulu.

# Input Format
# Baris pertama: Dua bilangan bulat n (jumlah tambang) dan T (total waktu yang tersedia)
# Baris kedua: n bilangan bulat, masing-masing gold[i] (jumlah emas dari tambang ke-i)
# Baris ketiga: n bilangan bulat, masing-masing time[i] (waktu untuk menambang tambang ke-i)

# Constraints
# 1 ≤ n ≤ 10⁴
# 1 ≤ T ≤ 10⁴
# 1 ≤ gold[i], time[i] ≤ 1000

# Output Format
# Satu bilangan bulat: jumlah maksimal emas yang bisa dikumpulkan dalam waktu T
# Sample Input 0
# 3 10  
# 100 200 300  
# 5 10 20  

# Sample Output 0
# 200

# Sample Input 1
# 6 20  
# 90 80 70 60 50 40  
# 2 4 6 8 10 12 
# Sample Output 1
# 300

# Sample Input 2
# 4 12  
# 60 70 80 90  
# 6 6 6 6  
# Sample Output 2
# 170

def Max_Gold(n, T, gold, time):
    mines = [(gold[i] / time[i], gold[i], time[i]) for i in range(n)]
    mines.sort(reverse=True)
    
    total_gold = 0
    for efficiency, g, t in mines:
        if T >= t:
            total_gold += g
            T -= t
        if T == 0:
            break
    return total_gold

n, T = map(int, input().split())
gold = list(map(int, input().split()))
time = list(map(int, input().split()))
print(Max_Gold(n, T, gold, time))
