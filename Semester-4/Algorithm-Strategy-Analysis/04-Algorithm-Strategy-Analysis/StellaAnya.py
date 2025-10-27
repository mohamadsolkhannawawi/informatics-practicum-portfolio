def hitungInversi(arr, kiri, kanan):
    if kiri >= kanan:
        return 0 

    tengah = (kiri + kanan) // 2

    inversiKiri = hitungInversi(arr, kiri, tengah)
    inversiKanan = hitungInversi(arr, tengah + 1, kanan)
    return inversiKiri + inversiKanan + mergeAndCount(arr, kiri, tengah, kanan)

def mergeAndCount(arr, kiri, tengah, kanan):
    temp = []
    i, j = kiri, tengah + 1
    inversi = 0

    while i <= tengah and j <= kanan:
        if arr[i] <= arr[j]:
            temp.append(arr[i])
            i += 1
        else:
            temp.append(arr[j])
            inversi += (tengah - i + 1)  
            j += 1


    temp.extend(arr[i:tengah + 1])  
    temp.extend(arr[j:kanan + 1])   
    arr[kiri:kanan + 1] = temp
    return inversi

N = int(input())
arr = list(map(int, input().split()))
print(hitungInversi(arr, 0, N - 1))