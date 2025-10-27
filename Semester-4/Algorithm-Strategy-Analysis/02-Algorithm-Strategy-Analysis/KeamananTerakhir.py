# Mr. Robot, seorang hacker legendaris, hampir berhasil menembus server milik mega-bank terbesar di dunia. Dia telah berhasil melewati semua firewall kecuali satu pengaman terakhir. Dia mendapatkan info dari rekannya, Elliot, bahwa dia memerlukan sebuah kode sepanjang N digit yang hanya terdiri dari karakter biner. Namun, ada satu aturan penting, kode tersebut tidak boleh memiliki angka 1 yang berurutan, Dia hanya memiliki beberapa saat tersisa sebelum sistem mendeteksinya dan membunyikan alarm.

# Dengan waktu yang semakin menipis, Mr. Robot harus segera menghasilkan semua kombinasi kode yang memenuhi aturan tersebut. Anda diminta Mr. Robot untuk membuat sebuah algoritma rekursif untuk memecahkan kode tersebut. Nasibnya dan keberhasilan seluruh misinya bergantung pada algoritma anda!

# Input Format

# Bilangan bulat N yang menunjukkan panjang kode.

# Constraints

# 1 ≤ N ≤ 20

# Output Format

# Satu baris berupa semua permutasi string biner yang tidak memiliki angka 1. Keluarkan string-string biner dalam urutan ascending.

# Sample Input 0

# 3
# Sample Output 0

# 000 001 010 100 101
# Explanation 0

# Terdapat 5 kombinasi string biner dengan panjang 3 tanpa ada angka 1 yang berurutan.

# Sample Input 1

# 4
# Sample Output 1

# 0000 0001 0010 0100 0101 1000 1001 1010


def KeamananTerakhir(N, kode=''):
    if N == 0:
        return [kode]
    
    hasil = KeamananTerakhir(N-1, kode + '0')
    if not kode or kode[-1] != '1':
        hasil += KeamananTerakhir(N-1, kode + '1')

    return hasil

N = int(input().strip())
print(' '.join(KeamananTerakhir(N)))

