# Mydei sangat menyukai buah delima, dia dapat menghabiskan banyak delima dalam sekejap. Mydei mencari cara agar dia dapat berhemat karena sudah akhir bulan, alhasil Mydei membagi delima ke dua kantong yang berbeda. Mydei memiliki N delima dengan berat masing-masing yang sudah diketahui. Lalu, delima akan dibagi menjadi dua kantong dengan ketentuan Mydei ingin berat kedua kantong memiliki selisih yang terkecil dengan banyak delima yang akan disimpan dalam kantong tidak penting. Buat program untuk mengeluarkan selisih terkecil dari kantong delima Mydeimos!

# Input Format

# n: integer {banyaknya delima} w1, w2, ..., w3: integer {berat masing-masing delima}

# Output Format

# integer

# Sample Input 0

# 4
# 1 2 3 4
# Sample Output 0

# 0
# Explanation 0

# dibagi menjadi 2 kantong: (2 + 3) dan (1 + 4) dengan masing-masing kantong beratnya 5, jadi selisihnya adalah

def cariSelisihTerkecil(delima, index=0, kantong1=0, kantong2=0):
    if index == len(delima):
        return abs(kantong1 - kantong2)  # Selisih dua kantong

    # Pilih masuk ke kantong pertama
    selisih1 = cariSelisihTerkecil(delima, index + 1, kantong1 + delima[index], kantong2)
    # Pilih masuk ke kantong kedua
    selisih2 = cariSelisihTerkecil(delima, index + 1, kantong1, kantong2 + delima[index])

    return min(selisih1, selisih2)
n = int(input())
delima = list(map(int, input().split()))
print(cariSelisihTerkecil(delima))