# Nama file    : 24060123120020_TambangBerbahaya.py
# Nama Pembuat : Mohamad Solkhan Nawawi
# NIM          : 24060123120020
# # Deskripsi  : Program untuk menghitung luas poligon yang mewakili wilayah tambang sebelum dan sesudah evakuasi lokasi berbahaya.

# Menggunakan rumus luas poligon dengan koordinat titik
# 2A = (x1y2 - x2y1) + (x2y3 - x3y2) + (x3y4 - x4y3) + ... + (xny1 - x1yn)
# class Titik:
#     def __init__(self, x, y):
#         self.x = x
#         self.y = y
    
#     def __str__(self):
#         return f"({self.x}, {self.y})"
    
# # Luas poligon ketika hanya diketahui titik titiknya
# def luas_poligon(titik):
#     n = len(titik)
#     luas = 0
#     for i in range(n):
#         x1, y1 = titik[i].x, titik[i].y
#         x2, y2 = titik[(i + 1) % n].x, titik[(i + 1) % n].y
#         luas += x1 * y2 - x2 * y1
#     return abs(luas) / 2

# # Poligon yang sudah tidak ada titik berbahaya
# def poligon_aman(titik_awal, titik_bahaya):
#     titik_bahaya_set = set((t.x, t.y) for t in titik_bahaya)
#     titik_aman_bersih = [t for t in titik_awal if (t.x, t.y) not in titik_bahaya_set]
#     return titik_aman_bersih

# # Input jumlah titik awal
# n = int(input())
# # Input titik-titik awal
# titik_awal = []
# for _ in range(n):
#     x, y = map(int, input().split())
#     titik_awal.append(Titik(x, y))

# # Input jumlah titik berbahaya
# k = int(input())
# titik_bahaya = []
# for _ in range(k):
#     x, y = map(int, input().split());
#     titik_bahaya.append(Titik(x, y))

# print(f"{luas_poligon(titik_awal):.3f}")
# titik_aman = poligon_aman(titik_awal, titik_bahaya)
# print(f"{luas_poligon(titik_aman):.3f}")

import sys
def hitung_luas_poligon(vertices):
    n = len(vertices)
    if n < 3:
        return 0.0
    luas_ganda = 0
    for i in range(n):
        x1, y1 = vertices[i]
        x2, y2 = vertices[(i + 1) % n]
        luas_ganda += (x1 * y2) - (x2 * y1)
    return abs(luas_ganda) / 2.0

def main():
    try:
        n = int(sys.stdin.readline())
    except (IOError, ValueError):
        return
    titik_awal = []
    for _ in range(n):
        x, y = map(int, sys.stdin.readline().split())
        titik_awal.append((x, y))
    k = int(sys.stdin.readline())
    titik_bahaya_set = set()
    for _ in range(k):
        titik_bahaya_set.add(tuple(map(int, sys.stdin.readline().split())))

    luas_sebelum = hitung_luas_poligon(titik_awal)
    print(f"{luas_sebelum:.3f}")
    titik_aman = [p for p in titik_awal if p not in titik_bahaya_set]
    luas_sesudah = hitung_luas_poligon(titik_aman)
    print(f"{luas_sesudah:.3f}")
if __name__ == "__main__":
    main()


