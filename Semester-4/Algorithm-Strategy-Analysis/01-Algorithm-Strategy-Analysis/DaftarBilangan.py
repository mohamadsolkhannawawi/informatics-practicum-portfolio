# Narbig ingin membuat sebuah program yang bisa melakukan operasi spesial pada daftar bilangan bulat/angka. Ia ingin cara perhitungannya unik tergantung pada panjang daftar angka yang diberikan. Jika panjang list genap, hasilnya adalah jumlah dari semua angka. Jika panjang list ganjil, maka angka di tengah dihapus lalu jumlah dari dua bagian sisanya dikalikan dengan angka tengah tersebut.

# Bantu Narbig untuk menyelesaikan program tersebut!

# Note: Ukuran list sengaja tidak diberi sebagai inputan

# Input Format

# Deretan bilangan bulat l yang dipisahkan oleh spasi, merepresentasikan kata yang harus disusun.

# Constraints

# 1 ≤ |l| ≤ 1000

# Output Format

# Bilangan Bulat

# Sample Input 0

# 1 2 3 4
# Sample Output 0

# 10
# Sample Input 1

# 1 2 -1 3 4
# Sample Output 1

# -10

def DaftarBilangan(arr):
    if len(arr) % 2 == 0:
        return sum(arr)
    else:
        removed = arr[len(arr)//2]
        arr.remove(arr[len(arr)//2])
        return sum(arr) * removed
    
arr = list(map(int, input().split()))
print(DaftarBilangan(arr))