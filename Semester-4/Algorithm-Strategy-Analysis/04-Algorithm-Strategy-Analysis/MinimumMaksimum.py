def minMax(n, arr):
    min = arr[0]
    max = arr[0]
    for i in range(1, n):
        if arr[i] < min:
            min = arr[i]
        if arr[i] > max:
            max = arr[i]
    return min, max

n = int(input().strip())
arr = list(map(int, input().strip().split()))
minValue, maxValue = minMax(n, arr)
print(minValue, maxValue)