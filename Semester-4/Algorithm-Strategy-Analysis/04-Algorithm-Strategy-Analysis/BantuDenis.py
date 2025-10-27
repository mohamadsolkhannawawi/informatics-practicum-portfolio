# Suatu hari yang cerah saat Adit, Denis, dan teman temannya sedang bermain "Hitung Bola". Pada awal permainan ditentukan dulu (N) untuk maksimal jumlah angka bola yang diperlukan, dan opsi bola yang ada. Setiap bola memiliki angka yang berbeda. Dalam game ini ad beberapa opsi yang tersedia untuk memilih bola, namun dari banyaknya opsi yang tersedia, pemain harus menemukan jumlah bola minimum yang total angkanya dapat mencapai jumlah angka bola yang diperlukan tidak kurang dan tidak lebih. Pemain yang gagal dalam game ini harus mentraktir bakso Kang Ujang selama Satu Bulan

# Ketika Adit dan teman lainnya telah selesai mencoba, tibalah giliran Denis. Denis terlihat bingung dalam bermainnya dan kata kata andalannya pun keluar, "Adit tolongin aku dit...", Aditpun tidak tega melihat Deniss akhirnya mencoba untuk membantunyaa. "Tenang Den, bayangin kalo kamu jadi Programmer".

# Bantulah Adit untuk menyelesaikan solusinya. Gunakan pendekatan Decrease and Conquer.

# Input Format

# Baris pertama berisi dua bilangan bulat N dan H:

# Baris kedua berisi N bilangan bulat yang menyatakan daftar angka bola yang dapat digunakan. Tiap angka bola berada dalam rentang (1 ≤ A[i] ≤ H).

# Constraints

# N (1 ≤ N ≤ 100) menyatakan jumlah pilihan tinggi anak tangga yang tersedia. H (1 ≤ H ≤ 10⁶) menyatakan tinggi total yang harus dicapai.

# Output Format

# Cetak satu bilangan bulat yang menyatakan jumlah bola minimum yang diperlukan untuk mencapai tepat H. Jika tidak mungkin mencapai angka H, cetak -1.

# Sample Input 0

# 3 10  
# 1 3 5  
# Sample Output 0

# 2
# Explanation 0

# (Menggunakan 5 + 5 atau 3 + 3 + 3 + 1)

# Sample Input 1

# 5 7  
# 1 2 4 6 8  
# Sample Output 1

# 2
# Explanation 1

# (Menggunakan 4 + 2 + 1 atau 6 + 1, dsb.)

# Sample Input 2

# 5 15  
# 4 6 9 3 5  
# Sample Output 2

# 2
# Explanation 2

# (Menggunakan 6 + 6 + 3 atau 9 + 3 + 3, dsb.)

def BantuDenis(daftarBola, target):
    if target == 0:
        return 0
    if target < 0:
        return float('inf')
    
    jumlahMinimum = float('inf')
    for bola in daftarBola:
        jumlahBola = BantuDenis(daftarBola, target - bola)
        if jumlahBola != float('inf'):
            jumlahMinimum = min(jumlahMinimum, jumlahBola + 1)
    
    return jumlahMinimum

n, target = map(int, input().split())
daftarBola = list(map(int, input().split()))
hasil = BantuDenis(daftarBola, target)
print(hasil if hasil != float("inf") else -1)

