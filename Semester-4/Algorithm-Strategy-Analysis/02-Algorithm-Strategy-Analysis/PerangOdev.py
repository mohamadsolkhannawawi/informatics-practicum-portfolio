# Di tanah yang jauh di belantara Angkadia, dua kekuatan besar telah lama bertikai. Kaum Oddlings, pasukan pemberani yang kekuatannya berasal dari bilangan ganjil, bertempur dengan penuh semangat melawan kaum Evenly, prajurit tangguh yang kekuatannya terletak pada bilangan genap.

# Namun, kekacauan terjadi! Pasukan dari kedua kubu telah bercampur di medan perang tanpa bisa dikenali satu sama lain. Tidak hanya itu, beberapa prajurit ternyata adalah pengkhianat, membawa energi negatif yang dapat melemahkan kekuatan pasukannya sendiri!

# Tugasmu sebagai ahli strategi kerajaan adalah membagi pasukan yang bercampur ini, menghitung total kekuatan mereka, dan menentukan pemenang dari pertempuran besar ini!

# Jika satu kubu memiliki kekuatan lebih besar, maka mereka menang!
# Pasukan pemenang dan jumlah kekuatan akan diumumkan.
# Jika kekuatan kedua kubu sama, mereka akan berdamai dan menyatukan kekuatan mereka.
# Semua pasukan yang tersisa akan disatukan sebagai satu tentara baru yang tak terkalahkan!
# Jika kedua kubu kehilangan seluruh kekuatan mereka karena pengkhianat, maka mereka semua musnah!
# Kerajaan akan menyaksikan kehancuran total dari kedua belah pihak...
# Ketentuan Deklarasi (perhatikan case):

# "Evenly/Oddlings menang!"
# "Kedua pasukan damai!"
# "Kedua pasukan sudah musnah"
# Dilarang untuk membagi pasukan menggunakan for / loop sejenis!

# Input Format

# Baris pertama berisi bilangan bulat positif N (N≥1)yang merupakan estimasi banyak pasukan
# Baris kedua berisi N bilangan bulat yang merupakan representasi dari kekuatan kedua pasukan (A)
# Constraints

# Output Format

# Baris pertama string deklarasi pasukan yang menang
# Baris kedua barisan bilangan dari pasukan yang menang (bisa jadi kosong)
# Baris ketiga merupakan jumlah kekuatan pasukan yang menang (bisa jadi kosong)
# Sample Input 0

# 3
# 1 3 4
# Sample Output 0

# Kedua pasukan damai!
# 4 1 3
# 8
# Sample Input 1

# 5
# 2 -3 8 7 3
# Sample Output 1

# Evenly menang!
# 2 8
# 10
# Sample Input 2

# 6
# 2 -3 8 -7 3 -10
# Sample Output 2

# Kedua pasukan sudah musnah

def pisahkanPasukan(i, arr):
    if i == len(arr):
        return [], []
    genap, ganjil = pisahkanPasukan(i + 1, arr)
    if arr[i] % 2 == 0:
        return [arr[i]] + genap, ganjil
    else:
        return genap, [arr[i]] + ganjil

def hasilPerang(arr):
    genap, ganjil = pisahkanPasukan(0, arr)
    sumGenap, sumGanjil = sum(genap), sum(ganjil)
    
    if sumGenap <= 0 and sumGanjil <= 0:
        return "Kedua pasukan sudah musnah"
    elif sumGenap == sumGanjil:
        return "Kedua pasukan damai!\n" + " ".join(map(str, genap + ganjil)) + f"\n{sumGenap + sumGanjil}"
    elif sumGenap > sumGanjil:
        return "Evenly menang!\n" + " ".join(map(str, genap)) + f"\n{sumGenap}"
    else:
        return "Oddlings menang!\n" + " ".join(map(str, ganjil)) + f"\n{sumGanjil}"


n = int(input())
arr = list(map(int, input().split()))
print(hasilPerang(arr))