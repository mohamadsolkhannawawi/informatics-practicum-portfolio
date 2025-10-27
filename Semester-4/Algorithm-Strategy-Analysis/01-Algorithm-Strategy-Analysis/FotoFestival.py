# Foto Festival Terbaik

# Deskripsi
# Shinomiya Kaguya adalah seorang Wakil Ketua OSIS dari Akademi Shuchiin. Saat ini sedang diadakan festival
# di akademi tersebut. Karena anggota OSIS terbatas, Kaguya terpaksa merangkap menjadi divisi PDD. Kaguya
# ingin mengabadikan momen terbaik dari acara festival ini dengan kameranya.
# Kaguya memiliki kamera yang mampu menangkap gambar dalam bentuk persegi dengan ukuran berapa pun,
# misalnya 1 × 1, 2 × 2, 3 × 3, dan seterusnya. Nilai kualitas foto ditentukan berdasarkan jumlah total nilai
# fragmen yang tertangkap dalam bingkai kamera. Semakin tinggi jumlah nilai fragmen, semakin baik fotonya.
# Karena terlalu banyak kombinasi yang bisa diambil, Kaguya membutuhkan bantuan untuk menemukan foto
# terbaik.

# Sebagai contoh, terdapat 20 kemungkinan kombinasi yang bisa dipilih untuk foto di atas, di antaranya:
# • Ukuran 1 × 1: terdapat 12 kombinasi, dengan nilai maksimum 15.
# • Ukuran 2 × 2:

# Kualitas foto = 5 + 12 + 6 − 5 = 18

# Kualitas foto = 12 + 9 − 5 − 11 = 5

# Kualitas foto = 9 + 7 − 11 + 15 = 20

# 1

# Kualitas foto = 6 − 5 + 5 + 2 = 8

# Kualitas foto = −5 − 11 + 2 + 1 = −13

# Kualitas foto = −11 + 15 + 1 + 0 = 5

# • Ukuran 3 × 3:

# Kualitas foto = 5 + 12 + 9 + 6 − 5 − 11 + 5 + 2 + 1 = 24

# Kualitas foto = 12 + 9 + 7 − 5 − 11 + 15 + 2 + 1 + 0 = 30

# Dari seluruh kemungkinan yang ada, foto terbaik adalah foto dengan ukuran 3 × 3 yang dimulai dari koordinat
# pojok kiri atas di (1, 2).
# Format Masukan
# • Baris pertama berisi dua bilangan bulat N, M (1 ≤ N, M ≤ 50) yang menunjukkan ukuran foto.
# • N baris berikutnya berisi M bilangan bulat −106 ≤ Aij ≤ 106 yang merupakan nilai setiap elemen
# fragmen foto.

# 2

# Format Keluaran
# Keluarkan satu baris yang terdiri atas empat bilangan bulat p, n, x, y, di mana:
# • p adalah kualitas foto terbaik.
# • n × n adalah ukuran foto terbaik. Cukup keluarkan n sekali saja.
# • (x, y) adalah koordinat pojok kiri atas dari foto.
# Jika terdapat beberapa foto dengan kualitas yang sama, maka:
# 1. Pilih foto dengan ukuran terbesar.
# 2. Jika ukuran sama, pilih foto dengan x terkecil.
# 3. Jika x sama, pilih foto dengan y terkecil.
# Contoh Masukan 1
# 3 4
# 5 12 9 7
# 6 -5 -11 15
# 5 2 1 0

# Contoh Keluaran 1

# 30 3 1 2

# Contoh Masukan 2
# 3 3
# 8 6 7
# 2 -5 9
# 4 -20 -1

# Contoh Keluaran 2

# 17 2 1 2

# Contoh Masukan 3
# 4 4
# 8 6 7 10
# 2 -5 9 12
# 4 -20 -1 14
# 1 2 3 4

# Contoh Keluaran 3
# 56 4 1 1

# Penjelasan
# Pada contoh keluaran pertama sudah jelas seperti pada contoh di atas, bahwa kualitas foto tertinggi adalah 30
# dengan ukuran 3 × 3 pada posisi pojok kiri atas (1, 2).

# n, m = map(int, input().split())
# matrix = [list(map(int, input().split())) for _ in range(n)]

# def foto(n,m,matrix):  
#     # Membangun prefix sum 2D (ukuran (n+1) x (m+1))
#     pre = [[0] * (m + 1) for _ in range(n + 1)] # Inisialisasi dengan 0 (m+1) x (n+1)
#     for i in range(1, n + 1):
#         for j in range(1, m + 1):
#             pre[i][j] = matrix[i - 1][j - 1] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1]
    
#     best_sum = -9999999
#     best_size = 0
#     best_x = 0  
#     best_y = 0  
    
#     # Ukuran foto terbaik bisa berupa submatrix berbentuk bujur sangkar dengan sisi 1 sampai min(n, m)
#     for s in range(1, min(n, m) + 1):
#         for i in range(n - s + 1):
#             for j in range(m - s + 1):
#                 # Hitung jumlah submatrix dari (i,j) sampai (i+s-1,j+s-1) menggunakan prefix sum
#                 current_sum = pre[i + s][j + s] - pre[i][j + s] - pre[i + s][j] + pre[i][j]
                
#                 # Perbarui jika kualitas foto lebih tinggi
#                 if current_sum > best_sum:
#                     best_sum = current_sum
#                     best_size = s
#                     best_x = i
#                     best_y = j
#                 # Jika sama, gunakan aturan:
#                 # 1. Pilih ukuran submatrix yang lebih besar
#                 # 2. Jika sama, pilih baris terkecil
#                 # 3. Jika baris sama, pilih kolom terkecil
#                 elif current_sum == best_sum:
#                     if s > best_size:
#                         best_size = s
#                         best_x = i
#                         best_y = j
#                     elif s == best_size:
#                         if i < best_x or (i == best_x and j < best_y):
#                             best_x = i
#                             best_y = j
    
#     # Karena koordinat output diminta 1-indexed
#     print(best_sum, best_size, best_x + 1, best_y + 1)

# foto(n,m,matrix)

# def FotoFestival(n, m, matrix):
#     # Membangun prefix sum 2D
#     prefixSum = [[0] * (m + 1) for _ in range(n + 1)]
#     for i in range(1, n + 1):
#         for j in range(1, m + 1):
#             prefixSum[i][j] = matrix[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1]

#     kualitasTerbaik = -9999999
#     ukuranTerbaik = 0
#     xTerbaik = 0
#     yTerbaik = 0

#     # Mencari submatrix terbaik dengan ukuran s x s
#     for s in range(1, min(n, m) + 1):
#         for i in range(n - s + 1):
#             for j in range(m - s + 1):
#                 jumlahSaatIni = prefixSum[i + s][j + s] - prefixSum[i][j + s] - prefixSum[i + s][j] + prefixSum[i][j]

#                 # Perbarui jika kualitas lebih tinggi atau sesuai aturan prioritas
#                 if jumlahSaatIni > kualitasTerbaik:
#                     kualitasTerbaik = jumlahSaatIni
#                     ukuranTerbaik = s
#                     xTerbaik = i
#                     yTerbaik = j
#                 elif jumlahSaatIni == kualitasTerbaik:
#                     if s > ukuranTerbaik or (s == ukuranTerbaik and (i < xTerbaik or (i == xTerbaik and j < yTerbaik))):
#                         ukuranTerbaik = s
#                         xTerbaik = i
#                         yTerbaik = j

#     # Output dalam format 1-indexed
#     print(kualitasTerbaik, ukuranTerbaik, xTerbaik + 1, yTerbaik + 1)

# n, m = map(int, input().strip().split())
# matrix = [list(map(int, input().strip().split())) for _ in range(n)]
# FotoFestival(n, m, matrix)


def FotoFestivalTerbaik(n, m, matrix):
    # Membangun prefix sum 2D (ukuran (n+1) x (m+1))
    prefixSum = [[0] * (m + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            prefixSum[i][j] = (
                matrix[i - 1][j - 1] 
                + prefixSum[i - 1][j] 
                + prefixSum[i][j - 1] 
                - prefixSum[i - 1][j - 1]
            )

    kualitasTerbaik = -10**6  # Inisialisasi nilai minimum
    ukuranTerbaik = 0
    xTerbaik = 0
    yTerbaik = 0

    # Iterasi untuk semua ukuran submatrix (1x1 hingga min(n, m) x min(n, m))
    for s in range(1, min(n, m) + 1):
        for i in range(n - s + 1):
            for j in range(m - s + 1):
                # Menggunakan prefix sum untuk mendapatkan kualitas foto
                kualitasSaatIni = (
                    prefixSum[i + s][j + s] 
                    - prefixSum[i][j + s] 
                    - prefixSum[i + s][j] 
                    + prefixSum[i][j]
                )

                # Memilih foto terbaik berdasarkan aturan yang diberikan
                if kualitasSaatIni > kualitasTerbaik:
                    kualitasTerbaik = kualitasSaatIni
                    ukuranTerbaik = s
                    xTerbaik = i
                    yTerbaik = j
                elif kualitasSaatIni == kualitasTerbaik:
                    if s > ukuranTerbaik or (s == ukuranTerbaik and (i < xTerbaik or (i == xTerbaik and j < yTerbaik))):
                        ukuranTerbaik = s
                        xTerbaik = i
                        yTerbaik = j

    # Output dalam format 1-indexed
    print(kualitasTerbaik, ukuranTerbaik, xTerbaik + 1, yTerbaik + 1)

n, m = map(int, input().strip().split())
matrix = [list(map(int, input().strip().split())) for _ in range(n)]
FotoFestivalTerbaik(n, m, matrix)


    