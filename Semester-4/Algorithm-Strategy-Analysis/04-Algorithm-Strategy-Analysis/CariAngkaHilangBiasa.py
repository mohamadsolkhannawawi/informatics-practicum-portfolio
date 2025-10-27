def findMuridHilang(arr, kiri, kanan):
    if kiri >= kanan:
        return kiri
    
    tengah = (kiri + kanan) // 2
    if arr[tengah] == tengah:
        return findMuridHilang(arr, tengah + 1, kanan) 
    else:
        return findMuridHilang(arr, kiri, tengah)


N = int(input())
arr = list(map(int, input().split()))
print(findMuridHilang(arr, 0, N))


def findMuridHilang(arr, N):
    kiri, kanan = 0, N - 1  

    while kiri < kanan:
        tengah = (kiri + kanan) // 2
        if arr[tengah] == tengah:
            kiri = tengah + 1 
        else:
            kanan = tengah 
    return kiri  

N = int(input())
arr = list(map(int, input().split()))
print(findMuridHilang(arr, N))
