# Phainon diberi tugas oleh profesor Anaxagoras tentang bahasa Kremnos yang hilang. Tugas tersebut mengahruskan Phainon untuk membuktikan apakah dua string tersebut ekuivalen dengan panjang string yang pasti sama. Syarat dari dua string dianggap ekuivqlen adalah: 1. Jika panjang string ganjil, maka akan ekuivalen jika keduanya identik 2. Jika panjang string genap, dianggap ekuivalen jika memenuhi salah satu dari dua syarat: - Dua string tersebut identik - Jika string a dibagi dua menjadi a1 dan a2, dan string b dibagi menjadi b1 dan b. Maka salah satu dari dua pernyataan berikut harus terpenuhi 1. a1 ekuivalen dengan b1 dan a2 ekuivalen dengan b2 2. a1 ekuivalen dengan b2 dan a2 ekuivalen dengan b1

# Input Format

# input dua string yang dicoba Phainon dengan panjang yang pasti sama.

# Output Format

# output YA jika ekuivalen output TIDAK jika tidak ekuivalen

# Sample Input 0

# baaa
# aaab
# Sample Output 0

# YA
# Explanation 0

# String dibagi menjadi dua: 'baaa' menjadi 'ba' dan 'aa' 'aaab' menjadi 'aa' dan 'ab' 'ba' ekuivalen dengan 'ab', karena 'ba' = 'b' + 'a' dan 'ba' = 'a' + 'b' (hurufnya sama walau berbeda penempatan) 'aa' ekuivalen dengan 'aa' (syarat a1 ekuivalen dengan b2 dan a2 ekuivalen dengan b1)

# Sample Input 1

# bbab
# aabb
# Sample Output 1

# TIDAK

def isEkuivalen(string_1, string_2):
    if string_1 == string_2:
        return True # Identik
    if len(string_1) % 2 != 0:
        return False # Ganjil, tidak identik
    else:
        tengah = len(string_1) // 2
        string_1_kiri = string_1[:tengah]
        string_1_kanan = string_1[tengah:]
        string_2_kiri = string_2[:tengah]
        string_2_kanan = string_2[tengah:]
        return (isEkuivalen(string_1_kiri, string_2_kiri) and  isEkuivalen(string_1_kanan,string_2_kanan)) or (isEkuivalen(string_1_kiri, string_2_kanan) and isEkuivalen(string_1_kanan, string_2_kiri))
    
string_1 = input().strip()
string_2 = input().strip()
if isEkuivalen(string_1, string_2):
    print("YA")
else:
    print("TIDAK")


        