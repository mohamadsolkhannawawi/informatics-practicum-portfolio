# Beberapa waktu lalu Pastry Mille Morteln si Pangeran bungsu kerajaan Morteln memutuskan untuk membuka toko rotinya sendiri! Dia membeli bahan-bahan yang dibutuhkan dan oven ajaib yang dapat memanggang beberapa jenis kue, dan membuka toko roti.

# Segera setelah pengeluaran mulai melebihi pendapatan, Pastry Mille Morteln memutuskan untuk mempelajari pasar permen. Dia belajar bahwa mengemas kue dalam kotak menguntungkan dan bahwa semakin berbeda jenis kue yang terkandung dalam kotak (mari kita tunjukkan angka ini sebagai nilai kotak), semakin tinggi harganya.

# Dia perlu mengubah teknologi produksi! Masalahnya adalah oven memiliki kehendak sendiri dan memilih jenis kue sendiri dan Pastry Mille Morteln tidak dapat memengaruhinya. Namun, dia tahu jenis dan urutan  kue yang akan dipanggang oven hari ini. Pastry Mille Morteln harus mengemas tepat  kotak dengan kue hari ini, dan dia harus memasukkan ke dalam setiap kotak beberapa (setidaknya satu) kue yang dihasilkan oven satu demi satu (dengan kata lain, dia harus memasukkan ke dalam kotak segmen kue yang terus menerus).

# Pastry Mille Morteln ingin memaksimalkan nilai total semua kotak dengan kue. Bantu dia menentukan nilai total maksimum yang mungkin ini.

# Contoh

# input :

# 4 1

# 1 2 2 1

# output : 2

# alasan: Dalam contoh pertama Pastry Mille Morteln hanya memiliki satu kotak. Dia harus memasukkan semua kue ke dalamnya, sehingga ada dua jenis kue di dalam kotak, sehingga nilainya sama dengan 2.

# input :

# 7 2

# 1 3 3 1 4 4 4

# output : 5

# alasan: Pada contoh kedua, menguntungkan untuk memasukkan dua kue pertama ke dalam kotak pertama, dan sisanya di kotak kedua. Ada dua jenis yang berbeda di kotak pertama, dan tiga di kotak kedua kemudian, jadi nilai totalnya adalah 5.

# Input Format

# Baris pertama berisi dua bilangan bulat n dan k (1 ≤ n ≤ 35000, 1 ≤ k ≤ min(n, 50)) – jumlah kue dan jumlah kotak, masing-masing

# Constraints

# -
# Output Format

# Cetak satu-satunya bilangan bulat – nilai total maksimum dari semua kotak dengan kue.

# Sample Input 0

# 7 2
# 1 3 3 1 4 4 4
# Sample Output 0

# 5
# Sample Input 1

# 4 1
# 1 2 2 1
# Sample Output 1

# 2

def solve(n, k, cakes):
    result = 0      # Variabel untuk menyimpan total nilai semua kotak
    idx = 0         # Indeks untuk melacak posisi saat memproses daftar kue

    # Iterasi untuk setiap kotak yang tersedia
    for i in range(k):
        unique_cakes = set()   # Set untuk menyimpan jenis kue unik di kotak saat ini

        # Jika ini adalah kotak terakhir, masukkan semua sisa kue ke dalam kotak
        if i == k - 1:
            unique_cakes = set(cakes[idx:])   # Masukkan semua sisa kue yang belum dimasukkan
            result += len(unique_cakes)       # Tambahkan jumlah jenis kue unik ke total nilai
            break                             # Keluar dari loop karena semua kue sudah terpakai

        # Untuk kotak selain yang terakhir, masukkan kue hingga ada minimal 2 jenis berbeda
        while idx < n and len(unique_cakes) < 2:
            unique_cakes.add(cakes[idx])  # Tambahkan jenis kue ke dalam set
            idx += 1                      # Pindah ke kue berikutnya

        result += len(unique_cakes)       # Tambahkan jumlah jenis unik di kotak ini ke total nilai

    return result   # Kembalikan nilai total dari semua kotak

# Input dari pengguna
n, k = map(int, input().split())         # Baca input jumlah kue (n) dan jumlah kotak (k)
cakes = list(map(int, input().split()))  # Baca urutan jenis kue yang dipanggang oven

print(solve(n, k, cakes))                # Cetak hasil nilai total maksimum semua kotak

def kotak_kue(n, k, kue):
    hasil = 0
    index = 0
    for i in range(k):
        jenis_kue = set()
        if i == k - 1:
            jenis_kue = set(kue[index:])
            hasil += len(jenis_kue)
            break
        while index < n and len(jenis_kue) < 2:
            jenis_kue.add(kue[index])
            index += 1
            
        hasil += len(jenis_kue)
    return hasil

n, k = map(int, input().split())
kue = list(map(int, input().split()))
print(kotak_kue(n, k, kue))



def kue_unik(daftar):
    unik = []
    for item in daftar:
        if item not in unik:
            unik.append(item)
    return unik

def kotak_kue(n, k, kue):
    hasil = 0
    index = 0
    for i in range(k):
        jenis_kue = []
        if i == k - 1:
            jenis_kue = kue_unik(kue[index:])
            hasil += len(jenis_kue)
            break
        while index < n and len(jenis_kue) < 2:
            if kue[index] not in jenis_kue:
                jenis_kue.append(kue[index])
            index += 1
        hasil += len(jenis_kue)
    return hasil

n, k = map(int, input().split())
kue = list(map(int, input().split()))
print(kotak_kue(n, k, kue))