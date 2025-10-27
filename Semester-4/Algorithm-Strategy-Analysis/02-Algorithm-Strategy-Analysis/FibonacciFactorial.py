# Diberikan sebuah array yang isinya berupa elemen angka, Anda diminta untuk menjumlahkan seluruh elemen array dengan dua pilihan.

# Pilihan 1: Fibonacci, yaitu Anda harus melakukan operasi fibonacci pada setiap elemen array, kemudian menjumlahkannya

# Pilihan 2: Factorial, yaitu Anda harus melakukan operasi factorial terlebih dahulu pada setiap elemen, kemudian menjumlahkannya

# Input Format

# Baris pertama merupakan banyaknya n elemen angka pada array
# Baris kedua adalah kumpulan angka k sebanyak n buah dalam array
# Baris ketiga adalah sebuah pilihan p yang direpresentasikan dalam angka

# Constraints

# 1 ≤ n ≤ 1000
# 0 ≤ k ≤ 10
# 1 ≤ p ≤ 2
# Output Format

# Sebuah bilangan bulat yang menyatakan jumlah seluruh angka dalam array setelah dilakukan operasi pilihan tertentu

# Sample Input 0

# 5
# 1 2 3 4 5
# 1
# Sample Output 0

# 12
# Explanation 0

# Pada input, pilihan (p) adalah 1 maka lakukan operasi fibonacci pada tiap elemen array. Sehingga jumlah semua elemen pada array: 1 + 1 + 2 + 3 + 5 = 12

# Sample Input 1

# 5
# 1 2 3 4 5
# 2
# Sample Output 1

# 153
# Explanation 1

# Pada input, pilihan (p) adalah 2 maka lakukan operasi factorial pada tiap elemen array. Sehingga jumlah semua elemen pada array: 1! + 2! + 3! + 4! + 5! = 153

def FibonacciFaktorial(n, arr, pilihan):
    def Fibonacci(n):
        if n <= 0:
            return 0
        elif n == 1:
            return 1
        else:
            return Fibonacci(n-1) + Fibonacci(n-2)
        
    def Faktorial(n):
        if n == 0:
            return 1
        else:
            return n * Faktorial(n-1)
    
    if pilihan == 1:
        return sum([Fibonacci(i) for i in arr])
    else:
        return sum([Faktorial(i) for i in arr])
    
n = int(input())
arr = list(map(int, input().split()))
pilihan = int(input())
print(FibonacciFaktorial(n, arr, pilihan))

