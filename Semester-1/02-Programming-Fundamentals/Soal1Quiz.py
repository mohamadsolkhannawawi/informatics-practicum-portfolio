#Nama File : Soal1Quiz.py
#Pembuat   : Julius Tegar Aji Putra - 24060123130117
#Tanggal   : 23 September 2023
#Deskripsi : Mencari median dari 3 nilai

# Definisi dan Spesifikasi
# max (a,b)  : 2 integer [int a != int b] -> integer
#   {max(a,b) mencari nilai maximum dari int a dan int b dengan cara
#   menambah a, b dan mutlak dari a - b lalu dibagi dengan 2, dengan syarat a != b}
# min (a,b)  : 2 integer [int a != int b] -> integer
#   {min(a,b) mencari nilai minimum dari int a dan int b dengan cara
#   menambah a dan b menguranginya dengan mutlak dari a-b lalu dibagi dengan 2, dengan syarat a != b}
# Median (a,b,c) : 3 integer [int a != int b != int c]-> integer
#   {Median(a,b,c) mencari median dengan cara menambahkan a, b dan c lalu dikurangi min(min(a,b),c) lalu
#   dikurangi lagi dengan max(max(a,b),c), dengan syarat a != b != c}

# Realisasi
def max(a,b):
    return(int(((a+b) + abs(a-b))/2))

def min(a,b):
    return(int(((a+b) - abs(a-b))/2))

def Median(a,b,c):
    return (a+b+c - (min(min(a,b),c))-(max(max(a,b),c)))

# Aplikasi 
print (Median(3,7,5))
print (Median(25,20,40))
