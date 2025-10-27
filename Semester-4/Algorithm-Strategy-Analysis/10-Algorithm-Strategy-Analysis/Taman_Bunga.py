# Sebelum kematiannya, Anaxagoras memberikan tugas kepada Phainon. 
# Phainon ditugaskan untuk menanam bunga di taman bunga yang dibagi menjadi beberapa petak, 
# dengan syarat bunga tidak boleh ditanam secara bersebelahan. Kondisi taman bungan tersebut beragam, 
# seperti beberapa petak telah ditanami bunga, dan beberapa lainnya tidak ditanami.

# Taman bungan direpresentasikan dalam sebuah array, dengan nilai: 1, 
# yang artinya sudah ada bunga pada petak tersebut. 0, artinya petak kosong. 
# Serta sebuah angka n, dimana n adalah jumlah bunga baru yang akan ditanam. 
# Buatkan program yang akan menghasilkan true jika bunga berhasil ditanam semua, dan false jika gagal.

# Input Format

# array of integer (tanam bunga) n : interger (jumlah bungan yang akan ditanami)

# Output Format

# boolean

# Sample Input 0
# 1 0 0 0 1
# 1
# Sample Output 0
# true
# Explanation 0
# true, karena bisa ditanami 1 bunga tanpa bersebelahan

# Sample Input 1
# 1 0 0 0 1
# 2
# Sample Output 1
# false
# Explanation 1
# false, karena tidak bisa ditanami bunga tanpa ada bunga yang bersebelahan

def isCan_Place_Flower(flowerbed, n):
    length = len(flowerbed)
    count = 0

    for i in range(length):
        if flowerbed[i] == 0:
            empty_left = (i == 0) or (flowerbed[i - 1] == 0)
            empty_right = (i == length - 1) or (flowerbed[i + 1] == 0)
            if empty_left and empty_right:
                flowerbed[i] = 1
                count += 1
                if count >= n:
                    return True
    return count >= n

flowerbed_input = input()
flowerbed = list(map(int, flowerbed_input.strip().split()))
n = int(input())
result = isCan_Place_Flower(flowerbed, n)
print(str(result).lower())
