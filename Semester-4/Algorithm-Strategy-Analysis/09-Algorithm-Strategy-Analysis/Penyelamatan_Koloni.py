# Koloni Mars membentuk jaringan kota-kota yang terhubung oleh terowongan satu arah. Setiap terowongan memiliki waktu tempuh tertentu.
# Tugasmu adalah membantu para insinyur menemukan waktu minimum untuk menyelamatkan semua penduduk dari kota awal menuju tempat perlindungan,
# yang terletak di kota terakhir.
# Gunakan algoritma Branch and Bound untuk meminimalkan total waktu perjalanan dari 
# kota 0 (awal) ke kota N-1 (tujuan akhir). Kamu tidak harus mengunjungi semua kota, namun jalur yang diambil tidak boleh memutar ke kota yang sama dua kali (tidak boleh ada siklus.

# Input Format

# Baris pertama berisi satu integer N, jumlah kota (0 sampai N-1).
# Diikuti oleh N baris, masing-masing berisi N integer, mewakili matriks graph[i][j] (waktu tempuh dari kota i ke kota j).
# Jika graph[i][j] = -1, maka tidak ada terowongan langsung dari kota i ke kota j.
# Constraints

# 2 ≤ N ≤ 15
# 0 ≤ graph[i][j] ≤ 10⁴ atau -1 jika tidak ada jalur
# graph[i][i] = -1 untuk semua i
# Output Format

# Cetak satu bilangan bulat: total waktu minimum dari kota 0 ke kota N-1.
# Jika tidak ada jalur yang memungkinkan, cetak -1

import heapq

def waktu_minimum_bnb(graph):
    N = len(graph)
    goal = N - 1

    # Priority queue: (total_cost, current_city, visited_set)
    pq = [(0, 0, frozenset([0]))]
    min_time = float('inf')

    while pq:
        cost, city, visited = heapq.heappop(pq)
        if city == goal:
            min_time = min(min_time, cost)
            continue
        for next_city in range(N):
            time = graph[city][next_city]
            if time != -1 and next_city not in visited:
                new_visited = visited | frozenset([next_city])
                heapq.heappush(pq, (cost + time, next_city, new_visited))

    return min_time if min_time != float('inf') else -1

N = int(input())
graph = []
for _ in range(N):
    graph.append(list(map(int, input().split())))
print(waktu_minimum_bnb(graph))
