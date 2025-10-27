# Pisi ingin mengucapkan dua kata (misal "pintu" dan "tua") dalam satu kalimat, tapi terlalu malas bicara panjang-panjang. Ia ingin menyatukan kedua string itu dalam satu kata terpendek yang tetap menyimpan keduanya sebagai substring (urutan huruf bersebelahan). Tugas kita: mencari panjang string terpendek yang bisa memuat keduanya sebagai substring.
# Format Masukan:
# Baris 1: String S
# Baris 2: String T
# Format Keluaran:
# Panjang minimal string yang mengandung S dan T sebagai substring
# Contoh:

# Input:
# pintu
# tua

# Output:
# 6

# Penjelasan: gabungan "pintua" mengandung "pintu" dan "tua" sebagai substring, panjang = 6


def gabung_kata(s, t):
    n = len(s)
    m = len(t)
    overlap = 0
    for i in range(1, min(n, m) + 1):
        if s[-i:] == t[:i]:
            overlap = i
    stringBeda = t[overlap:]
    hasil = s + stringBeda
    return len(hasil)

s = input().strip()
t = input().strip()
hasil = gabung_kata(s, t)
print(hasil)
