# Hal ini disebabkan semua orang (mahluk/entitas) di planet ini memiliki kromosom yang berbeda dan hanya para ahli yang bisa membedakannya. Tugas kalian adalah membantu para ahli untuk membedakan apakah bayi yang di check merupakan Cephalopod atau bukan. Hal ini nantinya akan digunakan untuk sistem cerdas mereka agar memudahkan pekerjaan para ahli nantinya. Menentukan Cephalopod atau bukan adalah dengan melihat banyaknya pasangan XY dalam kromosom yang diuji, jika dalam satu track kromosom terdapat XY berjumlah genap maka mereka terlahir sebagai Cephalopod. Sebagai tambahan, para ahli hanya ingin menggunakan algoritma rekursif.

# Contoh 1:

# input : ADXYADXYARYX

# output : True

# alasan : Karena terdapat 2 pasangan XY

# Contoh 2:

# input : ACADXDXY

# output : False

# alasan : Tidak terdapat pasangan XY dengan jumlah genap

# Input Format

# N string consist of alphabets, where 1 < N < 10^3

# Constraints

# -

# Output Format

# Boolean

# Sample Input 0

# A
# Sample Output 0

# False
# Sample Input 1

# AXAXY
# Sample Output 1

# False

def UjiKromosom(string, isTrue=True):
    if len(string) < 2:
        return isTrue
    elif string[:2] == 'XY':
        return not isTrue
        
    return UjiKromosom(string[1:], isTrue)
    
string = str(input())
print(UjiKromosom(string))

def HitungXY(string, count=0):
    if len(string) < 2:
        return count
    elif string[:2] == 'XY':
        return HitungXY(string[2:], count+1)
    return HitungXY(string[1:], count)

def UjiKromosom(string):
    return HitungXY(string) % 2 == 0

string = str(input())
print(UjiKromosom(string))