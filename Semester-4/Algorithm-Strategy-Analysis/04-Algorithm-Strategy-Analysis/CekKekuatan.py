# Di sebuah dunia fantasi, ada sebuah menara yang dijaga oleh sejumlah penjaga. Setiap lantai menara dijaga oleh satu penjaga yang lebih kuat dari penjaga di lantai bawahnya. Seorang pahlawan harus mencapai puncak menara, tetapi untuk melakukannya, ia harus mengalahkan setiap penjaga secara berurutan dari lantai pertama hingga lantai terakhir.

# Diberikan sebuah bilangan bulat P yang menyatakan kekuatan awal pahlawan dan sebuah array G berisi N bilangan bulat yang menyatakan kekuatan penjaga di setiap lantai (dari lantai pertama hingga lantai ke-N). Jika pahlawan memiliki kekuatan lebih besar atau sama dengan kekuatan penjaga di lantai tertentu, ia dapat mengalahkan penjaga tersebut dan menambahkan kekuatan penjaga ke kekuatannya sendiri. Jika tidak, pahlawan akan terhenti dan tidak bisa melanjutkan ke lantai berikutnya.

# Buatlah program yang menentukan apakah pahlawan bisa mencapai puncak menara atau tidak dengan menggunakan algoritma decrease and conquer.

# Input Format

# Baris pertama berisi dua bilangan bulat N dan P, dipisahkan oleh spasi.
# Baris kedua berisi N bilangan bulat G[i] yang menyatakan kekuatan penjaga di tiap lantai.
# Constraints

# 1 <= N <= 100000
# 1 <= P, G[i] <= 10^9
# Output Format

# Cetak "YES" jika pahlawan dapat mencapai puncak menara.
# Cetak "NO" jika pahlawan terhenti di tengah jalan.
# Sample Input 0

# 2 1
# 2 1
# Sample Output 0

# NO
# Sample Input 1

# 4 4
# 2 3 5 7
# Sample Output 1

# YES
# Contest ends in 12 hours 7 minutes 40 seconds
# Submissions: 21
# Max Score: 1
# Rate This Challenge:

    
# More

def CekKekuatan(jumlahLantai, kekuatanPahlawan, daftarKekuatanPenjaga, lantaiSekarang = 0):
    if lantaiSekarang == jumlahLantai:
        return "YES"
    if kekuatanPahlawan < daftarKekuatanPenjaga[lantaiSekarang]:
        return "NO"
    
    return CekKekuatan(jumlahLantai, kekuatanPahlawan + daftarKekuatanPenjaga[lantaiSekarang], daftarKekuatanPenjaga, lantaiSekarang + 1)

jumlahLantai, kekuatanPahlawan = map(int, input().split())
daftarKekuatanPenjaga = list(map(int, input().split()))
print(CekKekuatan(jumlahLantai, kekuatanPahlawan, daftarKekuatanPenjaga))