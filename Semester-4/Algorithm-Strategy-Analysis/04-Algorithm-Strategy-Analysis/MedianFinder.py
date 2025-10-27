# Soal: Median Finder
# Diberikan sebuah array yang berisi N angka yang tidak terurut, tugas Anda adalah untuk
# mencari median dari array tersebut.
# Definisi Median:
# • Jika jumlah elemen adalah ganjil, maka median adalah elemen yang terletak di posisi
# tengah dalam array setelah disortir.
# • Jika jumlah elemen adalah genap, maka median adalah rata-rata dari dua elemen
# tengah.
# Input:
# • Baris pertama berisi angka N (1 ≤ N ≤ 10^5), jumlah elemen dalam array.
# • Baris kedua berisi N angka yang masing-masing berada di dalam rentang (1 ≤ arr[i] ≤
# 10^6), yaitu elemen-elemen dari array.
# Output:
# • Jika N adalah ganjil, outputkan elemen yang terletak di posisi tengah setelah disortir.
# • Jika N adalah genap, outputkan nilai elemen tengah paling kiri setelah disortir.
# Contoh:
# Input 1:
# 6
# 4 3 1 5 6 2
# Output 1:
# 3
# Input 2:
# 8
# 12 3 5 7 19 4 1 10
# Output 2:
# 5

def partisi(arr, bawah, atas):
    pivot = arr[bawah]  
    kiri = bawah + 1
    kanan = atas

    while True:
        while kiri <= kanan and arr[kiri] <= pivot:
            kiri += 1
        while kiri <= kanan and arr[kanan] > pivot:
            kanan -= 1
        if kiri <= kanan:
            arr[kiri], arr[kanan] = arr[kanan], arr[kiri]
        else:
            break

    arr[bawah], arr[kanan] = arr[kanan], arr[bawah] 
    return kanan  

def quickSort(arr, bawah, atas, k):
    if bawah <= atas:
        pivotIndex = partisi(arr, bawah, atas)

        if pivotIndex == k:  
            return arr[pivotIndex]  
        elif pivotIndex > k:  
            return quickSort(arr, bawah, pivotIndex - 1, k)  
        else:  
            return quickSort(arr, pivotIndex + 1, atas, k)  
    return None

def findMedian(n, arr):
    medianIndex = (n - 1) // 2 
    return quickSort(arr, 0, n - 1, medianIndex)


n = int(input().strip())
arr = list(map(int, input().strip().split()))
print(findMedian(n, arr))
 