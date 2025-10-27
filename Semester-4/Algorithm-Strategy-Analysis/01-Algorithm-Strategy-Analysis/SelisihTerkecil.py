# Kamu memiliki sebuah daftar nilai yang berupa angka. Carilah hasil selisih terkecil dari dua angka dalam daftar.

# Contoh: Input: [10, 5, 12, 7, 15]

# Output: 2

# Input Format

# array of integer

# Output Format

# integer

# Sample Input 0

# 10 5 12 7 15
# Sample Output 0

# 2
# Sample Input 1

# 1 5 9 3
# Sample Output 1

# 2

def SelisihTerkecil(arr):
    min = abs(arr[1] - arr[0])
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            if abs(arr[j] - arr[i]) < min:
                min = abs(arr[j] - arr[i])
    return min

arr = [int(x) for x in input().split()]
print(SelisihTerkecil(arr)) 