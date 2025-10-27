"""
Kamu adalah seorang Pencari Artefak dalam misi menembus labirin misterius demi menemukan artefak langka. Di dalam labirin ini terdapat dinding-dinding penghalang dan jalur sempit yang harus kamu jelajahi. Berdasarkan peta 2D yang menunjukkan posisimu, lokasi artefak, dan jalan yang tersedia, hitung berapa artefak yang bisa kamu jangkau sendiri. Hitung dengan cepat agar kamu dapat langsung menghubungi rekanmu bila artefak terlalu banyak.

Gunakan DFS untuk penelusuran labirinnya!

Notasi Map:

. = Jalur yang bisa dilewati
Y = Posisi kamu saat ini
# = Tembok yang menghalangi
A = Artefak
Input Format

Baris pertama berisi integer positif n dan m untuk jumlah baris dan kolom
Baris selanjutnya berisi grid matriks karakter n x m yang berisi sesuai notasi map di atas
Constraints

1 <= n, m <= 50
Posisi kamu dipastikan selalu satu.
'A' dapat berjumlah nol atau lebih.
Tidak ada karakter selain 'Y', 'A', '.', atau '#'.
Output Format

Sebuah bilangan bulat (integer) jumlah artefak yang bisa kamu jangkau.

Sample Input 0

4 4
Y . . #
# # . #
# A . #
# # . A
Sample Output 0

2
Explanation 0

Dari posisi 0,0 Kamu dapat menjangkau artefak di 3,2 dan 4,4

Sample Input 1

10 10
. . . . # . . # # Y
A # . . A . # . . .
# . . . . . # # . .
. . . . . # . . . .
# # # . . . . # # #
A . # # # . . . . .
# # . . . . . . . .
A # # # # # # A . .
. # # # # # # . # #
. . . . . . . . . .
Sample Output 1

4
"""
def dfs(grid, i, j, n, m, visited):
    if i < 0 or i >= n or j < 0 or j >= m:
        return 0
    if grid[i][j] == '#' or visited[i][j]:
        return 0

    visited[i][j] = True
    found = 1 if grid[i][j] == 'A' else 0

    found += dfs(grid, i+1, j, n, m, visited)  # bawah
    found += dfs(grid, i-1, j, n, m, visited)  # atas
    found += dfs(grid, i, j+1, n, m, visited)  # kanan
    found += dfs(grid, i, j-1, n, m, visited)  # kiri

    return found

n, m = map(int, input().split())
grid = [input().split() for _ in range(n)]

for i in range(n):
    for j in range(m):
        if grid[i][j] == 'Y':
            start_i, start_j = i, j
            break

visited = [[False]*m for _ in range(n)]
result = dfs(grid, start_i, start_j, n, m, visited)
print(result)