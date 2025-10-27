# Seorang analis sepak bola sedang meneliti performa seorang penyerang dalam sebuah liga. Setiap musim, data jumlah gol yang dicetak oleh pemain direpresentasikan sebagai sebuah bilangan N dalam bentuk biner dengan panjang 32 bit.

# Setiap bit bernilai 1 menunjukkan bahwa pemain tersebut mencetak gol dalam pertandingan tertentu, sedangkan bit 0 menunjukkan bahwa pemain tidak mencetak gol.

# Analis ingin mengetahui berapa banyak pertandingan di mana pemain tersebut berhasil mencetak gol selama musim tersebut. Anda diminta untuk membantu menghitung jumlah pertandingan tersebut.

# # Sebagai contoh, jika data gol seorang pemain dalam satu musim direpresentasikan adalah 7 yang sebagai bilangan biner 00000000000000000000000000001011, itu berarti pemain tersebut mencetak gol dalam 3 pertandingan pada musim tersebut (karena ada tiga bit '1').

# # Input Format

# # Sebuah bilangan bulat tak bertanda N yang merepresentasikan statistik musim dalam format 32-bit.

# # Constraints

# # Output Format

# # Sebuah bilangan bulat yang menyatakan jumlah pertandingan di mana pemain mencetak gol (jumlah bit 1 dalam representasi biner dari N).

# # Sample Input 0

# # 7
# # Sample Output 0

# # 3
# # Sample Input 1

# # 9
# # Sample Output 1

# # 2

def konversi_ke_biner(N):
    binary_str = ''  # Inisialisasi string kosong untuk menyimpan hasil konversi biner
    
    # Buat daftar nilai bit dari 2^31 ke 2^0, untuk memastikan hasilnya 32-bit
    # Misalnya, [2^31, 2^30, ..., 2^1, 2^0]
    nilai_bit = [2 ** i for i in range(31, -1, -1)]
    
    # Iterasi melalui setiap nilai bit dari besar ke kecil
    for nilai in nilai_bit:
        if N >= nilai:  # Jika N masih lebih besar atau sama dengan nilai bit saat ini
            binary_str += '1'  # Tambahkan '1' ke string biner
            N -= nilai  # Kurangi N dengan nilai bit tersebut karena sudah terwakili oleh '1'
        else:
            binary_str += '0'  # Jika tidak, tambahkan '0' karena bit tersebut tidak aktif
    
    return binary_str  # Kembalikan string representasi biner 32-bit

def hitung_gol(binary_str):
    count = 0  # Inisialisasi penghitung untuk jumlah bit '1'
    
    # Iterasi setiap karakter dalam string biner
    for bit in binary_str:
        if bit == '1':  # Jika bit adalah '1', artinya ada gol di pertandingan tersebut
            count += 1  # Tambahkan 1 ke penghitung
    
    return count  # Kembalikan jumlah total bit '1' (jumlah gol)

# Input dari pengguna
N = int(input())  # Menerima input angka desimal dari pengguna

# Konversi angka ke representasi biner 32-bit
binary_representation = konversi_ke_biner(N)
print(f"Representasi Biner (32-bit): {binary_representation}")  # Cetak hasil konversi

# Hitung jumlah gol berdasarkan jumlah bit '1' di representasi biner
jumlah_gol = hitung_gol(binary_representation)
print(f"Jumlah Gol: {jumlah_gol}")  # Cetak jumlah gol



def konversi_string_biner(N):
    string_biner = ""
    nilai_bit = [2 ** i for i in range(31, -1, -1)]
    for nilai in nilai_bit:
        if N >= nilai:
            string_biner += '1'
            N -= nilai
        else:
            string_biner += '0'

    return string_biner

def hitung_gol(string_biner):
    count = 0
    for bit in string_biner:
        if bit == '1':
            count += 1

    return count

N = int(input())
string_biner = konversi_string_biner(N)
print(hitung_gol(string_biner))

