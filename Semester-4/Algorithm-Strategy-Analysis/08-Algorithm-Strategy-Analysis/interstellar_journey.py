"""
Interstellar Journey

Deskripsi
Caelus adalah seorang trailblazer yang sangat menyukai petualangan. Caelus dan rekan-rekannya berpetualang
antar planet menggunakan Astral Express, kereta canggih yang mampu berpindah tempat dengan sangat cepat
dengan menggunakan warp.
Untuk berpindah antar planet, diperlukan warp yang membutuhkan sumber daya. Setiap planet memiliki alat
warp masing-masing. Biaya untuk melakukan warp di planet i adalah Ai

. Untuk melakukan perpindahan dari

planet i ke planet j adalah Ai + Aj .
Ternyata sudah ada planet yang memiliki relasi, sehingga untuk melakukan warp antar planet tersebut tidak
membutuhkan sumber daya apapun.
Caelus ingin melakukan perjalanan sebanyak Q planet dengan urutan yang sudah ditentukan bersama kru
Astral Express. Bantulah Caelus untuk menentukan sumber daya minimum yang diperlukan untuk melakukan
perjalanan menuju semua planet secara berurutan!
Format Masukan
Baris pertama berisikan tiga buah bilangan N, M, Q 

1 ≤ N, Q ≤ 100, 0 ≤ M ≤
N(N−1)
2

yang masing-masing

menyatakan jumlah planet, jumlah relasi, dan jumlah urutan planet yang ingin dikunjungi.
Baris kedua berisikan N bilangan bulat Ai (1 ≤ Ai ≤ 100) yang menyatakan biaya yang diperlukan untuk
melakukan warp di planet i
M baris berikutnya untuk masing-masing barisnya berisikan 2 buah bilangan bulat Bi Ci (1 ≤ Bi

, Ci ≤ N, Bi ̸=

Ci) yang menyatakan bahwa Bi dan Ci memiliki relasi.
Baris terakhir berisikan Q bilangan bulat Di (1 ≤ Di ≤ N) yang menyatakan urutan planet yang ingin
dikunjungi Caelus. Caelus bisa saja mengunjungi suatu planet lebih dari satu kali.
Format Keluaran

Keluarkan sebuah bilangan bulat yang menyatakan sumber daya minimum yang diperlukan Caelus untuk menye-
lesaikan perjalanannya.

Contoh Masukan 1
10 6 5
15 4 7 6 9 8 7 10 12 15
1 5
2 7
5 4
5 9
6 8
6 10
1 9 3 7 10 6

Contoh Keluaran 1
36

Contoh Masukan 2
3 3 3
8 9 10
1 2
1 3
2 3
1 2 3

Contoh Keluaran 2
0

1

Penjelasan
Berikut ini adalah contoh ilustrasi dari graph

Berikut ini adalah urutan perjalanan yang dilakukan oleh Caelus beserta jumlah sumber daya yang diperlukan:
1. 1 → 9 = 0 (1 dan 9 terhubung melalui 1 → 5 → 9)
2. 9 → 3 = 6 + 7 = 13 (Melalui 9 → 5 → 4 → 3)
3. 3 → 7 = 7 + 4 = 11 (Melalui 3 → 2 → 7)
4. 7 → 10 = 4 + 8 = 12 (Melalui 7 → 2 → 6 → 10)
5. 10 → 6 = 0 (10 dan 6 terhubung secara langsung )
Jadi total sumber daya yang dibutuhkan oleh Caelus sebesar 13 + 11 + 12 = 36
Petunjuk
Untuk mempermudah pengerjaan, buatlah fungsi DFS yang menerima input dua buah planet. Dengan DFS,
bisa dilakukan pengecekan apakah dua buah planet tersebut terhubung atau tidak.
Jika dua buah planet tidak terhubung, maka lakukan DFS 2 kali, untuk masing-masing planet, cari planet mana
yang membutuhkan sumber daya paling kecil.
Sample Input 0

10 6 5
15 4 7 6 9 8 7 10 12 15
1 5
2 7
5 4
5 9
6 8
6 10
1 9 3 7 10 6
Sample Output 0

36
Sample Input 1

4 3 3
11 10 15 5
1 2
1 3
2 3
4 1 4
Sample Output 1

30
"""

def dfs(u, comp_id, adj, visited, component, costs):
    visited[u] = True
    component[u] = comp_id
    for v in adj[u]:
        if not visited[v]:
            dfs(v, comp_id, adj, visited, component, costs)

def find_min_cost_component(component, comp_id, costs):
    min_cost = float('inf')
    for i in range(len(component)):
        if component[i] == comp_id:
            min_cost = min(min_cost, costs[i])
    return min_cost

N, M, Q = map(int, input().split())
A = list(map(int, input().split()))

adj = [[] for _ in range(N)]
for _ in range(M):
    u, v = map(int, input().split())
    adj[u-1].append(v-1)
    adj[v-1].append(u-1)

visited = [False] * N
component = [-1] * N
comp_id = 0
min_cost_per_comp = dict()

for i in range(N):
    if not visited[i]:
        dfs(i, comp_id, adj, visited, component, A)
        min_cost_per_comp[comp_id] = min(A[j] for j in range(N) if component[j] == comp_id)
        comp_id += 1

D = list(map(int, input().split()))
D = [x-1 for x in D]  

total_cost = 0
for i in range(len(D) - 1):
    u, v = D[i], D[i+1]
    if component[u] != component[v]:
        total_cost += min_cost_per_comp[component[u]] + min_cost_per_comp[component[v]]

print(total_cost)