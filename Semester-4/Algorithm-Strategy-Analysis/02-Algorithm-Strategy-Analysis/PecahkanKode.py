# Di sebuah kampus teknologi, terdapat seorang mahasiswa bernama Syahla yang sangat tertarik dengan pemrograman. Suatu hari, ia mendapatkan tantangan dari dosennya untuk memecahkan sebuah kode rahasia yang tersembunyi dalam bentuk susunan angka.

# Kode tersebut terdiri dari sebuah barisan angka N, dan Syahla diminta untuk menghitung jumlah cara yang mungkin untuk menginterpretasikan barisan tersebut menjadi huruf-huruf alfabet. Aturan interpretasinya adalah:

# Angka '1' dapat diartikan sebagai huruf 'A' Angka '2' dapat diartikan sebagai huruf 'B' Dan seterusnya hingga angka '26' yang dapat diartikan sebagai huruf 'Z'

# Misalnya, jika barisan angkanya adalah "123", maka dapat diinterpretasikan sebagai:

# "1 2 3" (A B C) "12 3" (L C) "1 23" (A W)

# Sehingga terdapat 3 cara berbeda untuk menginterpretasikan "123".

# Namun, ada satu aturan tambahan: Angka '0' tidak dapat diinterpretasikan menjadi huruf apapun, tetapi dapat berpasangan dengan angka sebelumnya jika membentuk angka valid (10 hingga 26).

# Bantulah Syahla untuk memecahkan kode ini dengan menggunakan algoritma rekursi yang efisien!

# Input Format

# Baris pertama berisi sebuah string yang terdiri dari digit 0-9, merepresentasikan barisan angka N.

# Constraints

# 1 ≤ Panjang N ≤ 30
# N hanya terdiri dari digit 0-9
# N tidak dimulai dengan angka 0
# Output Format

# Sebuah bilangan bulat yang merepresentasikan jumlah cara yang mungkin untuk menginterpretasikan barisan angka N menjadi huruf-huruf alfabet.

# Sample Input 0

# 123
# Sample Output 0

# 3
# Sample Input 1

# 2020
# Sample Output 1

# 1
# Sample Input 2

# 27
# Sample Output 2

# 1

def PecahkanKode(N, memo={}):
    if N in memo:
        return memo[N]
    if not N or N[0] == '0':
        return 0
    if len(N) == 1:
        return 1
    if len(N) == 2:
        return 1 if N[0] == '0' or N[1] == '0' or int(N) > 26 else 2

    hasil = PecahkanKode(N[1:], memo)
    if 1 <= int(N[:2]) <= 26:
        hasil += PecahkanKode(N[2:], memo)

    memo[N] = hasil
    return hasil

N = input().strip()
print(PecahkanKode(N))