def findAngkaHilang(arr, n):
    if n not in arr: 
        return n
    return findAngkaHilang(arr, n - 1) 

def findAngkaTerbesar(n, arr):
    return findAngkaHilang(arr, n) 

n = int(input())
arr = list(map(int, input().split()))
print(findAngkaTerbesar(n, arr))
