def find_best_laser_position(rows, cols, grid):
    max_destroyed = 0
    best_x, best_y = 0, 0

    # Hitung jumlah asteroid di setiap baris dan kolom
    row_sum = [sum(grid[i]) for i in range(rows)]
    col_sum = [sum(grid[i][j] for i in range(rows)) for j in range(cols)]

    # Cari posisi terbaik
    for x in range(rows):
        for y in range(cols):
            destroyed = row_sum[x] + col_sum[y] - grid[x][y]
            if destroyed > max_destroyed or (destroyed == max_destroyed and (x < best_x or (x == best_x and y < best_y))):
                max_destroyed = destroyed
                best_x, best_y = x, y

    print(best_x, best_y, max_destroyed)

# Contoh penggunaan
rows, cols = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(rows)]
find_best_laser_position(rows, cols, grid)