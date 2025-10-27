# Budi kecil baru saja mendapatkan mainan baru berupa sekumpulan karakter magnetik yang bisa ditempelkan di pintu kulkas. Setiap karakter dalam mainan ini memiliki bentuk huruf tertentu, dan Budi bisa menyusunnya menjadi kata-kata. Ayahnya memberikan tantangan Budi harus menyusun sebuah kata tersembunyi menggunakan karakter yang tersedia. Ayah Budi juga merupakan seseorang yang teliti jadi Budi diminta untuk tetap memberikan kata yang bisa terbentuk walau tidak sepenuhnya dari kata yang diberikan.

# Tantangan ini tidak hanya tentang menyusun huruf, tetapi juga tentang memastikan bahwa setiap huruf yang dibutuhkan untuk membentuk kata tersebut tersedia dalam kumpulan karakter yang dimiliki Budi. Jika semua huruf yang dibutuhkan ada, maka Budi bisa menyusun kata tersebut. Namun, jika ada huruf yang kurang, maka Budi tidak bisa menyelesaikan tantangan tersebut.

# Bantu Budi untuk menentukan apakah kata tersebut bisa disusun atau tidak, dan kata yang bisa tersusun (bisa seadanya).

# Input Format

# Baris pertama berisi sebuah string (1 ≤ |s| ≤ 1000), yaitu kumpulan karakter magnet yang tersedia.

# Baris kedua berisi deretan bilangan bulat yang dipisahkan oleh spasi, merepresentasikan kata yang harus disusun. Panjang daftar ini minimal 1 dan maksimal 100. (word)

# Constraints

# String hanya berisi karakter alfabet huruf besar ('A'-'Z') dan huruf kecil ('a'-'z').
# Panjang word minimal 1 dan maksimal 100.
# Perbandingan huruf bersifat case-sensitive ('a' berbeda dengan 'A').
# Output Format

# Pada baris pertama cetak "Bisa" atau "Tidak"

# Pada baris kedua cetak kata yang bisa tersusun (bisa kosong atau seadanya). Yang dimaksud seadanya adalah substring terpanjang yang dapat dibentuk dari karakter pertama.

# Sample Input 0

# hlelo
# 104 101 108 108 111
# Sample Output 0

# Bisa
# hello
# Sample Input 1

# dog
# 99 97 116
# Sample Output 1

# Tidak
# Sample Input 2

# fafafufucu
# 102 117 102 117 102 97 102 97 99 97
# Sample Output 2

# Tidak
# fufufafac

def bisa_menyusun_kata(magnets, word_codes):
    # Konversi kode ASCII ke karakter
    target_word = ''.join(chr(code) for code in word_codes)
    
    # Hitung frekuensi karakter pada magnet yang tersedia
    magnet_count = {}
    for char in magnets:
        magnet_count[char] = magnet_count.get(char, 0) + 1
    
    # Hitung frekuensi karakter dalam target word
    target_count = {}
    for char in target_word:
        target_count[char] = target_count.get(char, 0) + 1
    
    # Cek apakah semua huruf dalam target_word tersedia dalam jumlah yang cukup
    bisa_disusun = True
    for char in target_word:
        if target_count[char] > magnet_count.get(char, 0):
            bisa_disusun = False
            break
    
    if bisa_disusun:
        print("Bisa")
        print(target_word)
    else:
        print("Tidak")
        # Bentuk kata seadanya berdasarkan karakter yang tersedia
        constructed_word = ''
        for char in target_word:
            if magnet_count.get(char, 0) > 0:
                constructed_word += char
                magnet_count[char] -= 1
        print(constructed_word)

# Input
magnets = input().strip()
word_codes = list(map(int, input().split()))

# Output
bisa_menyusun_kata(magnets, word_codes)


def TantanganKata(string, ascii):
    targetKata = ''.join(chr(i) for i in ascii)
    stringCount = {}
    for char in string:
        stringCount[char] = stringCount.get(char, 0) + 1
    targetCount = {}
    for char in targetKata:
        targetCount[char] = targetCount.get(char, 0) + 1
    bisaDisusun = True
    for char in targetKata:
        if targetCount[char] > stringCount.get(char, 0):
            bisaDisusun = False
            break
    if bisaDisusun:
        print("Bisa")
        print(targetKata)
    else:
        print("Tidak")
        kataTerbentuk = []
        for char in targetKata:
            if stringCount.get(char, 0) > 0:
                kataTerbentuk.append(char)
                stringCount[char] -= 1
            else:
                break  
        print(''.join(kataTerbentuk))

string = input().strip()
ascii = list(map(int, input().split()))
TantanganKata(string, ascii)