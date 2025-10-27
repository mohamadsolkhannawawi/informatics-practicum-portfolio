"""
Nama : Mohamad Solkhan Nawawi
NIM  : 24060123120020
Kelas: Sistem Cerdas C
Tugas: Implementasi BFS (Breadth First Search) pada Pohon
"""

# Membuat kelas Node untuk merepresentasikan simpul dalam pohon
class Node:
    # Konstruktor untuk inisialisasi nilai node dan daftar anak-anaknya
    def __init__(self, value, children=None):
        self.value = value                  # Menyimpan nilai dari node
        self.children = children or []      # Menyimpan daftar anak-anak node. Jika None, diinisialisasi sebagai list kosong.

# Fungsi untuk membuat objek Node
def make_node(value, children=None):
    return Node(value, children)            # Mengembalikan objek Node baru dengan nilai dan daftar anak yang diberikan

# Fungsi untuk enqueue atau menambahkan ke dalam antrian
def enqueue(queue, element):
    return queue + [element]               # Mengembalikan antrian dengan elemen baru ditambahkan di akhir

# Fungsi untuk dequeue atau mengeluarkan dari antrian
# Fungsi untuk mengambil dan menghapus elemen pertama dari antrian
def dequeue(queue):
    if not queue:
        # Jika antrian kosong, kembalikan None dan antrian kosong
        return None, []
    
    # Ambil elemen pertama dari antrian
    first_element = queue[0]
    # Buat antrian baru tanpa elemen pertama
    remaining_queue = queue[1:]
    
    # Kembalikan elemen pertama dan antrian yang tersisa
    return first_element, remaining_queue

# Fungsi untuk mencetak antrian saat ini
def print_queue(queue):
    # Ambil nilai dari setiap node di dalam antrian dan cetak sebagai daftar
    values = [node.value for node in queue]
    print("Current Queue:", values)

# Fungsi BFS untuk mencari node dengan nilai tertentu
def bfs(tree, goal):
    print("Starting BFS")
    # Fungsi rekursif untuk melakukan pencarian BFS
    def bfs_recursive(queue):
        # Jika antrian kosong, berarti goal tidak ditemukan
        if not queue:
            return "Goal not found \nFinished BFS!"
        
        # Cetak antrian saat ini
        print_queue(queue)
        
        # Ambil dan hapus node pertama dari antrian
        current, queue = dequeue(queue)      #current adalah node pertama dari antrian, queue adalah antrian tanpa node pertama
        print(f"Visiting Node: {current.value}")
        
        # Jika node saat ini adalah goal, kembalikan hasilnya
        if current.value == goal:
            return f"Goal '{goal}' found! \nFinished BFS!"
        
        # Tambahkan semua anak dari node saat ini ke antrian
        for child in current.children:
            queue = enqueue(queue, child)
        
        # Lanjutkan pencarian dengan antrian yang diperbarui
        return bfs_recursive(queue)

    # Mulai pencarian dengan node akar sebagai antrian awal
    return bfs_recursive([tree])


# Contoh struktur pohon pada PPT
# Struktur Pohon:
#        S
#      / | \
#     A  B  C
#    / \ |   \
#   D  E G    F
#  /
# H

# Membuat pohon dengan struktur yang diberikan
tree = make_node('S', [
    make_node('A', [
        make_node('D', [
            make_node('H')
        ]),
        make_node('E')
    ]),
    make_node('B', [
        make_node('G')
    ]),
    make_node('C', [
        make_node('F')
    ])
])

# Contoh pemanggilan BFS
print(bfs(tree, 'G'))