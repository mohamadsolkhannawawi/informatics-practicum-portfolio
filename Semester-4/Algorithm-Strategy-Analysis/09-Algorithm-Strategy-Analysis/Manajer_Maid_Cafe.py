# Sebagai manajer baru di sebuah maid cafe paling terkenal di Akihabara, 
# kamu bertanggung jawab untuk mengatur penugasan harian seluruh maid agar 
# pelayanan pelanggan tetap maksimal.

# Setiap hari, terdapat N maid dan N tugas penting yang harus dikerjakan, 
# mulai dari menyambut tamu, menyajikan parfait spesial, membersihkan meja VIP, 
# hingga membuat latte art berbentuk kucing.

# Setiap maid memiliki kemampuan dan kecepatan kerja yang berbeda untuk setiap tugas. 
# Kamu memiliki tabel yang menunjukkan waktu (dalam menit) yang dibutuhkan setiap maid 
# untuk menyelesaikan setiap tugas jika ditugaskan ke sana.

# Sebagai manajer yang efisien, kamu ingin menyusun penugasan satu maid untuk satu 
# tugas sehingga total waktu kerja seluruh tugas adalah yang paling minimum. 
# Gunakan algoritma Branch and Bound.

# Input Format

# Baris pertama berisi satu bilangan bulat N - jumlah maid dan jumlah tugas N baris berikutnya 
# masing-masing berisi N bilangan bulat, di mana elemen ke-j pada baris ke-i menyatakan waktu (dalam menit) 
# yang dibutuhkan maid ke-i untuk menyelesaikan tugas ke-j.
# Constraints
# 1 ≤ N ≤ 15 1 ≤ waktu ≤ 100
# Output Format
# Satu bilangan bulat — total waktu minimum untuk menyelesaikan seluruh tugas dengan penugasan terbaik.

# Sample Input 0
# 1
# 5
# Sample Output 0
# 5

# Sample Input 1
# 2
# 1 2
# 2 1
# Sample Output 1
# 2

import heapq

def BnB_Waktu_Minimal(cost_matrix):
    N = len(cost_matrix)
    min_task_time = [min(row) for row in cost_matrix]
    best_cost = float('inf')

    pq = []
    heapq.heappush(pq, (sum(min_task_time), 0, 0, frozenset()))

    while pq:
        bound, cost_so_far, maid, assigned = heapq.heappop(pq)
        if bound >= best_cost:
            continue
        if maid == N:
            if cost_so_far < best_cost:
                best_cost = cost_so_far
            continue
        for task in range(N):
            if task not in assigned:
                new_cost = cost_so_far + cost_matrix[maid][task]
                new_assigned = assigned | frozenset([task])
                est_bound = new_cost + sum(min_task_time[maid+1:])
                if est_bound < best_cost:
                    heapq.heappush(pq, (est_bound, new_cost, maid + 1, new_assigned))
    return best_cost

N = int(input())
cost_matrix = [list(map(int, input().split())) for _ in range(N)]
print(BnB_Waktu_Minimal(cost_matrix))
