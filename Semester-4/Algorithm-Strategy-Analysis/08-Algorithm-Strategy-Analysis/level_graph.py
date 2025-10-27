"""
Diberikan sebuah graph tak berarah dan tak berbobot dengan 5 simpul, dinomori 1 sampai 5, dan beberapa sisi. Mulai dari simpul 1, cari level (jarak dalam jumlah sisi) ke setiap simpul lain menggunakan BFS. Tulis urutan kunjungan BFS dan tentukan jarak (level) dari simpul 1 ke setiap simpul.

Input Format

5 [[1,2], [2,3], [1,4], [4,5]] 1

Constraints

-

Output Format

Urutan BFS: 1, 2, 4, 3, 5 Level: simpul 1: 0 simpul 2: 1 simpul 4: 1 simpul 3: 2 simpul 5: 2

Sample Input 0

4
[[1,2], [1,3], [2,4]]  
1
Sample Output 0

Urutan BFS: 1, 2, 3, 4
Level:
simpul 1: 0
simpul 2: 1
simpul 3: 1
simpul 4: 2
Sample Input 1

6
[[1,2], [2,3], [2,4], [1,5], [5,6]]  
2
Sample Output 1

Urutan BFS: 2, 1, 3, 4, 5, 6
Level:
simpul 2: 0
simpul 1: 1
simpul 3: 1
simpul 4: 1
simpul 5: 2
simpul 6: 3
"""

from collections import deque

def bfs(n, edges, start):
    graph = {i: [] for i in range(1, n+1)}  
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)  

    visited = set()
    level = {start: 0}
    queue = deque([start])
    bfs_order = []

    while queue:
        vertex = queue.popleft()
        if vertex not in visited:
            visited.add(vertex)
            bfs_order.append(vertex)
            for neighbor in sorted(graph[vertex]): 
                if neighbor not in visited and neighbor not in queue:
                    queue.append(neighbor)
                    level[neighbor] = level[vertex] + 1

    print("Urutan BFS:", ', '.join(map(str, bfs_order)))
    print("Level:")
    
    for vertex in bfs_order:
        if vertex in level:
            print(f"simpul {vertex}: {level[vertex]}")
        else:
            print(f"simpul {vertex}: tidak terjangkau")

n = int(input()) 
edges = eval(input())  
start = int(input()) 
bfs(n, edges, start)