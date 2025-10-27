# Di zaman Mesir kuno, seorang Firaun bernama Khufra bermimpi untuk membangun piramida termegah yang pernah ada di dunia. Ia diberikan tepat N batu, masing-masing diketahui beratnya. Batu-batu ini menjadi fondasi utama dari bangunan megahnya. Demi menciptakan piramida terhebat, Khufra membuat aturan khusus: setiap batu yang ditempatkan di atas harus memiliki berat sama dengan jumlah dua batu yang berada tepat di bawahnya, memastikan setiap tingkat semakin berat dan kokoh.

# Kini, dengan tekad menciptakan piramida paling megah, Khufra harus cermat memilih penempatan batu tersebut agar kekuatannya maksimal demi memukau para dewa. Dia telah melantik anda sebagai penasihatnya untuk mengawasi pembangunan piramidanya itu. Dari fondasi piramida yang telah diberikan, bantulah Khufra menemukan penempatan batu di tingkat-tingkat selanjutnya menggunakan algoritma rekursif, jika anda menghargai nyawa anda!

# Input Format

# Baris pertama berisi bilangan bulat N yang menunjukkan jumlah batu yang menjadi fondasi piramida.
# Baris kedua berisi elemen-elemen array A berupa N bilangan bulat yang menunjukkan berat dari setiap batu.
# Constraints


# 1 ≤ N ≤ 10
# 1 ≤ Ai ≤ 103
# Output Format

# N baris berisi bilangan-bilangan bulat yang menunjukkan berat dari batu-batu yang menempati setiap tingkat piramida. Diawali dari puncak sampai ke fondasi piramida.

# Sample Input 0

# 5
# 1 2 3 4 5
# Sample Output 0

# 48
# 20 28
# 8 12 16
# 3 5 7 9 
# 1 2 3 4 5
# Explanation 0

# Di tingkat kedua piramida:
# 1 + 2 = 3
# 2 + 3 = 5
# 3 + 4 = 7
# 4 + 5 = 9


# Di tingkat ketiga piramida:
# 3 + 5 = 8
# 5 + 7 = 12
# 7 + 9 = 16


# Dan seterusnya.

# Sample Input 1

# 4
# 1 1000 1 1000
# Sample Output 1

# 4004
# 2002 2002
# 1001 1001 1001
# 1 1000 1 1000

def PiramidaFiraun(n, arr):
    def PenempatanBatu(arr):
        if len(arr) == 1:
            return [arr]
        else :
            newArr = [arr[i] + arr[i+1] for i in range(len(arr)-1)]
            return PenempatanBatu(newArr) + [arr]
    
    hasil = PenempatanBatu(arr)
    for baris in hasil:
        print(" ".join(map(str, baris)))

n = int(input())
arr = list(map(int, input().split()))
PiramidaFiraun(n, arr)
