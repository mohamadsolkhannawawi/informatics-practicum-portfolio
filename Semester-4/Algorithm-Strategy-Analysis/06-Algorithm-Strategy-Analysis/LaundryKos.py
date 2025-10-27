def binary_search_lantai(batas_awal, x):
    """Mencari lantai tempat kamar x berada menggunakan binary search manual"""
    left, right = 0, len(batas_awal) - 1
    while left <= right:
        mid = (left + right) // 2
        if batas_awal[mid] <= x:
            left = mid + 1
        else:
            right = mid - 1
    return right  # Index lantai yang sesuai

def laundry_kos():
    # Baca input
    n, m = map(int, input().split())  # Baca jumlah lantai dan jumlah kamar yang dicari
    f = list(map(int, input().split()))  # Baca jumlah kamar di setiap lantai
    kamar_lama = [int(input()) for _ in range(m)]  # Baca daftar kamar yang perlu dikonversi

    # Hitung batas awal tiap lantai
    batas_awal = [0] * n
    batas_awal[0] = 1  # Lantai 1 mulai dari kamar 1
    for i in range(1, n):
        batas_awal[i] = batas_awal[i - 1] + f[i - 1]

    # Proses setiap kamar yang diberikan
    for x in kamar_lama:
        lantai = binary_search_lantai(batas_awal, x)  # Cari lantai dengan binary search manual
        nomor_kamar_baru = x - batas_awal[lantai] + 1  # Hitung nomor kamar di lantai tersebut
        print(lantai + 1, nomor_kamar_baru)  # Cetak hasil

# Jalankan program
laundry_kos()
