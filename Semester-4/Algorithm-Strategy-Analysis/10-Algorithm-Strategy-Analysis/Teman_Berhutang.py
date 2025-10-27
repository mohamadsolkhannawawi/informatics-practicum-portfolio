# Sebuah kelompok terdiri dari n orang yang saling meminjamkan uang. 
# Setiap orang mungkin memiliki utang atau piutang terhadap orang lain 
# dalam kelompok tersebut. Tujuannya adalah menyelesaikan semua utang-piutang 
# dengan jumlah transaksi seminimal mungkin, sehingga tidak ada lagi 
# yang berhutang setelah proses ini.

# Input Format
# baris pertama adalah jumlah n dan baris kedua adalah list angka

# Constraints
# -
# Output Format
# List of Integer

# Sample Input 0
# 3
# [[0, 1000, 2000], [0, 0, 5000], [0, 0, 0]]
# Sample Output 0
# [[0, 0, 3000], [0, 0, 4000], [0, 0, 0]]

import sys
import ast

def Get_Jumlah_Bersih(graph):
    n = len(graph)
    jumlah_bersih = [0] * n
    for i in range(n):
        for j in range(n):
            jumlah_bersih[i] += graph[j][i] - graph[i][j]
    return jumlah_bersih

def Get_Max_Kreditur(jumlah_bersih):
    max_index = 0
    for i in range(1, len(jumlah_bersih)):
        if jumlah_bersih[i] > jumlah_bersih[max_index]:
            max_index = i
    return max_index

def Get_Max_Debitur(jumlah_bersih):
    min_index = 0
    for i in range(1, len(jumlah_bersih)):
        if jumlah_bersih[i] < jumlah_bersih[min_index]:
            min_index = i
    return min_index

def Pelunasan_Iteratif(jumlah_bersih, res):
    while True:
        mx_credit = Get_Max_Kreditur(jumlah_bersih)
        mx_debit = Get_Max_Debitur(jumlah_bersih)
        if jumlah_bersih[mx_credit] == 0 or jumlah_bersih[mx_debit] == 0:
            break
            
        amount = min(-jumlah_bersih[mx_debit], jumlah_bersih[mx_credit])
        if amount <= 0:
            break
            
        jumlah_bersih[mx_credit] -= amount
        jumlah_bersih[mx_debit] += amount
        res[mx_debit][mx_credit] += amount

def Min_Transaksi(graph):
    n = len(graph)
    jumlah_bersih = Get_Jumlah_Bersih(graph)
    result = [[0]*n for _ in range(n)]
    Pelunasan_Iteratif(jumlah_bersih, result)
    return result

lines = sys.stdin.read().strip().splitlines()
n = int(lines[0])
matrix = []
for i in range(1, n+1):
    row = list(map(int, lines[i].strip().split()))
    matrix.append(row)

result = Min_Transaksi(matrix)
for row in result:
    print(' '.join(map(str, row)))