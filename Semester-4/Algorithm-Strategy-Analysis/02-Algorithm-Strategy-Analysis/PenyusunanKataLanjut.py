# Seorang arkeolog menemukan prasasti kuno yang berisi kata sandi, tetapi prasasti tersebut rusak sehingga huruf-hurufnya bisa disusun ulang untuk membentuk berbagai kemungkinan kata. Namun, prasasti juga mengandung beberapa huruf yang harus berada pada posisi tertentu dalam susunan akhir.

# Arkeolog ingin mengetahui berapa banyak cara berbeda untuk menyusun ulang huruf-huruf dalam prasasti tersebut, dengan memperhatikan batasan posisi huruf tertentu.

# Input Format

# S: string {kata yang terdiri dari huruf A-Z (tanpa spasi)} M: integer {jumlah huruf dengan posisi tetap} M baris berikutnya: Setiap baris berisi dua nilai: - C: karakter huruf yang harus diposisikan - P: posisi tetap dari huruf tersebut (indeks berbasis 1)

# Constraints

# 1 ≤ |S| ≤ 10 1 ≤ M ≤ |S| Setiap huruf dalam constraint harus ada di dalam S 1 ≤ P ≤ |S| Tidak ada dua constraint dengan posisi yang sama Huruf dalam constraint tidak boleh diubah posisinya Huruf yang tidak memiliki constraint bebas dipermutasi

# Output Format

# Integer {jumlah cara berbeda untuk menyusun ulang huruf dalam kata tersebut sesuai batasan yang diberikan}

# Sample Input 0

# ABC  
# 1  
# B 2  
# Sample Output 0

# 2
# Sample Input 1

# DECODE  
# 2  
# D 1  
# E 6  
# Sample Output 1

# 24
# Sample Input 2

# AAAA  
# 2  
# A 2  
# A 4  
# Sample Output 2

# 1

def hitung(sisa, posFix, index, hasil):
    if index == len(hasil): 
        return 1

    if index in posFix:
        return hitung(sisa, posFix, index + 1, hasil)

    total = 0
    digunakan = {}

    for i in range(len(sisa)):
        if sisa[i] in digunakan:
            continue

        digunakan[sisa[i]] = True
        hasil[index] = sisa[i]
        total += hitung(sisa[:i] + sisa[i+1:], posFix, index + 1, hasil)
        hasil[index] = ''

    return total

S = input().strip()
M = int(input())

posFix = {}
sisa = []
hasil = [''] * len(S)

for _ in range(M):
    c, p = input().split()
    p = int(p) - 1
    posFix[p] = c
    hasil[p] = c  

for i in range(len(S)):
    if i not in posFix:
        sisa.append(S[i])

print(hitung(sorted(sisa), posFix, 0, hasil))