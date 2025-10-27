# Himmel si pecinta dungeon memulai harinya dengan menjelajahi dungeon lagi. 
# Dia melakukannya murni karena kecintaannya pada petualangan, 
# tetapi pada hari-hari tertentu, 
# dia bisa menemukan harta yang nilainya setara dengan kekayaan seorang raja! 
# Hari ini adalah salah satunya.
# Dungeon ini penuh dengan benda-benda langka dan berkilau!
# Sayangnya, karena jarangnya dia menemukan harta, 
# dia hanya membawa sebuah bindle (kain untuk membawa barang) dengan kapasitas terbatas. 
# Perjalanannya menuju dungeon ini memakan waktu hampir seminggu, 
# dan dia tidak berencana untuk kembali lagi. 
# Maka dari itu, dia ingin memanfaatkan kesempatan ini sebaik-baiknya 
# untuk mengisi bindle-nya yang hanya bisa membawa beban hingga X berat harta. 
# Tentu saja, dia tidak bisa memecahkan harta tersebut menjadi bagian-bagian 
# kecil — mereka harus dibawa secara utuh agar tetap bernilai.

# Bantulah dia menemukan solusi terbaik dan optimal!

# Input Format

# Baris pertama berisi integer positif N berupa jumlah harta.
# Baris pertama berisi integer positif X berupa kapasitas bindle.
# N baris berikutnya berupa dua integer positif, nilai harta Ni, harga dan berat harta Ni, berat.
# Constraints

# 1 ≤ N ≤ 20
# 1 ≤ X ≤ 200
# 1 ≤ Ni, harga ≤ 200, 1 ≤Ni, berat ≤ 200
# Output Format

# Dua integer berupa jumlah harga dan berat dari harta-harta yang diambil.

# Sample Input 0
# 3
# 50
# 60 10
# 100 20
# 120 30
# Sample Output 0
# 220 50

# Sample Input 1
# 2
# 5
# 100 10
# 200 20
# Sample Output 1
# 0 0



def KSP_Backtracking(index, total_value, total_weight):
    if total_weight > X:
        return 0, 0

    if index >= N:
        return total_value, total_weight

    value, weight = items[index]
    v1, w1 = KSP_Backtracking(index + 1, total_value + value, total_weight + weight)
    v2, w2 = KSP_Backtracking(index + 1, total_value, total_weight)

    if v1 > v2 or (v1 == v2 and w1 < w2):
        return v1, w1
    else:
        return v2, w2

N = int(input())
X = int(input())
items = []
for _ in range(N):
    value, weight = map(int, input().split())
    items.append((value, weight))

result_value, result_weight = KSP_Backtracking(0, 0, 0)
print(result_value, result_weight)
