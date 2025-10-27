# Nira adalah penguasa Tambang Kristal. Ia menguasai sejumlah lokasi kristal yang membentuk suatu wilayah dalam peta 2D. Lokasi-lokasi tersebut terhubung membentuk sebuah poligon, dan digunakan untuk menandai zona penggalian tambang. Namun, sebagian lokasi ditemukan memiliki radiasi berbahaya dan harus ditinggalkan.

# Setelah proses evakuasi, hanya lokasi-lokasi yang aman saja yang dipertahankan, dan zona tambang yang baru dibentuk dari titik-titik aman tersebut. Hitunglah luas wilayah tambang sebelum dan sesudah evakuasi.

# Format Masukan:

# Baris pertama: bilangan bulat N, banyaknya titik lokasi tambang awal.

# N baris berikutnya: masing-masing berisi koordinat X Y (titik lokasi tambang).

# Baris selanjutnya: bilangan bulat K, banyaknya titik yang terdeteksi berbahaya.

# K baris berikutnya: masing-masing koordinat X Y dari lokasi berbahaya.

# Format Keluaran:

# Dua baris:

# Luas wilayah tambang sebelum evakuasi

# Luas wilayah tambang setelah evakuasi

# Jawaban dibulatkan hingga 3 angka di belakang koma.

# Batasan:

# 3 ≤ N ≤ 1000

# 1 ≤ K ≤ N - 3

# −5000 ≤ x, y ≤ 5000

# Tidak ada koordinat yang sama

# Setelah evakuasi, jumlah titik masih membentuk poligon valid (minimal 3 titik dan membentuk loop tertutup)

# Contoh Masukan

# 5
# 0 0
# 4 0
# 4 3
# 2 4
# 0 3
# 2
# 4 0
# 4 3

# Contoh Keluaran:

# 14.000
# 3.000

# Nama file    : 24060123120020_TambangBerbahaya.py
# Nama Pembuat : Mohamad Solkhan Nawawi
# NIM          : 24060123120020
# # Deskripsi  : Program untuk menghitung luas poligon yang mewakili wilayah tambang sebelum dan sesudah evakuasi lokasi berbahaya.

#Menggunakan rumus luas poligon dengan koordinat titik
#2A = (x1y2 - x2y1) + (x2y3 - x3y2) + (x3y4 - x4y3) + ... + (xny1 - x1yn)
class Titik:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def __str__(self):
        return f"({self.x}, {self.y})"
    
# Luas poligon ketika hanya diketahui titik titiknya
def luas_poligon(titik):
    n = len(titik)
    luas = 0
    for i in range(n):
        x1, y1 = titik[i].x, titik[i].y
        x2, y2 = titik[(i + 1) % n].x, titik[(i + 1) % n].y
        luas += x1 * y2 - x2 * y1
    return abs(luas) / 2

def poligon_aman(titik_awal, titik_bahaya):
    titik_bahaya_set = set((t.x, t.y) for t in titik_bahaya)
    titik_aman_bersih = [t for t in titik_awal if (t.x, t.y) not in titik_bahaya_set]
    return titik_aman_bersih

# Input jumlah titik awal
n = int(input())
# Input titik-titik awal
titik_awal = []
for _ in range(n):
    x, y = map(int, input().split())
    titik_awal.append(Titik(x, y))

# Input jumlah titik berbahaya
k = int(input())
titik_bahaya = []
for _ in range(k):
    x, y = map(int, input().split());
    titik_bahaya.append(Titik(x, y))

print(f"{luas_poligon(titik_awal):.3f}")
titik_aman = poligon_aman(titik_awal, titik_bahaya)
print(f"{luas_poligon(titik_aman):.3f}")


