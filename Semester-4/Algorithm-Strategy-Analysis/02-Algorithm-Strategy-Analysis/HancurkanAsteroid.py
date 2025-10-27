# Asuka merupakan seorang pengelola ruang angkasa dari organisasi NASI. Asuka memetakan ruang angkasa dengan sistem koordinat kartesius yang dimulai dari pojok kiri bawah (0,0). Setelah berhasil memetakan posisi seluruh asteroid yang ada, Asuka ingin menghancurkan ateroid tersebut sebanyak mungkin dengan menggunakan laser. Laser tersebut dapat menjangkau seluruh asteroid secara horizontal dan vertikal. 

# Berikut ini adalah contoh dari pemetaan asteroid:
# 4 5 1 3 5 1 2
# 1 2 2 5 3 1 6
# 5 2 2 1 1 7 2
# 3 5 2 5 1 5 6

# Posisi meletakkan laser terbaik ada pada posisi (0, 0) dengan total asteroid yang dihancurkan sebanyak 37.
# X 5 1 3 5 1 2
# X 2 2 5 3 1 6
# X 2 2 1 1 7 2
# X X X X X X X

# Bantulah Asuka untuk menentukan posisi terbaik yang dapat menghancurkan asteroid sebanyak mungkin.
# Input Format

# Baris pertama berisikan 2 buah bilangan bulat  yang menyatakan baris dan kolom.

#  baris berikutnya berisikan  bilangan bulat yang menyatakan jumlah ada asteroid pada posisi tersebut.

# Constraints


# Untuk 90% testcases berlaku 

# Untuk 10% testcases berlaku 

# Output Format

# Keluarkan 3 bilangan bulat  yang masing masing menyatakan koordinat (x,y) dan k adalah jumlah asteroid terbanyak yang dapat dihancurkan.

# Jika ada 2 posisi memiliki jumlah asteroid yang sama, keluarkan dengan posisi  terkecil terlebih dahulu, jika  sama, keluarkan  terkecil.

# Sample Input 0

# 4 6
# 4 5 1 3 5 1 2
# 1 2 2 5 3 1 6
# 5 2 2 1 1 7 2
# 3 5 2 5 1 5 6
# Sample Output 0

# 0 0 37
# Sample Input 1

# 6 10
# 32 75 95 15 19 35 34 77 73 54
# 37 69 57 43 69 70 96 8 75 88
# 63 21 91 1 92 74 69 79 30 10
# 82 41 4 71 75 66 47 50 60 67
# 57 100 49 67 82 24 78 20 42 39
# 99 26 50 69 84 79 59 59 2 72
# Sample Output 1

# 4 4 964
# Sample Input 2

# 6 6
# 1 0 1 0 0 1
# 0 0 0 0 0 0
# 1 0 1 1 1 1
# 0 0 1 1 0 1
# 0 0 0 0 0 0
# 0 0 0 0 1 0
# Sample Output 2

# 2 3 7

# 4 7
# 4 5 1 3 5 1 2
# 1 2 2 5 3 1 6
# 5 2 2 1 1 7 2
# 3 5 2 5 1 5 6

def HancurkanAsteroid(Baris, Kolom, Matrik):
    maxPenghancuran = 0
    best_X, best_Y = 0, 0

    sumBaris = [sum(Matrik[i]) for i in range(Baris)]
    print(f"sumBaris: {sumBaris}")
    sumKolom = [sum(Matrik[i][j] for i in range(Baris)) for j in range(Kolom)]
    print(f"sumKolom: {sumKolom}")

    for i in range(Baris):
        for y in range(Kolom):
            x = Baris - 1 - i
            currentPenghancuran = sumBaris[i] + sumKolom[y] - Matrik[i][y]
            print(f"x: {y}, y: {x}")
            print(f"currentPenghancuran: {currentPenghancuran}")
            print(f"maxPenghancuran: {maxPenghancuran}, best_X: {best_X}, best_Y: {best_Y}")
            if currentPenghancuran > maxPenghancuran or (currentPenghancuran == maxPenghancuran and (x < best_X or (x == best_X and y < best_Y))):
                maxPenghancuran = currentPenghancuran
                best_X, best_Y = y, x
                print(f"maxPenghancuran: {maxPenghancuran}, best_X: {best_X}, best_Y: {best_Y}")

    print(best_X, best_Y, maxPenghancuran)

Baris, Kolom = map(int, input().split())
Matrik = [list(map(int, input().split())) for _ in range(Baris)]
HancurkanAsteroid(Baris, Kolom, Matrik)