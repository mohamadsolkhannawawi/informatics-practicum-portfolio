"""
Diberikan sebuah grid 2D yang berisi 0 (lautan) dan 1 (daratan), hitunglah jumlah pulau yang ada. Sebuah pulau dibentuk oleh sel-sel daratan yang terhubung secara vertikal atau horizontal (tidak diagonal). Anda diminta menggunakan algoritma Depth-First Search (DFS) untuk menyelesaikan masalah ini.

Input Format

Baris pertama berisi dua bilangan bulat m dan n, masing-masing menunjukkan jumlah baris dan kolom grid.
Diikuti oleh m baris, masing-masing berisi n digit (0 atau 1) yang dipisahkan oleh spasi.
Constraints

1 ≤ m, n ≤ 100
Setiap elemen grid adalah 0 atau 1
Output Format

Satu baris berisi jumlah pulau yang terdeteksi dalam grid.

Sample Input 0

3 3
1 1 0
0 1 0
1 0 1
Sample Output 0

3
Sample Input 1

3 3
1 0 1
0 1 0
1 0 1
Sample Output 1

5
"""

def dfs(grid, i, j, m, n):
    if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0:
        return
    
    grid[i][j] = 0
    
    dfs(grid, i+1, j, m, n)  # ke bawah
    dfs(grid, i-1, j, m, n)  # ke atas
    dfs(grid, i, j+1, m, n)  # ke kanan
    dfs(grid, i, j-1, m, n)  # ke kiri

def numIslands(grid):
    if not grid:
        return 0
    
    m, n = len(grid), len(grid[0])
    num_islands = 0
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1:
                dfs(grid, i, j, m, n)
                num_islands += 1
    
    return num_islands

m, n = map(int, input().split())  
grid = [list(map(int, input().split())) for _ in range(m)] 
result = numIslands(grid)
print(result)