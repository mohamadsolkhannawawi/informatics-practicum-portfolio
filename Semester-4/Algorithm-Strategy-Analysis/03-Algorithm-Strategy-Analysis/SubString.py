# Sebuah Substring dikatakan Baik jika di dalam suatu String s, untuk setiap huruf alfabet yang mengandung s, muncul dalam huruf besar dan kecil. Misalnya, "abABB" disebut SubString karena 'A' dan 'a' muncul, dan 'B' dan 'b' muncul. Namun, "abA" bukan karena 'b' muncul, tetapi 'B' tidak.

# Diberikan string s, kembalikan substring terpanjang dari s yang bagus. Jika ada beberapa, kembalikan substring dari kemunculan paling awal. Jika tidak ada, kembalikan string kosong.

# Input Format

# Sebuah String s

# Constraints

# 1 <= s.length <= 100

# Output Format

# Sebuah string yang substring terpanjang, jika tidak ada keluarkan string kosong ""

# Sample Input 0

# YazaAay
# Sample Output 0

# aAa
# Explanation 0

# aAa adalah substring yang baik, karena 'a/A' adalah satu-satunya huruf dalam rangkaian substring dimana huruf a non kapital dengan huruf A kapital muncul.

# Sample Input 1

# Bb
# Sample Output 1

# Bb
# Explanation 1

# Bb adalah substring yang baik karena huruf 'b' dan 'B' muncul.

# Fungsi untuk menghasilkan daftar karakter unik tanpa menggunakan set
def char_unik(s):
    unik = []  # Inisialisasi list kosong untuk menyimpan karakter unik
    for ch in s:  # Iterasi setiap karakter dalam string
        if ch not in unik:  # Jika karakter belum ada dalam list unik
            unik.append(ch)  # Tambahkan karakter ke dalam list unik
    return unik  # Kembalikan list karakter unik

# Fungsi untuk memeriksa apakah substring merupakan substring "baik"
def is_good(sub):
    # Mendapatkan karakter unik dari substring dalam huruf kecil
    unique_chars = char_unik(sub.lower())
    for ch in unique_chars:  # Iterasi setiap karakter unik
        # Periksa apakah huruf kecil dan kapital dari karakter tersebut ada di substring
        if ch.lower() not in sub or ch.upper() not in sub:
            return False  # Jika salah satu tidak ada, substring tidak "baik"
    return True  # Jika semua karakter memiliki pasangannya, substring adalah "baik"

# Fungsi untuk mencari substring "baik" terpanjang
def longest_good_substring(s):
    max_len = 0  # Variabel untuk menyimpan panjang maksimum substring "baik"
    result = ""  # Variabel untuk menyimpan substring "baik" terpanjang
    n = len(s)  # Menyimpan panjang string s

    # Iterasi untuk memulai substring dari indeks i
    for i in range(n):
        # Iterasi untuk mengakhiri substring di indeks j
        for j in range(i + 1, n + 1):
            sub = s[i:j]  # Ambil substring dari indeks i ke j (tidak termasuk j)
            # Jika substring "baik" dan panjangnya lebih dari max_len yang sebelumnya
            if is_good(sub) and len(sub) > max_len:
                max_len = len(sub)  # Perbarui panjang maksimum substring "baik"
                result = sub  # Simpan substring sebagai hasil terbaik saat ini

    return result  # Kembalikan substring "baik" terpanjang

# Menerima input string dari pengguna
s = input()

# Cetak hasil substring "baik" terpanjang yang ditemukan
print(longest_good_substring(s))

def char_unik(string):
    unik = []
    for karakter in string:
        if karakter not in unik:
            unik.append(karakter)
    return unik
    
def verifikasi_substring(sub):
    karakter_unik = char_unik(sub.lower())
    for karakter in karakter_unik:
        if karakter.lower() not in sub or karakter.upper() not in sub:
            return False
        
    return True

def substring_terpanjang(string):
    panjang_maks = 0
    hasil = ""
    panjang_string = len(string)

    for i in range(panjang_string):
        for j in range(i + 1, panjang_string + 1):
            sub = string[i:j]
            if verifikasi_substring(sub) and len(sub) > panjang_maks:
                panjang_maks = len(sub)
                hasil = sub
    return hasil

string = str(input())
print(substring_terpanjang(string))


