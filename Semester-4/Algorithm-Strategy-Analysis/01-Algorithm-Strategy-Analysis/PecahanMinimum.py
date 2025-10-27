# Diberikan sejumlah nominal uang X dalam bentuk bilangan bulat positif. Anda memiliki pecahan uang dengan nilai [1, 5, 10, 25, 50]. Tentukan jumlah minimum lembar uang yang diperlukan untuk membentuk nilai X menggunakan pecahan tersebut.

# Input Format

# Satu baris berisi bilangan bulat X (1 <= X <= 1000), menyatakan jumlah uang yang harus dibentuk.

# Constraints

# 1 <= X <= 1000

# Output Format

# Cetak sebuah bilangan bulat yang menyatakan jumlah minimum lembar uang yang diperlukan untuk membentuk nilai X.

# Sample Input 0

# 37
# Sample Output 0

# 4
# Explanation 0

# 37 dapat dibentuk menggunakan: 25 + 10 + 1 + 1 (total 4 lembar).

# Sample Input 1

# 3
# Sample Output 1

# 3
# Explanation 1

# 3 dapat dibentuk menggunakan: 1 + 1 + 1 (total 3 lembar).

def PecahanMinimum(X):
    pecahan = [50, 25, 10, 5, 1]
    lembar = 0
    sisa = X
    
    for i in pecahan:
        lembar += sisa // i
        sisa = sisa % i
    return lembar
    
X = int(input())
print(PecahanMinimum(X))