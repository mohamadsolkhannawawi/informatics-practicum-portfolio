# # Bu Ronan mempunyai kost-kostan elit yang bisa muat ribuan bahkan tak hingga orang di dalamnya. Saking banyaknya ruangan kost-kostan yang dimiliki Bu Ronan sampai saat ini beliau kebingungan dalam mengalokasikan sistem kebersihan dan juga sistem penagihan tiap bulannya. Akhirnya anak Bu Ronan menciptakan sistem manajemen untuk kost-kostan yang dimiliki Bu Ronan, yang awalnya tidak ber-id sekarang memiliki id unik yang mampu memudahkan alokasi-alokasi yang ada. Ada pun bentuk kost-kostan Bu Ronan yang telah dirombak sebagai berikut:

# # image

# # Maka, id kostan adalah 1 A 1 2

# # Jika Bu Ronan menerima 10 orang penyewa Maka, id kostan adalah 1 A 1 2 B 3 5 8 C 13

# # note: gunakan deret fibonaci

# # Input Format

# # format input : Sebuah integer n (1 ≤ n ≤ 1000).

# # Constraints

# # constraint: -

# # Output Format

# # format output : array of string consist of numbers and alphabets

# # Sample Input 0

# # 1
# # Sample Output 0

# # 1
# # Sample Input 1

# # 2
# # Sample Output 1

# # 1 A

# def fibonacci_pyramid(n):
#     if n < 1:
#         return ""

#     # Inisialisasi deret Fibonacci
#     fib_sequence = [1, 1]
#     for _ in range(2, n * n):  # Menghasilkan angka Fibonacci secukupnya
#         fib_sequence.append(fib_sequence[-1] + fib_sequence[-2])

#     result = ["1"]  # Baris pertama selalu angka "1"
#     index = 0  # Indeks Fibonacci yang sedang digunakan

#     for row in range(2, n + 1):  # Loop dari baris kedua hingga baris ke-n
#         if row == 2:
#             result.append("A")  # Baris kedua hanya memiliki "A"
#         elif row == 3:
#             result.append("B")  # Baris ketiga diawali "B"
#         elif row == 4:
#             result.append("C")  # Baris keempat diawali "C"

#         for _ in range(row - 2):  # Mulai angka Fibonacci dari baris ke-3
#             if index < len(fib_sequence):
#                 result.append(str(fib_sequence[index]))
#                 index += 1

#     return " ".join(result)  # Gabungkan semua elemen dalam satu baris output

# # Input jumlah baris piramida
# n = int(input())
# print(fibonacci_pyramid(n))

# def kost_id(n):
#     if n < 1:
#         return ""

#     # Inisialisasi deret Fibonacci
#     fib = [1, 1]
#     while len(fib) < n:  # Menghasilkan angka Fibonacci yang cukup
#         fib.append(fib[-1] + fib[-2])

#     hasil = ["1"]  # ID pertama selalu "1"
#     index = 1  # Mulai dari elemen kedua Fibonacci
#     huruf = 'A'  # Huruf pemisah pertama

#     for i in range(2, n + 1):  # Iterasi dari baris ke-2 hingga ke-n
#         hasil.append(huruf)  # Tambahkan huruf pemisah
#         huruf = chr(ord(huruf) + 1)  # Update ke huruf berikutnya

#         if i > 2:  # Hanya mulai menambahkan angka Fibonacci dari baris ke-3
#             for _ in range(i - 2):  # Tambahkan angka Fibonacci yang sesuai
#                 if index < n:
#                     hasil.append(str(fib[index]))
#                     index += 1

#     return " ".join(hasil)

# # Input jumlah penyewa
# n = int(input())
# print(kost_id(n))


# def InfinityKos(n):
#     if n < 0:
#         return ""
#     deretFibonacci = [1, 1]
#     while len(deretFibonacci) < n:
#         deretFibonacci.append(deretFibonacci[-1] + deretFibonacci[-2])

#     hasil = ["1"]
#     index = 1
#     huruf = 'A'

#     for i in range(2, n + 1):
#         hasil.append(huruf)
#         huruf = chr(ord(huruf) + 1)

#         if i > 2:
#             for _ in range(i - 2):
#                 if index < n:
#                     hasil.append(str(deretFibonacci[index]))
#                     index += 1
        
#     return " ".join(hasil)

# n = int(input())
# print(InfinityKos(n))

def InfinityKos(n):
    if n < 1:
        return ""

    deretFibonacci = [1, 1]
    while len(deretFibonacci) < n:
        deretFibonacci.append(deretFibonacci[-1] + deretFibonacci[-2])

    hasil = []
    huruf = 'A'  
    fibIndex = 0 
    posHuruf = [2]  
    nextGap = 3  

    while posHuruf[-1] < n:
        posHuruf.append(posHuruf[-1] + nextGap)
        nextGap += 1

    for i in range(1, n + 1):
        if i in posHuruf:
            hasil.append(huruf)
            huruf = chr(ord(huruf) + 1)
        else:
            hasil.append(str(deretFibonacci[fibIndex]))
            fibIndex += 1

    return " ".join(hasil)

n = int(input().strip())
print(InfinityKos(n))




