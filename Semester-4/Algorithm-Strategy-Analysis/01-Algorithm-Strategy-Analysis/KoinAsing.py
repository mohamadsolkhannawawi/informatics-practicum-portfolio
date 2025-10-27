# Pak Dengklek, seorang kolektor koin dari negeri Bebek, saat ini memiliki 8 buah koin di dompetnya. Di negeri Bebek terdapat 26 jenis koin yang dinyatakan dengan huruf A - Z. Setelah diperhatikan dengan seksama, ternyata semua koin Pak Dengklek sama jenisnya, kecuali satu buah koin.

# Sayangnya, Pak Dengklek terlalu tua untuk dapat membedakan koin-koin tersebut. Anda diberikan jenis-jenis dari kedelapan koin Pak Dengklek tersebut. Bantulah Pak Dengklek untuk mentukan koin mana yang jenisnya berbeda tersebut.

# Input Format

# Sebuah baris berisi 8 buah karakter A - Z, yang menyatakan jenis-jenis dari kedelapan koin Pak Dengklek. Koin-koin dinomori dari 1 sampai dengan 8 dari kiri ke kanan.

# Constraints

# 8 char

# Output Format

# Sebuah baris berisi nomor koin yang jenisnya berbeda tersebut.

# Sample Input 0

# AAABAAAA
# Sample Output 0

# 4
# Sample Input 1

# YXXXXXXX
# Sample Output 1

# 1

import time
def KoinAsing(coins):
    for i in range(len(coins)):
        if coins.count(coins[i]) == 1:
            return i + 1
    
coins = input()
print(KoinAsing(coins))
print(time.process_time())