"""
Dalam sebuah sistem galeri digital, gambar-gambar disusun dalam bentuk pohon biner. Setiap node dalam pohon mewakili sebuah gambar, dan nilai di node tersebut menunjukkan ukuran file gambar dalam megabyte (MB).

Sebagai kurator galeri, Anda diminta untuk menemukan ukuran gambar terbesar di setiap tingkat koleksi. Tingkat ke-0 adalah gambar root, tingkat ke-1 adalah anak-anak dari root, tingkat ke-2 adalah cucu-cucu, dan seterusnya.

Tugas kalian adalah menuliskan fungsi untuk mengembalikan sebuah list yang berisi ukuran gambar terbesar di setiap tingkat pohon, mulai dari tingkat 0.

Input Format

Baris pertama: Jumlah node n Baris kedua: List node dalam bentuk level order, dengan null untuk node kosong

Constraints

Jumlah node dalam pohon berada dalam rentang [0, 10^4]. -2^31 <= Node.value <= 2^31 - 1

Output Format

Sebuah list integer, di mana setiap angka adalah ukuran gambar terbesar pada tingkat pohon yang bersangkutan, dipisahkan oleh spasi.

Sample Input 0

1
5
Sample Output 0

5
Sample Input 1

7
1 3 2 5 3 null 9
Sample Output 1

1 3 9
"""

from collections import deque

def build_tree(nodes):
    if not nodes or nodes[0] == 'null':
        return None
    
    root = {'val': int(nodes[0]), 'left': None, 'right': None}
    queue = deque([root])
    
    i = 1
    while queue and i < len(nodes):
        current = queue.popleft()
        if i < len(nodes) and nodes[i] != 'null':
            current['left'] = {'val': int(nodes[i]), 'left': None, 'right': None}
            queue.append(current['left'])
        i += 1
        
        if i < len(nodes) and nodes[i] != 'null':
            current['right'] = {'val': int(nodes[i]), 'left': None, 'right': None}
            queue.append(current['right'])
        i += 1
    return root

def largest_values_per_level(root):
    if not root:
        return []
    
    result = []
    queue = deque([root])
    
    while queue:
        level_size = len(queue)
        max_val = float('-inf')
        for _ in range(level_size):
            node = queue.popleft()
            max_val = max(max_val, node['val'])
            if node['left']:
                queue.append(node['left'])
            if node['right']:
                queue.append(node['right'])
        result.append(max_val)
    return result

n = int(input())
nodes = input().split()
root = build_tree(nodes)
output = largest_values_per_level(root)
print(" ".join(map(str, output)))