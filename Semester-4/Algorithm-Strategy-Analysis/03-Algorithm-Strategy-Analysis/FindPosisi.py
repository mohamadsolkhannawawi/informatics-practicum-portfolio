# Di sebuah tempat pemerintahan futuristik "Elysium" terdapat pencurian chip penting yang bisa menghancurkan semua manusia Cyborg. Beruntungnya di tempat itu diawasi sistem canggih Quantum-Eye, sistem pengawasan canggih yang mencatat setiap individu yang masuk dan keluar dari lokasi tertentu.

# Namun, Quantum-Eye tidak merekam identitas langsung seseorang. Sebagai gantinya, sistem mencatat mereka dalam bentuk log kedatangan, sebuah daftar angka unik yang disusun berdasarkan waktu (menit) mereka masuk.

# Beruntungnya terdapat seorang saksi mata yang memberikan informasi identitas pelaku yang dicurigai, tugasmu adalah mencari tahu menit awal kemunculan dan akhir dari identitas tersebut yang direpresentasikan dalam sebuah index, untuk kemudian diselidiki lebih lanjut oleh divisi penyidik.

# Format log:

# Log Kedatangan direpresentasikan sebagai array angka unik, di mana setiap angka menunjukkan ID seorang individu.
# Array ini selalu berurut secara non-decreasing (tidak menurun) karena mencatat kedatangan berdasarkan waktu.
# Setiap angka bisa muncul lebih dari sekali, menandakan seseorang yang datang dalam beberapa kesempatan.
# Apakah kamu bisa menemukan mereka tepat waktu? Atau Quantum-Eye hanya akan memberimu "-1 -1", tanda bahwa bayangan itu telah menghilang selamanya?

# Perhatikan bahwa index dimulai dari 1.

# Input Format

# Baris pertama berisi integer positif n (ukuran array) dan integer k (target identitas)
# Baris kedua berisi barisan integer terurut naik yang merepresentasikan ID berukuran n
# Constraints

# Output Format

# Barisan integer yang menampilkan awal index dan akhir index kemunculan identitas
# Apabila tidak ditemukan maka akan menampilkan "-1 -1"
# Sample Input 0

# 6 10
# 8 8 9 9 10 10
# Sample Output 0

# 5 6
# Sample Input 1

# 1 2
# 2
# Sample Output 1

# 1 1
# Sample Input 2

# 10 21
# 16 16 17 18 19 20 20 22 22 30
# Sample Output 2

# -1 -1

def find_posisi(arr, target):
    hasil = -1
    kiri = 0
    kanan = len(arr) - 1
    while kiri <= kanan:
        tengah = (kiri + kanan) // 2
        if arr[tengah] == target:
            hasil = tengah
            break
        elif arr[tengah] < target:
            kiri = tengah + 1
        else:
            kanan = tengah - 1
        
    awal = hasil
    while awal > 0 and arr[awal - 1] == target:
        awal -= 1
    
    akhir = hasil
    while akhir < (len(arr) - 1) and arr[akhir + 1] == target:
        akhir += 1

    if hasil == -1:
        print("-1 -1")
    else:
        print(awal + 1, akhir + 1)

n, k = map(int, input().split())
arr = list(map(int, input().split()))
find_posisi(arr, k)

