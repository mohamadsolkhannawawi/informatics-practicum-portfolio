def merge_sort(data):
    if len(data) <=1:
        return data, 0 #sebagai penanda jumlah error
    tengah = len(data)//2
    kiri, invers_kiri = merge_sort(data[:tengah])
    kanan, invers_kanan = merge_sort(data[tengah:])
    hasil, invers_merge = merge(kiri, kanan)
    
    return hasil, invers_kiri + invers_kanan + invers_merge
    

def merge(kiri, kanan):
    i = 0
    j = 0
    count_invers = 0
    hasil = []
    
    while i < len(kiri) and j < len(kanan): 
        if kiri[i][0] <= kanan[j][0]: #bandingkan nilai kenakalannya
            hasil.append(kiri[i])
            i = i + 1
        else:
            hasil.append(kanan[j])
            count_invers = count_invers + len(kiri) - i # salah, karena semua elemen dikiri bakal lebih besar
            j = j + 1
            
    hasil.extend(kiri[i:])
    hasil.extend(kanan[j:])
    return hasil, count_invers #hasil gabungan

N = int(input())
arr = list(map(int, input().split()))
data = [(arr[i], i) for i in range(N)]
_, count_error = merge_sort(data)
print(count_error)