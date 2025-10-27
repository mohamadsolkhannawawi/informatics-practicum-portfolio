# King Farid dari kerajaan kuno Gondang menyembunyikan harta karunnya yang sangat berharga di dalam gua yang sangat luas dan bercabang-cabang. Sayangnya, peta yang dimiliki oleh penjaga kerajaan hilang, dan hanya tersisa sebuah buku petunjuk yang berisi angka-angka misterius.

# Sang pangeran, Fakhrell, harus menemukan harta tersebut sebelum pencuri menemukannya lebih dahulu. Dia menemukan bahwa angka-angka dalam buku petunjuk adalah ukuran masing-masing gua yang terbagi menjadi beberapa bagian. Satu-satunya cara untuk menemukan bagian yang memiliki harta adalah dengan mencari bagian terbesar dari gua dan memeriksanya lebih dalam.

# Bantu Fakhrell menemukan gua terbesar dengan menerapkan algoritma Divide and Conquer untuk mencari nilai maksimum dari daftar ukuran gua yang diberikan.

# Input Format

# Baris pertama berisi satu bilangan bulat N (1 <= N <= 10^5), menyatakan jumlah bagian gua.
# Baris kedua berisi N bilangan bulat yang dipisahkan oleh spasi, menyatakan ukuran setiap bagian gua. Nilai dari setiap ukuran adalah -10^9 <= A[i] <= 10^9.
# Constraints

# 1 <= N <= 100000
# 10^9 <= A[i] <= 10^9
# Penyelesaian harus menggunakan pendekatan Divide and Conquer.
# Output Format

# Cetak satu bilangan bulat yang merupakan ukuran terbesar dari bagian gua.

# Sample Input 0

# 5
# 3 1 4 1 5
# Sample Output 0

# 5
# Sample Input 1

# 10
# -2 -3 -1 -7 -4 -6 -8 -5 -9 -10
# Sample Output 1

# -1
# Sample Input 2

# 7
# 10 20 -30 40 -50 60 70
# Sample Output 2

# 70
# Contest ends in 2 days 10 hours 33 minutes 37 seconds
# Submissions: 12
# Max Score: 1
# Rate This Challenge:

    
# More

def max2(a, b):
    if a > b:
        return a
    else:
        return b
    
def find_MAX(arr):
    if len(arr) == 1:
        return arr[0] 
    else:
        tengah = len(arr) // 2
        max_kiri = find_MAX(arr[:tengah])
        max_kanan = find_MAX(arr[tengah:])
        return max2(max_kiri, max_kanan)
    
n = int(input().strip())
arr = list(map(int, input().strip().split()))
print(find_MAX(arr))
