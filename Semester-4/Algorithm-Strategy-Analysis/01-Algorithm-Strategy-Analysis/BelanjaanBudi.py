# Budi disuruh ibunya ke toko kelontong dengan uang sebanyak X untuk membeli telur. Toko tersebut menjual karton telur, masing-masing berisi jumlah telur yang berbeda. Karena Budi hanya memiliki dua tangan maka dia hanya dapat membeli dua karton. Dia harus menemukan tepat dua karton yang berisi X telur.

# Tuliskan fungsi untuk membantu Budi menemukan pasangan karton yang tepat. Dijamin terdapat hanya sepasang karton yang mengandung jumlah telur X.

# Input Format

# Baris pertama berisi bilangan bulat X yang mewakili jumlah telur yang dibutuhkan Budi.
# Baris kedua berisi bilangan bulat N yang mewakili jumlah karton telur yang tersedia di toko.
# Baris ketiga berisi elemen-elemen array A berupa N bilangan bulat yang mewakili jumlah telur di setiap karton.
# Constraints

# 1 ≤ X ≤ 10⁴
# 2 ≤ N ≤ 10³
# 1 ≤ Ai ≤ 10⁴
# Dijamin terdapat tepat sepasang bilangan bulat dalam A yang jumlahnya X.
# Output Format

# Dua bilangan bulat yang mewakili index karton yang dipilih. Kembalikan pasangan dalam urutan ascending.

# Sample Input 0

# 10
# 5
# 1 7 4 8 6
# Sample Output 0

# 2 4
# Explanation 0

# Karton di index 2 (4 telur) dan index 4 (6 telur) dijumlahkan menjadi 10.

# Sample Input 1

# 5
# 2
# 2 3
# Sample Output 1

# 0 1
# Explanation 1

# Karton di index 0 (2 telur) dan index 1 (3 telur) dijumlahkan menjadi 5.

def BelanjaanBudi(X, N, A):
    for i in range(N):
        for j in range(i+1, N):
            if A[i] + A[j] == X:
                return f"{i} {j}"

X = int(input())
N = int(input())
A = [int (x) for x in input().split()]
print(BelanjaanBudi(X, N, A))
            