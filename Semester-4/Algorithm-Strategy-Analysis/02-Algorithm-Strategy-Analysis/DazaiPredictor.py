# Dazai, seorang pemikir jenius, sedang mengamati sebuah pertarungan di arena bawah tanah. Dalam pertarungan ini, ada dua petarung, yaitu Chuuya dan Akutagawa. Keduanya bertarung secara bergantian untuk menentukan siapa yang akan keluar sebagai juara.

# Di arena ini, terdapat deretan angka yang mewakili kekuatan serangan yang tersedia. Pada setiap giliran, seorang petarung dapat memilih satu angka dari ujung kiri atau ujung kanan deretan angka tersebut. Angka yang dipilih akan menambah skor petarung tersebut, dan angka tersebut akan dihapus dari daftar.

# Dazai ingin memprediksi siapa yang akan keluar sebagai juara dengan melihat urutan angka yang tersedia dan memastikan bahwa setiap petarung bermain secara optimal. Jika skor akhir Chuuya lebih besar dari atau sama dengan skor Akutagawa, maka Dazai akan menyatakan bahwa Chuuya akan menang. Jika tidak, maka Akutagawa yang akan menang.

# Contoh:

# Input:

# array = [1, 5, 2]

# Output: false

# Penjelasan:

# Chuuya memilih antara 1 atau 2. Jika Chuuya memilih 2, maka Akutagawa bisa memilih antara 1 dan 5. Jika Akutagawa memilih 5, maka Chuuya hanya mendapatkan angka 1 di akhir. Total skor Chuuya = 1 + 2 = 3, sedangkan Akutagawa = 5. Karena skor Chuuya lebih kecil, maka hasilnya adalah False.

# Input Format

# Array of Integer

# Constraints

# 1 <= array.length <= 20

# 0 <= array[i] <= 107

# Output Format

# Boolean

# Sample Input 0

# 1 5 2
# Sample Output 0

# False
# Explanation 0

# Chuuya memilih antara 1 atau 2. Jika Chuuya memilih 2, maka Akutagawa bisa memilih antara 1 dan 5. Jika Akutagawa memilih 5, maka Chuuya hanya mendapatkan angka 1 di akhir. Total skor Chuuya = 1 + 2 = 3, sedangkan Akutagawa = 5. Karena skor Chuuya lebih kecil, maka hasilnya adalah False.

# Sample Input 1

# 1 5 233 7
# Sample Output 1

# True
# Explanation 1

# Chuuya memilih 1. Akutagawa memilih antara 5 atau 7. Apapun pilihan Akutagawa, Chuuya akan bisa memilih 233. Total skor Chuuya menjadi lebih besar, sehingga hasilnya True.

def DazaiPredictor(arr):
    def ChuuyaVsAkutagawa(arr):
        def Helper(arr, i, j, memo):
            if i > j:
                return 0
            if memo[i][j] != 0:
                return memo[i][j]
            start = arr[i] + min(Helper(arr, i+2, j, memo), Helper(arr, i+1, j-1, memo))
            end = arr[j] + min(Helper(arr, i+1, j-1, memo), Helper(arr, i, j-2, memo))
            memo[i][j] = max(start, end)
            return memo[i][j]
        
        memo = [[0 for i in range(len(arr))] for j in range(len(arr))]
        return Helper(arr, 0, len(arr)-1, memo)
    
    chuuya = ChuuyaVsAkutagawa(arr)
    akutagawa = sum(arr) - chuuya
    return chuuya >= akutagawa

arr = list(map(int, input().split()))
print(DazaiPredictor(arr))

def DazaiPredictor(arr):
    n = len(arr)
    memo = [[-1] * n for _ in range(n)] # Menandai yang belum dihitung

    def Helper(i, j):
        if i > j:
            return 0
        if memo[i][j] != -1:
            return memo[i][j]
        
        pilihanAwal = arr[i] + min(Helper(i+2, j), Helper(i+1, j-1))
        pilihanAkhir = arr[j] + min(Helper(i+1, j-1), Helper(i, j-2))
        
        memo[i][j] = max(pilihanAwal, pilihanAkhir)
        return memo[i][j]
    
    chuuya = Helper(0, n - 1)
    akutagawa = sum(arr) - chuuya
    return chuuya >= akutagawa

arr = list(map(int, input().split()))
print(DazaiPredictor(arr))