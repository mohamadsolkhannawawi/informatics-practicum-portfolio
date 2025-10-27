# Tuco adalah pemilik truk makanan yang jujur dan pekerja keras. 
# Dia bangga menyajikan taco terenak di daerahnya. Apa rahasianya? 
# Dia mencocokkan topping-nya secara berpasangan saat membuat taco, 
# yang katanya bisa menggandakan kepuasan pelanggannya!

# Sebuah topping diwakili dengan (, dan pasangannya dengan ). 
# Rahasia lain Tuco adalah bahwa topping ( harus diletakkan terlebih dahulu, 
# sebelum dipasangkan dengan ). Ketika seorang pelanggan memesan N jumlah topping, 
# Tuco bisa memikirkan semua kombinasi taco yang mungkin. 
# Bisakah kamu mengungkap rahasianya? Berapakah jumlah kombinasi yang mampu dibuat Tuco?

# Input Format

# Satu integer N.

# Constraints

# 1≤N≤20
# Gunakan algoritma backtracking.
# Output Format

# Satu integer berupa jumlah kombinasi yang mungkin terbentuk.

# Sample Input 0
# 2
# Sample Output 0
# 2
# Explanation 0
# "(())","()()"
# Ada 2 kombinasi.

# Sample Input 1
# 3
# Sample Output 1
# 5
# Explanation 1
# "((()))","(()())","(())()","()(())","()()()"
# Ada 5 kombinasi.

def Backtracking_Count_Combinations(open_count, close_count):
    if open_count == N and close_count == N:
        return 1

    total = 0
    if open_count < N:
        total += Backtracking_Count_Combinations(open_count + 1, close_count)

    if close_count < open_count:
        total += Backtracking_Count_Combinations(open_count, close_count + 1)

    return total

N = int(input())
print(Backtracking_Count_Combinations(0, 0))
