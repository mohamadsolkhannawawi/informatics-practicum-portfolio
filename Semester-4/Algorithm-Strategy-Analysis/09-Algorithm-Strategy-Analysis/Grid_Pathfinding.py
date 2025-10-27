# Diberikan sebuah grid 2D berukuran N x M, di mana setiap sel dapat berupa jalan kosong (0)
# atau rintangan (1). Anda harus mencari jalur terpendek dari titik awal (sx, sy) 
# ke titik tujuan (gx, gy) menggunakan algoritma A*. Jika tidak ada jalur, kembalikan -1.

# Grid dapat dilalui secara horizontal dan vertikal (tidak diagonal), dan 
# setiap langkah memiliki biaya tetap = 1. Fungsi heuristik yang digunakan adalah Manhattan Distance.

# Input Format

# Baris pertama: dua bilangan bulat N dan M (jumlah baris dan kolom)
# Baris kedua: empat bilangan bulat sx sy gx gy (koordinat awal dan tujuan)
# Berikutnya N baris masing-masing berisi M elemen 0 atau 1 (grid)
# Constraints

# 1 <= N, M <= 100
# 0 <= sx, sy, gx, gy < max(N, M)
# Koordinat (sx, sy) dan (gx, gy) selalu berada di dalam grid dan bukan rintangan
# Sel 1 adalah rintangan, tidak dapat dilalui
# Hanya pergerakan atas, bawah, kiri, kanan yang diperbolehkan
# Output Format

# Satu bilangan bulat: panjang jalur terpendek dari start ke goal, atau -1 jika tidak ada jalur.

# Sample Input 0
# 3 3
# 0 0 2 2
# 0 0 0
# 0 1 0
# 0 0 0
# Sample Output 0
# 4

# Sample Input 1
# 1 1
# 0 0 0 0
# 0
# Sample Output 1
# 0

# Sample Input 2
# 5 5
# 0 0 4 4
# 0 1 0 1 0
# 0 1 0 1 0
# 0 1 0 1 0
# 0 1 0 1 0
# 0 0 0 0 0
# Sample Output 2
# 8

import heapq
def heuristic(x, y):
        return abs(x - gx) + abs(y - gy)

def Astar_Grid_Pathfinding(grid, start, goal):
    N, M = len(grid), len(grid[0])
    sx, sy = start
    gx, gy = goal

    pq = []
    heapq.heappush(pq, (heuristic(sx, sy), 0, sx, sy))

    visited = [[False]*M for _ in range(N)]
    visited[sx][sy] = True
    directions = [(1,0), (-1,0), (0,1), (0,-1)]

    while pq:
        f, g, x, y = heapq.heappop(pq)
        if (x, y) == (gx, gy):
            return g
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < N and 0 <= ny < M and not visited[nx][ny] and grid[nx][ny] == 0:
                visited[nx][ny] = True
                g_new = g + 1
                f_new = g_new + heuristic(nx, ny)
                heapq.heappush(pq, (f_new, g_new, nx, ny))
    return -1

N, M = map(int, input().split())
sx, sy, gx, gy = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(N)]
print(Astar_Grid_Pathfinding(grid, (sx, sy), (gx, gy)))
