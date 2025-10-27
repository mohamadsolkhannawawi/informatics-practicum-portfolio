# Di negeri Optimaria, seorang pahlawan sedang menjalankan misi untuk membasmi 
# segerombolan monster yang menyerang desa-desa. Setiap monster memiliki kekuatan
# tertentu dan setelah dikalahkan, pahlawan bisa mendapatkan bonus buff atau kekuatan. 
# Pahlawan harus memilih urutan yang paling optimal agar bisa mengalahkan semua monster.

# Setiap monster hanya bisa dikalahkan jika kekuatan pahlawan saat itu ≥ kekuatan monster. 
# Setelah mengalahkan monster, kekuatan pahlawan bertambah sesuai bonus dari monster tersebut.

# Tentukan apakah pahlawan tersebut dapat mengalahkan segerombolan monster atau tidak! 
# Sehingga pahlawan bisa mundur untuk mencari bantuan terlebih dahulu.

# Input Format
# Baris pertama: dua bilangan bulat positif kekuatan awal yang dimiliki pahlawan P dan N jumlah gerombolan monster
# Baris kedua sampai n: dua bilangan bulat kekuatan monster K dan bonus kekuatan B
# Constraints

# Output Format
# Sebuah string yang menyatakan "YA" atau "NO"

# Sample Input 0
# 2 10
# 30 12
# 2 4
# 6 1
# 90 1
# 4 12
# 8 2
# 12 2
# 15 2
# 1 4
# 2 10
# Sample Output 0
# NO

# Sample Input 1
# 1 4
# 90 3
# 30 5
# 1 100
# 8 1
# Sample Output 1
# YES

def isCan_Win_All(p, monsters):
    monsters.sort(key=lambda x: x[0])
    for k, b in monsters:
        if p >= k:
            p += b
        else:
            return "NO"
    return "YES"

p_n = input().split()
p = int(p_n[0]) 
n = int(p_n[1])
monsters = []
for _ in range(n):
    k_b = input().split()
    k = int(k_b[0]) 
    b = int(k_b[1])
    monsters.append((k, b))
print(isCan_Win_All(p, monsters))
