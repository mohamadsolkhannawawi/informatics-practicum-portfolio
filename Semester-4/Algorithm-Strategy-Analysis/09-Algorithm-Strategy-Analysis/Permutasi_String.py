# Diberikan sebuah string S, tugas Anda adalah mencetak semua permutasi unik 
# dari karakter dalam string tersebut dalam urutan leksikografis (berurutan secara alfabet).

# Permutasi adalah penyusunan ulang seluruh karakter dalam string. 
# Jika karakter ada yang berulang, hasil permutasi yang sama harus hanya dicetak sekali.

# Input Format

# Satu baris berisi sebuah string S yang hanya terdiri dari huruf kecil alfabet (a - z)

# Constraints

# Panjang string: 1 ≤ |S| ≤ 8

# Output Format
# Cetak semua permutasi unik dari S, satu per baris, dalam urutan leksikografis naik.

# Sample Input 0
# ab
# Sample Output 0
# ab
# ba

# Sample Input 1
# abc
# Sample Output 1
# abc
# acb
# bac
# bca
# cab
# cba

def Backtracking_Permutations():
    S = sorted(string)
    if len(current) == n:
        result.append(''.join(current))
        return
    
    for i in range(n):
        if used[i]:
            continue
        if i > 0 and S[i] == S[i - 1] and not used[i - 1]:
            continue

        used[i] = True
        current.append(S[i])
        Backtracking_Permutations()
        current.pop()
        used[i] = False

string = input(str())
n = len(string)
used = [False] * n
current = []
result = []
Backtracking_Permutations()
for p in result:
    print(p)