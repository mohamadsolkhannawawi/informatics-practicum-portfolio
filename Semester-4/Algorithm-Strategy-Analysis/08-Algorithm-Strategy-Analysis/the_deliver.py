"""
Janus telah membuat jalur antar kota yang direpresentasikan sebagai graf tak berarah dengan n kota (node), di mana setiap node diberi label dari 0 hingga n-1. Graf direpresentasikan dalam bentuk array 2 dimensi, di mana setiap elemen edge[i] = [ui, vi] menunjukkan egde dua arah antara node ui dan node vi. Setiap pasangan node hanya terhubung oleh maksimal satu edge, dan tidak ada node yang memiliki edge ke dirinya sendiri.

Phainon, salah satu Chrysos Heirs mengemban tugas untuk mengalahkan black tide di seluruh kota. Bantu Phainon untuk menentukan apakah terdapat path yang valid dari node awal ke node tujuan dengan algoritma BFS!!

Input Format

N = jumlah node

E = jumlah edge

List Egde

A, T = node awal, node tujuan

Constraints

-

Output Format

boolean (True False)

Sample Input 0

3
3
0 1
1 2
2 0
0 2
Sample Output 0

True
Explanation 0

Ada jalur dari node 0 ke 2
"""

from collections import deque

def bfs(n, edges, A, T):
    graph = {i: [] for i in range(n)}
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    
    visited = set() 
    queue = deque([A]) 
    visited.add(A)
    
    while queue:
        node = queue.popleft()
        if node == T:
            return True
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
    return False

n = int(input()) 
E = int(input())  
edges = [list(map(int, input().split())) for _ in range(E)] 
A, T = map(int, input().split())
result = bfs(n, edges, A, T)
print(result)
