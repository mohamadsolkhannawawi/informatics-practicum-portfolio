# Fibo bekerja sebagai kasir di Indomaret. Tapi ada twist-nya — Indomaret ini berada 
# di alam semesta lain! Di alam semesta ini, uang tunai hanya tersedia dalam bentuk 
# bilangan Fibonacci (jangan tanya kenapa).

# Terkadang, ada pelanggan yang datang tanpa membeli apa pun, tetapi tetap meminta 
# Fibo untuk menukarkan uang sejumlah N dolar. Fibo ingin memberikan uang kembalian 
# dengan jumlah lembar uang sesedikit mungkin.

# Mereka biasanya tidak mengeluh juga — toh mereka tidak membeli apa pun dari awal. 
# Fibo benar-benar butuh bantuanmu untuk mencari tahu jumlah lembar uang minimum yang 
# bisa diberikan.

# Input Format
# Sebuah bilangan bulat n di mana 2 ≤ n ≤ 2000.
# Constraints
# 2 ≤ n ≤ 2000
# Algoritma berupa pendekatan greedy.

# Output Format
# Sebuah bilangan bulat yang merupakan kembalian dengan jumlah lembar uang minimum.

# Sample Input 0
# 7
# Sample Output 0
# 2
# Explanation 0
# Jumlah angka fibonacci minimum adalah 2, 5 + 2 = 7.

# Sample Input 1
# 13
# Sample Output 1
# 1
# Explanation 1
# Jumlah angka fibonacci minimum adalah 1, 13 = 13.

def Generate_Fibonacci(n):
    fib = [1, 2]  
    while fib[-1] + fib[-2] <= n:
        fib.append(fib[-1] + fib[-2])
    return fib

def Max_Lembar(n):
    fib = Generate_Fibonacci(n)
    count = 0
    idx = len(fib) - 1
    
    while n > 0:
        if fib[idx] <= n:
            n -= fib[idx]
            count += 1
        else:
            idx -= 1
    return count

n = int(input())
print((Max_Lembar(n)))