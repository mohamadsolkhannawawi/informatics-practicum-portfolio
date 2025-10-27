# Bantu SJW (Sobat Joko Widodo) maksudnya Sung Jin-Woo mempersiapkan item untuk pergi ke dungeon terakhir. Sung Jin-Woo sedang bersiap untuk menghadapi Dungeon level 100, tetapi untuk itu, ia perlu menjual beberapa barang berharga yang ia dapatkan dari dungeon sebelumnya. Setiap barang yang ditemukan memiliki nilai tertentu, dan Sung Jin-Woo ingin memilih tiga barang yang nilainya meningkat dalam urutan yang sama dari dua daftar berbeda: daftar pertama adalah urutan barang berdasarkan kekuatan dari barang tersebut dan daftar kedua adalah urutan berdasarkan harga jual di toko.

# Tugasnya adalah mencari kombinasi tiga barang yang memiliki urutan meningkat di kedua daftar tersebut. Dengan menemukan kombinasi barang yang tepat, Sung Jin-Woo bisa memaksimalkan keuntungan dan memperoleh cukup emas untuk membeli perlengkapan yang dibutuhkan sebelum menghadapi tantangan berikutnya.

# Kita diberikan dua daftar barang yang merupakan permutasi dari angka 0 hingga 𝑛 −1, di mana 𝑛 adalah jumlah total barang yang ditemukan. Kita perlu menghitung berapa banyak kombinasi barang (3 Jenis barang sekaligus) yang dapat dipilih dengan aturan peningkatan urutan yang sesuai di kedua daftar.

# Contoh:

# Input

# 2 0 1 3   
# 0 1 2 3
# Output:

# 1
# Explanation:

# Dalam nums1, terdapat empat kemungkinan kombinasi yang memiliki urutan meningkat, yaitu
# 2,0,1, 
# 2,0,3, 
# 2,1,3,
# 0,1,3. 
# Namun, setelah diperiksa dengan urutan  di nums2, hanya (0,1,3) yang juga meningkat. Oleh karena itu, jumlah kombinasi yang valid adalah 1, sehingga outputnya adalah 1.
# Input Format

# Array Of Integer
# Array Of Integer
# Constraints

# n == nums1.length == nums2.length
# 3 <= n <= 105
# 0 <= nums1[i], nums2[i] <= n - 1
# nums1 and nums2 adalah permutasi dari [0, 1, ..., n - 1].
# Output Format

# Integer
# Sample Input 0

# 2 0 1 3
# 0 1 2 3
# Sample Output 0

# 1
# Sample Input 1

# 4 0 1 3 2
# 4 1 0 2 3
# Sample Output 1

# 4

class FenwickTree:
    def __init__(self, size):
        self.tree = [0] * (size + 1)

    def update(self, index, value):
        index += 1
        while index < len(self.tree):
            self.tree[index] += value
            index += index & -index

    def query(self, index):
        index += 1
        result = 0
        while index > 0:
            result += self.tree[index]
            index -= index & -index
        return result

def hitung_kombinasi(nums1, nums2):
    n = len(nums1)

    # Mapping posisi di nums2
    posisi = {num: i for i, num in enumerate(nums2)}

    # Ubah nums1 ke urutan posisi di nums2
    urutan = [posisi[num] for num in nums1]

    # Fenwick Tree untuk menghitung left dan right count
    left_tree = FenwickTree(n)
    right_tree = FenwickTree(n)

    # Hitung right count terlebih dahulu
    right_count = [0] * n
    for i in reversed(range(n)):
        right_count[i] = right_tree.query(n - 1) - right_tree.query(urutan[i])
        right_tree.update(urutan[i], 1)

    # Hitung left count dan hasil akhir
    result = 0
    for i in range(n):
        left_count = left_tree.query(urutan[i] - 1)
        result += left_count * right_count[i]
        left_tree.update(urutan[i], 1)

    return result

# Input dari pengguna
nums1 = list(map(int, input().split()))
nums2 = list(map(int, input().split()))

# Output hasil
print(hitung_kombinasi(nums1, nums2))


def update(tree, index, value):
    # Mengubah index ke basis 1 (karena Fenwick Tree menggunakan 1-based indexing)
    index += 1
    
    # Iterasi untuk memperbarui semua node yang terpengaruh dalam Fenwick Tree
    while index < len(tree):
        # Tambahkan 'value' ke posisi saat ini dalam tree
        tree[index] += value
        
        # Bergerak ke node berikutnya yang mencakup index ini
        # index & -index adalah operasi bit untuk makhirapatkan LSB (least significant bit)
        # Ini memastikan kita memperbarui semua node yang terkait
        index += index & -index

def query(tree, index):
    # Mengubah index ke basis 1 (1-based index untuk Fenwick Tree)
    index += 1
    hasil = 0
    # Proses query untuk menjumlahkan prefix sum hingga indeks tertentu
    while index > 0:
        hasil += tree[index]
        # Bergerak ke parent node berikutnya dalam Fenwick Tree
        index -= index & -index
    return hasil

def hitung_kombinasi(nums1, nums2):
    n = len(nums1)

    # Membuat mapping posisi dari elemen nums2 untuk memudahkan pencarian
    # Contoh: nums2 = [0,1,2,3] => posisi = {0:0, 1:1, 2:2, 3:3}
    posisi = {num: i for i, num in enumerate(nums2)}

    # Mengonversi elemen nums1 ke posisi mereka di nums2
    # Contoh: nums1 = [2,0,1,3] => urutan = [2,0,1,3]
    urutan = [posisi[num] for num in nums1]

    # Inisialisasi dua Fenwick Tree (BIT) untuk menghitung kombinasi
    left_tree = [0] * (n + 1)
    right_tree = [0] * (n + 1)

    # right_count[i] akan menyimpan jumlah elemen di sebelah kanan yang lebih kecil dari urutan[i]
    right_count = [0] * n
    # Iterasi dari belakang untuk menghitung right_count
    for i in reversed(range(n)):
        # Hitung jumlah elemen yang lebih besar dari urutan[i] di sisi kanan
        right_count[i] = query(right_tree, n - 1) - query(right_tree, urutan[i])
        # Update Fenwick Tree untuk menambahkan elemen urutan[i]
        update(right_tree, urutan[i], 1)

    hasil = 0
    # Iterasi dari kiri untuk menghitung kombinasi dengan right_count
    for i in range(n):
        # Hitung jumlah elemen yang lebih kecil dari urutan[i] di sisi kiri
        left_count = query(left_tree, urutan[i] - 1)
        # Kombinasi valid dihitung dengan perkalian left_count dan right_count
        hasil += left_count * right_count[i]
        # Update Fenwick Tree untuk menambahkan elemen urutan[i]
        update(left_tree, urutan[i], 1)

    # Mengembalikan total jumlah kombinasi yang valid
    return hasil

# Membaca input nums1 dan nums2 dari pengguna
nums1 = list(map(int, input().split()))
nums2 = list(map(int, input().split()))

# Mencetak hasil dari fungsi hitung_kombinasi
print(hitung_kombinasi(nums1, nums2))

def update(tree, index, value):
    index += 1
    while index < len(tree):
        tree[index] += value
        index += index & -index

def query(tree, index):
    index += 1
    result = 0
    while index > 0:
        result += tree[index]
        index -= index & -index
    return result

def hitung_kombinasi(nums1, nums2):
    n = len(nums1)

    posisi = {num: i for i, num in enumerate(nums2)}

    urutan = [posisi[num] for num in nums1]

    left_tree = [0] * (n + 1)
    right_tree = [0] * (n + 1)

    right_count = [0] * n
    for i in reversed(range(n)):
        right_count[i] = query(right_tree, n - 1) - query(right_tree, urutan[i])
        update(right_tree, urutan[i], 1)

    result = 0
    for i in range(n):
        left_count = query(left_tree, urutan[i] - 1)
        result += left_count * right_count[i]
        update(left_tree, urutan[i], 1)

    return result

nums1 = list(map(int, input().split()))
nums2 = list(map(int, input().split()))
print(hitung_kombinasi(nums1, nums2))



def build_tree(size):
    return [0] * (2 * size)

def update(tree, size, index, value):
    index += size  # Shift to leaf position
    tree[index] += value
    while index > 1:
        index //= 2
        tree[index] = tree[2 * index] + tree[2 * index + 1]

def query(tree, size, kiri, kanan):
    hasil = 0
    kiri += size
    kanan += size
    while kiri < kanan:
        if kiri % 2 == 1:
            hasil += tree[kiri]
            kiri += 1
        if kanan % 2 == 1:
            kanan -= 1
            hasil += tree[kanan]
        kiri //= 2
        kanan //= 2
    return hasil

def hitung_kombinasi(nums1, nums2):
    n = len(nums1)
    posisi = {num: i for i, num in enumerate(nums2)}
    urutan = [posisi[num] for num in nums1]

    pohon_kiri = build_tree(n)
    pohon_kanan = build_tree(n)

    count_kanan = [0] * n
    for i in reversed(range(n)):
        count_kanan[i] = query(pohon_kanan, n, urutan[i] + 1, n)
        update(pohon_kanan, n, urutan[i], 1)

    hasil = 0
    for i in range(n):
        count_kiri = query(pohon_kiri, n, 0, urutan[i])
        hasil += count_kiri *count_kanan[i]
        update(pohon_kiri, n, urutan[i], 1)

    return hasil

kekuatan = list(map(int, input().split()))
harga = list(map(int, input().split()))
print(hitung_kombinasi(kekuatan, harga))


nums1 = [int (x) for x in input().split()]
nums2 = [int (x) for x in input().split()]

def count_meningkat(nums1, nums2):
    n = len(nums1)
    posisiNumSatu = [0] * n
    for i in range(n):
        posisiNumSatu[nums1[i]] = i

    posisiNum2 = [0] * n
    for i in range(n):
        posisiNum2[i] = posisiNumSatu[nums2[i]] # Berdasarkan num1
    
    return kombinasi_meningkat(posisiNum2, 0, n-1)

def kombinasi_meningkat(arr, awal, akhir):
    if akhir - awal + 1 <= 2:
        return 0
    
    tengah = (awal + akhir) // 2
    
    count_kiri = kombinasi_meningkat(arr, awal, tengah)
    count_kanan = kombinasi_meningkat(arr, tengah + 1, akhir)

    valid_index = validasi_index(arr, awal, tengah, akhir)

    return count_kiri + count_kanan + valid_index

def validasi_index(arr, awal, tengah, akhir):
    count = 0
    for i in range(awal, tengah + 1):
        for k in range(tengah + 1, akhir + 1):
            if arr[i] < arr[k]:
                for j in range(i + 1, k):
                    if arr[i] < arr[j] < arr[k]:
                        count += 1
    
    return count



nums1 = [int (x) for x in input().split()]
nums2 = [int (x) for x in input().split()]
hasil = count_meningkat(nums1, nums2)
print(hasil)