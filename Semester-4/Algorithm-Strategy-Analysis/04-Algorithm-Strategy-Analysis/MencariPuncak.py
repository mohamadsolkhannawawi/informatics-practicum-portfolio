# Kamu adalah seorang petualang ternama yang tengah memburu relic legendaris sebuah artefak langka yang dikabarkan mampu membangkitkan orang yang telah tiada 😯. Menurut desas-desus, relic itu tersembunyi di sebuah kuil kuno di puncak Gunung Ashenfang. Namun, gunung ini bukanlah tempat biasa. Ia diselimuti kabut tebal yang menyesatkan dan dipenuhi makhluk buas yang siap menerkam siapa saja yang nekat mendakinya.

# Pegunungan ini memiliki karakteristik unik yaitu terdiri dari satu punggungan yang terus menanjak hingga mencapai titik tertinggi, lalu menurun tanpa ada dua titik berdekatan yang memiliki ketinggian yang sama.

# Legenda setempat menyebutkan bahwa siapa pun yang berdiri di Singgasana Surga saat titik balik matahari akan dianugerahi kebijaksanaan luar biasa. Namun, waktu sangat terbatas—kamu hanya memiliki cukup sinar matahari untuk melakukan sejumlah pencarian secara logaritmik sebelum malam tiba dan kegelapan menelan segalanya.

# Kamu memiliki sebuah peta yang menunjukkan ketinggian di setiap titik sepanjang punggungan. Misinya jelas: temukan puncak tertinggi dan tentukan dengan tepat di mana letaknya sebelum waktu habis! (posisi index)

# Note: Index array dimulai dari 1

# Input Format

# Baris pertama berisi bilangan bulat positif merupakan n panjang/banyak titik punggungan
# Baris kedua berisi bilangan bulat positif berupa barisan array titik titik punggungan dengan panjang n
# Constraints

# Output Format

# Sebuah bilangan bulat positif yang menunjukkan index dari puncak pegunungan tersebut

# Sample Input 0

# 9
# 1 4 23 79 84 99 95 91 21
# Sample Output 0

# 6

def MencariPuncak(arr, kiri, kanan):
    if kiri == kanan:
        return kiri + 1
    
    tengah = (kiri + kanan) // 2
    if tengah > 0 and tengah < len(arr) - 1:
        if arr[tengah] > arr[tengah - 1] and arr[tengah] > arr[tengah + 1]:
            return tengah + 1
        elif arr[tengah] < arr[tengah + 1]:
            return MencariPuncak(arr, tengah + 1, kanan)
        else:
            return MencariPuncak(arr, kiri, tengah - 1)
        
    if tengah == 0:
        if arr[0] > arr[1]:
            return 1
        else:
            return 2
    
    if tengah == len(arr) - 1:
        if arr[len(arr) - 1] > arr[len(arr) - 2]:
            return len(arr)
        else:
            return len(arr) - 1
    
n = int(input())
arr = list(map(int, input().split()))
print(MencariPuncak(arr, 0, n - 1))
    