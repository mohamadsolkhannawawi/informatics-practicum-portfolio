"""
Okabe suka bisa berjalan melalui kotanya di jalan setapak yang diterangi oleh lampu jalan. Dengan begitu, dia tidak dipukuli oleh anak-anak sekolah.

Kota Okabe diwakili oleh kisi-kisi sel 2D. Baris diberi nomor dari 1 hingga n dari atas ke bawah, dan kolom diberi nomor 1 hingga m dari kiri ke kanan. Tepat k sel di kota diterangi oleh lampu jalan. Dijamin bahwa sel kiri atas menyala.

Okabe memulai perjalanannya dari sel kiri atas, dan ingin mencapai sel kanan bawah. Tentu saja, Okabe hanya akan berjalan di atas sel yang menyala, dan dia hanya bisa bergerak ke sel yang berdekatan ke arah atas, bawah, kiri, dan kanan. Namun, Okabe juga dapat menyalakan sementara semua sel dalam satu baris atau kolom pada satu waktu jika dia membayar 1 koin, memungkinkannya untuk berjalan melalui beberapa sel yang tidak menyala pada awalnya.

Perhatikan bahwa Okabe hanya dapat menyalakan satu baris atau kolom pada satu waktu, dan harus membayar koin setiap kali dia menyalakan baris atau kolom baru. Untuk mengubah baris atau kolom yang menyala sementara, ia harus berdiri di sel yang menyala pada awalnya. Selain itu, setelah dia menghapus cahaya sementaranya dari baris atau kolom, semua sel dalam baris/kolom yang awalnya tidak menyala sekarang tidak menyala.

Bantu Okabe menemukan jumlah minimum koin yang harus dia bayar untuk menyelesaikan perjalanannya!

format input : Baris pertama input berisi tiga bilangan bulat yang dipisahkan spasi n, m, dan k (2 ≤ n, m, k ≤ 10000).

Masing-masing baris k berikutnya berisi dua bilangan bulat yang dipisahkan ruang ri dan ci (1 ≤ ri ≤ n, 1 ≤ ci ≤ m). baris dan kolom sel menyala ke-i.

Dijamin bahwa semua sel k berbeda. Dijamin bahwa sel kiri atas menyala.

Input Format

Baris pertama input berisi tiga bilangan bulat yang dipisahkan spasi n, m, dan k (2 ≤ n, m, k ≤ 10000).

Constraints

-

Output Format

Cetak jumlah minimum koin yang harus dibayar Okabe untuk menyelesaikan perjalanannya, atau -1 jika tidak memungkinkan.

Sample Input 0

4 4 5
1 1
2 1
2 3
3 3
4 3
Sample Output 0

2
"""

def min_coins_dfs(n, m, k, lit_cells):
    grid = [[0] * m for _ in range(n)]
    for r, c in lit_cells:
        grid[r-1][c-1] = 1
    
    best_coins = {}
    def dfs(r, c, coins, light_type, light_index):
        if r < 0 or r >= n or c < 0 or c >= m:
            return float('inf')

        cell_lit = grid[r][c] == 1 or (light_type == 1 and r == light_index) or (light_type == 2 and c == light_index)
        if not cell_lit:
            return float('inf')
        
        if r == n-1 and c == m-1:
            return coins
        
        state = (r, c, light_type, light_index)
        if state in best_coins and best_coins[state] <= coins:
            return float('inf')
        
        best_coins[state] = coins
        min_result = float('inf')
        
        result = dfs(r+1, c, coins, light_type, light_index)  # ke bawah
        min_result = min(min_result, result)
        
        result = dfs(r-1, c, coins, light_type, light_index)  # ke atas
        min_result = min(min_result, result)
        
        result = dfs(r, c+1, coins, light_type, light_index)  # ke kanan
        min_result = min(min_result, result)
        
        result = dfs(r, c-1, coins, light_type, light_index)  # ke kiri
        min_result = min(min_result, result)
        
        if grid[r][c] == 1:
            for new_row in range(n):
                if new_row != light_index or light_type != 1:  
                    result = dfs(r, c, coins + 1, 1, new_row)
                    min_result = min(min_result, result)
            
            for new_col in range(m):
                if new_col != light_index or light_type != 2:  
                    result = dfs(r, c, coins + 1, 2, new_col)
                    min_result = min(min_result, result)
        
        return min_result
    
    result = dfs(0, 0, 0, 0, -1)
    return result if result != float('inf') else -1

n, m, k = map(int, input().split())
lit_cells = []
for _ in range(k):
    r, c = map(int, input().split())
    lit_cells.append((r, c))
print(min_coins_dfs(n, m, k, lit_cells))