"""
Faishal, seorang anak SMK, baru saja membuat kalkulator seadanya. Karena keterbatasan akses ke sumber daya, kalkulator itu cukup sederhana. Kalkulator itu hanya dapat menampung satu integer, dan hanya memiliki akses ke 3 operasi:

Menambah atau mengurangi dengan 1.
Mengalikan dengan 2.
Membagikan dengan 3n (n≥0).
Saat ini, kalkulator itu sedang menampung satu integer N. Faishal ingin menghapus memorinya agar bisa digunakan lagi lain kali. Tentukan jumlah minimum operasi yang dibutuhkan untuk mengkonversi N ke 0.

Input Format

Satu integer N.

Constraints

1≤N≤1000

Output Format

Satu integer berupa jumlah minimal operasi yang dibutuhkan untuk mengonversi N -> 0.

Sample Input 0

6
Sample Output 0

3
Explanation 0

6/3 = 2
2-1 = 1
1-1 = 0
Sample Input 1

14
Sample Output 1

4
Explanation 1

14*2 = 28
28-1 = 27
27/27 = 1
1-1 = 0
"""

from collections import deque

def min_operations(N):
    if N == 0:
        return 0

    queue = deque([(N, 0)])
    visited = set([N])

    while queue:
        current, operations = queue.popleft()
        divisor = 1
        while divisor <= current:
            if current % divisor == 0:
                result = current // divisor
                if result == 0:
                    return operations + 1
                if result not in visited:
                    visited.add(result)
                    queue.append((result, operations + 1))
            divisor *= 3
            if divisor > current:  
                break
                
        result = current * 2
        if result <= 10000 and result not in visited: 
            visited.add(result)
            queue.append((result, operations + 1))
            
        result = current - 1
        if result >= 0 and result not in visited:
            if result == 0:
                return operations + 1
            visited.add(result)
            queue.append((result, operations + 1))
            
        result = current + 1
        if result <= 10000 and result not in visited: 
            visited.add(result)
            queue.append((result, operations + 1))     
    return -1 

N = int(input())
result = min_operations(N)
print(result)