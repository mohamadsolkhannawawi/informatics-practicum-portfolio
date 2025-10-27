"""
Di dunia virtual, seorang pemain video game sedang terjebak dalam labirin berisi monster. Labirin tersebut digambarkan dalam bentuk matriks, di mana 1 menunjukkan area yang dapat dilalui pemain dan 0 menunjukkan dinding. Pemain harus menemukan dan menghitung jumlah zona aman yang dapat dijelajahi tanpa bertemu monster.

Setiap zona aman (nilai 1) terhubung secara horizontal atau vertikal, namun tidak diagonal. Sementara zona berbahaya (nilai 0) tidak bisa dilewati.

Catatan: - Gunakan Algoritma Depth-First Search (DFS)

Input Format

Baris pertama: dua bilangan bulat n dan m, yang menunjukkan jumlah baris dan kolom pada matriks.
Diikuti n baris, masing-masing berisi m bilangan (0 atau 1) yang dipisahkan oleh spasi.
Constraints

1 ≤ n, m ≤ 1000

Output Format

Sebuah bilangan bulat yang menunjukkan jumlah zona aman yang dapat dijelajahi pemain.

Sample Input 0

5 5
1 1 0 0 0
1 1 0 0 0
0 0 1 1 0
0 0 0 1 1
1 1 1 0 0
Sample Output 0

3
Sample Input 1

3 4
1 0 0 0
1 1 1 0
0 0 1 1
Sample Output 1

1
Sample Input 2

4 4
1 1 0 0
0 1 0 0
1 1 0 0
0 0 1 1
Sample Output 2

2

"""
def dfs(grid, i, j, m, n):
    if i < 0 or i >= m or j < 0 or j >= n:
        return
    if grid[i][j] != 1:
        return

    grid[i][j] = -1
    dfs(grid, i+1, j, m, n)  # ke bawah
    dfs(grid, i-1, j, m, n)  # ke atas
    dfs(grid, i, j+1, m, n)  # ke kanan
    dfs(grid, i, j-1, m, n)  # ke kiri

def count_safe_zones(grid, m, n):
    count = 0
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1:
                dfs(grid, i, j, m, n)
                count += 1
    return count

m, n = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(m)]
print(count_safe_zones(grid, m, n))