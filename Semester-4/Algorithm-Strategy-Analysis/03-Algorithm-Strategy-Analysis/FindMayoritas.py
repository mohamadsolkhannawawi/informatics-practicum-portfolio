# Swain, penguasa kerajaan Noxus, berdiri di atas menaranya yang megah, mengawasi kerajaannya. Di bawah, jalanan dipenuhi berbagai macam penduduk Noxus — prajurit, pedagang, cendekiawan, dan para buangan. Dia tahu bahwa kekuatan berasal dari kendali, tetapi terlalu banyak dari satu golongan bisa menyebabkan pemberontakan. Jika satu kelompok menjadi terlalu dominan, mereka mungkin menantang kekuasaannya. "Kekuatan ada dalam jumlah," bisik mereka di kegelapan. Dari N penduduknya, dia memperkirakan bahwa suatu golongan yang mencapai populasi N/2 bisa menjadi ancaman.

# Memanggil para penasihat kepercayaannya, Swain memerintahkan analisis cepat. Menghitung satu per satu tidaklah efisien, dan waktu bukanlah kemewahan yang bisa dimilikinya. Sebagai gantinya, mereka menyusun strategi: divide and conquer. Sebagai salah satu penasihatnya, bantulah Swain mencari golongan mayoritas yang tinggal dalam kerajaan Noxus!

# Input Format

# Baris pertama berisi bilangan bulat N yang menunjukkan jumlah penduduk Noxus.
# Baris kedua berisi N bilangan bulat yang merepresentasikan golongan setiap penduduk yang berbeda-beda.
# Constraints


# 1 ≤ N ≤ 12
# 1 ≤ Ai ≤ 102
# Selesaikan menggunakan algoritma Divide and Conquer
# Output Format

# Sebuah bilangan bulat yang menunjukkan golongan penduduk Noxus yang menjadi mayoritas (mencapai populasi N/2). Jika tidak ada, kembalikan nilai -1.

# Sample Input 0

# 7
# 3 3 4 2 3 3 3
# Sample Output 0

# 3
# Sample Input 1

# 6
# 1 2 3 4 5 6
# Sample Output 1

# -1
# Contest ends in 2 days 9 hours 30 minutes 43 seconds
# Submissions: 8
# Max Score: 1
# Rate This Challenge:

    
# More
 
# 1
# ​
def count_frekuensi(arr, x):
    count = 0
    for i in arr:
        if i == x:
            count += 1
    return count

def find_mayoritas(arr):
    if len(arr) == 1:
        return arr[0]
    
    tengah = len(arr) // 2
    mayoritas_kiri = find_mayoritas(arr[:tengah])
    mayoritas_kanan = find_mayoritas(arr[tengah:])

    if mayoritas_kiri == mayoritas_kanan:
        return mayoritas_kiri
    
    frekuensi_kiri = count_frekuensi(arr, mayoritas_kiri)
    frekuensi_kanan = count_frekuensi(arr, mayoritas_kanan)
    return mayoritas_kiri if frekuensi_kiri > frekuensi_kanan else mayoritas_kanan

n = int(input().strip())
arr = list(map(int, input().strip().split()))
kandidat_mayoritas = find_mayoritas(arr)  
if count_frekuensi(arr, kandidat_mayoritas) > n // 2:
    print(kandidat_mayoritas)
else:
    print(-1)  



    