def partisi(arr, bawah, atas):
    pivot = arr[atas]  
    i = bawah - 1

    for j in range(bawah, atas):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[atas] = arr[atas], arr[i + 1]
    return i + 1  

def quickSort(arr, bawah, atas):
    if bawah < atas:
        pivotIndex = partisi(arr, bawah, atas)
        quickSort(arr, bawah, pivotIndex - 1)
        quickSort(arr, pivotIndex + 1, atas)

n = int(input().strip())
arr = list(map(int, input().strip().split()))
quickSort(arr, 0, n - 1)
print(" ".join(map(str, arr)))

