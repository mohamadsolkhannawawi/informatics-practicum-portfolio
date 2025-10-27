# Tim ekspedisi luar angkasa dari Galactic Exploration Union (GEU) sedang menjalankan misi eksplorasi di Planet Zygma, sebuah planet misterius dengan medan yang ekstrem. Untuk mengangkut sumber daya dan melakukan penelitian, mereka perlu membangun jalur ekspedisi yang paling aman agar kendaraan mereka tidak mengalami kerusakan akibat perubahan ketinggian yang terlalu drastis.

# Dari hasil pemetaan, didapatkan N titik ketinggian yang merepresentasikan jalur potensial yang bisa dilalui. Namun, tidak semua jalur memiliki kondisi yang ideal. Tim GEU harus menemukan dua titik dengan selisih ketinggian terkecil di jalur tersebut. Karena banyaknya data yang dikumpulkan, tim memerlukan algoritma Divide and Conquer untuk menemukan solusi secara efisien.

# Namun, ada tantangan tambahan! Jika ada lebih dari satu pasang titik yang memiliki selisih terkecil, maka sistem harus mencari pasangan dengan indeks terkecil dalam daftar.

# Input Format

# Format Masukan: Baris pertama berisi satu bilangan bulat N (2 ≤ N ≤ 10⁵), menyatakan jumlah titik ketinggian yang telah dikumpulkan. Baris kedua berisi N bilangan bulat yang dipisahkan oleh spasi, menyatakan ketinggian dari setiap titik di jalur tersebut. Nilai dari setiap ketinggian: -10⁹ ≤ A[i] ≤ 10⁹

# Constraints

# Jumlah Titik Ketinggian (N):
# - 2≤N≤100000 - Minimal harus ada dua titik agar bisa dihitung selisihnya.

# Nilai Ketinggian Tiap Titik ( A[i] ):
# - -10⁹ ≤ A[i] ≤ 10⁹ - Bisa berupa bilangan positif, negatif, atau nol.

# Output Format

# Cetak dua bilangan bulat:

# Selisih ketinggian terkecil di antara dua titik. Indeks terkecil dari pasangan yang memiliki selisih tersebut (indeks dimulai dari 1).

# Sample Input 0

# 6  
# 10 15 12 18 19 21  
# Sample Output 0

# 1 4
# Sample Input 1

# 4  
# -50 -47 -45 -40  
# Sample Output 1

# 2 2
# Sample Input 2

# 3  
# -1000000000 0 1000000000  
# Sample Output 2

# 1000000000 1


def merge_sort(data):
    # Jika panjang data kurang dari 2, data dianggap sudah terurut
    if len(data) <= 1:
        return data

    # Tentukan titik tengah untuk membagi data
    mid = len(data) // 2
    # Rekursi ke bagian kiri dan kanan
    left = merge_sort(data[:mid])
    right = merge_sort(data[mid:])

    # Gabungkan hasil dari kedua bagian yang telah diurutkan
    return merge(left, right)

def merge(left, right):
    result = []
    i = j = 0

    # Gabungkan dua bagian dengan membandingkan elemen dari kiri dan kanan
    while i < len(left) and j < len(right):
        if left[i][0] < right[j][0]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    # Tambahkan sisa elemen yang belum digabungkan
    result.extend(left[i:])
    result.extend(right[j:])
    return result

def temukan_selisih_terkecil(N, ketinggian):
    # Pasangkan ketinggian dengan indeks aslinya (indeks dimulai dari 1)
    data = [(ketinggian[i], i + 1) for i in range(N)]
    
    # Urutkan data menggunakan merge sort manual
    data = merge_sort(data)

    # Inisialisasi selisih terkecil dan indeks terkecil
    min_selisih = float('inf')
    min_indeks = -1

    # Cek selisih terkecil dengan membandingkan elemen yang berdekatan
    for i in range(1, N):
        selisih = abs(data[i][0] - data[i - 1][0])
        indeks = min(data[i][1], data[i - 1][1])

        # Update jika ditemukan selisih yang lebih kecil atau indeks yang lebih kecil
        if selisih < min_selisih or (selisih == min_selisih and indeks < min_indeks):
            min_selisih = selisih
            min_indeks = indeks

    return min_selisih, min_indeks

# ----------------------- Bagian Utama Program -----------------------

# Input jumlah titik ketinggian
N = int(input())

# Input daftar ketinggian yang dipisahkan oleh spasi
ketinggian = list(map(int, input().split()))

# Proses pencarian selisih terkecil dan indeks terkecil
selisih, indeks = temukan_selisih_terkecil(N, ketinggian)

# Cetak hasil berupa selisih terkecil dan indeks terkecil
print(f"{selisih} {indeks}")


def merge_sort(data):
    if len(data) <= 1:
        return data
    
    tengah = len(data) // 2
    kiri = merge_sort(data[:tengah])
    kanan = merge_sort(data[tengah:])
    return merge(kiri, kanan)

def merge(kiri, kanan):
    hasil = []
    i = 0
    j = 0
    while i < len(kiri) and j < len(kanan):
        if kiri[i][0] < kanan[j][0]:
            hasil.append(kiri[i])
            i += 1
        else:
            hasil.append(kanan[j])
            j += 1
    
    hasil.extend(kiri[i:])
    hasil.extend(kanan[j:])
    return hasil

def selisih_terkecil(N, ketinggian):
    salinan = [(ketinggian[i], i + 1) for i in range(N)]
    salinan = merge_sort(salinan)

    min_selisih = float('inf')
    min_index = -1
    for i in range(1, N):
        selisih = abs(salinan[i][0] - salinan[i - 1][0])
        index = min(salinan[i][1], salinan[i -1][1])
        if selisih < min_selisih or (selisih == min_selisih and index < min_index):
            min_selisih = selisih
            min_index = index

    return min_selisih, min_index

N = int(input())
ketinggian = list(map(int, input().split()))
selisih, index = selisih_terkecil(N, ketinggian)
print(f"{selisih} {index}")

# ! test Komen
# ? eyaa
# // eya
# TODO 

