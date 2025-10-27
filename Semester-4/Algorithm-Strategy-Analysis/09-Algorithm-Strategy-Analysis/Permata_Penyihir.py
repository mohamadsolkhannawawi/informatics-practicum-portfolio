# Di negeri sihir Arkanastra, seorang penyihir muda menemukan dua gulungan kuno. 
# Gulungan pertama berisi daftar permata ajaib (disebut jewels), 
# masing-masing ditandai dengan satu huruf unik. 
# Gulungan kedua berisi daftar batu-batu biasa yang ia kumpulkan selama perjalanannya 
# (disebut stones), juga ditandai dengan huruf-huruf.

# Namun tidak semua batu itu berharga. Hanya batu yang termasuk dalam daftar permata ajaib yang bernilai tinggi. 
# Setiap huruf pada daftar batu menunjukkan satu jenis batu yang ditemukan. 
# Kamu diminta membantu sang penyihir menghitung berapa banyak dari batu-batu itu yang merupakan permata ajaib.
# Huruf besar dan kecil memiliki arti berbeda di dunia sihir ini, jadi "a" berbeda dari "A".

# Input Format

# Baris pertama berisi string jewels — daftar jenis permata ajaib yang dicari sang penyihir.
# Baris kedua berisi string stones — daftar jenis batu-batu yang dimiliki sang penyihir.
# Constraints

# 1 <= panjang jewels, stones <= 50

# jewels dan stones hanya berisi huruf alfabet Inggris

# Semua karakter di jewels unik
# Output Format

# Integer

# Sample Input 0
# aA
# aAAbbbb
# Sample Output 0
# 3

# Sample Input 1
# z
# ZZ
# Sample Output 1
# 0

def backtracking_count_jewels(index, count):
    jewel_set = set(jewels)
    if index == len(stones):
        return count

    if stones[index] in jewel_set:
        return backtracking_count_jewels(index + 1, count + 1)
    else:
        return backtracking_count_jewels(index + 1, count)

jewels = input()
stones = input()
print(backtracking_count_jewels(0, 0))