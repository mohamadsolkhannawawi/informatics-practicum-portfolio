def merge_sort(arr):
    """Menggunakan Merge Sort untuk mengurutkan array secara rekursif."""
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0

        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

def cari_pembagi(n, p=1, faktor=[]):
    """Menggunakan rekursi (Decrease and Conquer) untuk mencari faktor bilangan."""
    if p > n:
        return faktor
    if n % p == 0 and (n // p) == 13:
        faktor.append(p)
    return cari_pembagi(n, p + 1, faktor)

# Membaca input
N, t = map(int, input().split())  # Jumlah paket dan jumlah yang dikirim
jarak_paket = list(map(int, input().split()))  # Daftar jarak paket setelah disortir
paket_dikirim = list(map(int, input().split()))  # Indeks paket yang dikirim

# Proses setiap indeks paket yang dikirim Pai
hasil_akhir = []
for idx in paket_dikirim:
    faktor = cari_pembagi(jarak_paket[idx - 1])  # Cari faktor dari paket
    if not faktor:
        faktor = [-1]
    merge_sort(faktor)  # Urutkan faktor yang ditemukan
    hasil_akhir.extend(faktor)

# Cetak hasil dalam satu baris
print(" ".join(map(str, hasil_akhir)))
