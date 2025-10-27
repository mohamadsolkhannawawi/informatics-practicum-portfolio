def fungsiMod(a, b, m):
    if a == 0:
        return 0
    if b == 0:
        return 1
    if m == 1:
        return 0

    temp = fungsiMod(a, b - 1, m) % m
    return pow(a, temp, m)

a, b, m = map(int, input().split())
print(fungsiMod(a, b, m))
