def is_anagram(s, t):
    if len(s) != len(t):
        return False
    return sorted(s) == sorted(t)

def gabung_kata(s, t):
    n = len(s)
    m = len(t)
    for i in range(min(n, m), 0, -1):
        if s[-i:] == t[:i]:
            return len(s) + len(t) - i
    return len(s) + len(t)
s = input().strip()
t = input().strip()
hasil = gabung_kata(s, t)

import sys
def tentukan_arah(x1, y1, x2, y2, x3, y3, x4, y4):
    titik_pangkal_v1 = complex(x1, y1)
    titik_ujung_v1 = complex(x2, y2)
    titik_pangkal_v2 = complex(x3, y3)
    titik_ujung_v2 = complex(x4, y4)

    if titik_ujung_v1 != titik_pangkal_v2:
        return "tidak terhubung"

    v1 = titik_ujung_v1 - titik_pangkal_v1
    v2 = titik_ujung_v2 - titik_pangkal_v2

    cross_product = (v1.conjugate() * v2).imag

    if cross_product > 0:
        return "kiri"
    elif cross_product < 0:
        return "kanan"
    else:
        return "sejajar"

def main():
    try:
        x1, y1 = map(int, sys.stdin.readline().split())
        x2, y2 = map(int, sys.stdin.readline().split())
        x3, y3 = map(int, sys.stdin.readline().split())
        x4, y4 = map(int, sys.stdin.readline().split())
    except (IOError, ValueError):
        return
    hasil = tentukan_arah(x1, y1, x2, y2, x3, y3, x4, y4)
    print(hasil)
if __name__ == "__main__":
    main()


import sys
def longest_common_prefix(strs):
    if not strs:
        return ""
    strs.sort()
    
    first_str = strs[0]
    last_str = strs[-1]
    lcp = []
    for i in range(min(len(first_str), len(last_str))):
        if first_str[i] == last_str[i]:
            lcp.append(first_str[i])
        else:
            break     
    return "".join(lcp)

def main():
    try:
        n = int(sys.stdin.readline())
        input_list = [sys.stdin.readline().strip() for _ in range(n)]
        result = longest_common_prefix(input_list)
        print(result)
    except (IOError, ValueError):
        pass
if __name__ == "__main__":
    main()

import sys

def hitung_luas_poligon(vertices):
    n = len(vertices)
    if n < 3:
        return 0.0
    luas_ganda = 0
    for i in range(n):
        x1, y1 = vertices[i]
        x2, y2 = vertices[(i + 1) % n]
        
        luas_ganda += (x1 * y2) - (x2 * y1)  
    return abs(luas_ganda) / 2.0

def main():
    try:
        n = int(sys.stdin.readline())
    except (IOError, ValueError):
        return
    titik_awal = []
    for _ in range(n):
        x, y = map(int, sys.stdin.readline().split())
        titik_awal.append((x, y))
    k = int(sys.stdin.readline())
    titik_bahaya_set = set()
    for _ in range(k):
        titik_bahaya_set.add(tuple(map(int, sys.stdin.readline().split())))
    luas_sebelum = hitung_luas_poligon(titik_awal)
    print(f"{luas_sebelum:.3f}")
    titik_aman = [p for p in titik_awal if p not in titik_bahaya_set]
    luas_sesudah = hitung_luas_poligon(titik_aman)
    print(f"{luas_sesudah:.3f}")
if __name__ == "__main__":
    main()


def sieve_of_eratosthenes(n):
    is_prime = [True] * (n + 1)
    if n >= 0:
        is_prime[0] = False
    if n >= 1:
        is_prime[1] = False
    p = 2
    while p * p <= n:
        if is_prime[p]:
            for i in range(p * p, n + 1, p):
                is_prime[i] = False
        p += 1
    primes = []
    for i in range(2, n + 1):
        if is_prime[i]:
            primes.append(i) 
    return primes
def main():
    try:
        n = int(sys.stdin.readline())
        prime_numbers = sieve_of_eratosthenes(n)
        print(*prime_numbers)
    except (IOError, ValueError):
        pass
if __name__ == "__main__":
    main()


import sys

def compute_lps(s):
    n = len(s)
    lps = [0] * n
    length = 0
    i = 1
    while i < n:
        if s[i] == s[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
    return lps

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    if n == 0:
        print(0)
        return
    lps = compute_lps(s)
    len_border = lps[-1]
    k = n - len_border
    if n % k == 0:
        print(k)
    else:
        print(n)
solve()

import sys

def dist_sq(p1, p2):
    return (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2

def jarak_euclidean(points):
    n = len(points)
    if n <= 3:
        min_d2 = float('inf')
        for i in range(n):
            for j in range(i + 1, n):
                min_d2 = min(min_d2, dist_sq(points[i], points[j]))
        return min_d2
    mid = n // 2
    mid_point = points[mid]
    d2_left = jarak_euclidean(points[:mid])
    d2_right = jarak_euclidean(points[mid:])
    d2 = min(d2_left, d2_right)
    strip = []
    for p in points:
        if (p[0] - mid_point[0])**2 < d2:
            strip.append(p)    
    strip.sort(key=lambda p: p[1])
    for i in range(len(strip)):
        for j in range(i + 1, len(strip)):
            if (strip[j][1] - strip[i][1])**2 >= d2:
                break
            d2 = min(d2, dist_sq(strip[i], strip[j]))    
    return d2

def solve():
    n = int(sys.stdin.readline())
    points = [tuple(map(int, sys.stdin.readline().split())) for _ in range(n)]
    points.sort()
    result = jarak_euclidean(points)
    print(result)

solve()

import sys
input = sys.stdin.readline
def sieve(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    return [i for i, v in enumerate(is_prime) if v]
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a
MOD = 10**9 + 7
N, K = map(int, input().split())
primes = sieve(N)
ans = sum(p for p in primes if gcd(p, K) == 1) % MOD
print(ans)

import sys
input = sys.stdin.readline
S = input().strip()
palindromes = set()
for i in range(len(S)):
    l, r = i, i
    while l >= 0 and r < len(S) and S[l] == S[r]:
        palindromes.add(S[l:r+1])
        l -= 1
        r += 1
    l, r = i, i+1
    while l >= 0 and r < len(S) and S[l] == S[r]:
        palindromes.add(S[l:r+1])
        l -= 1
        r += 1
print(len(palindromes))

import sys
input = sys.stdin.readline
R = int(input())
R2 = R * R
count_titik_dalam_lingkaran = 0
for x in range(-R, R + 1):
    y_max = int((R2 - x * x) ** 0.5)
    count_titik_dalam_lingkaran += (2 * y_max + 1)
print(count_titik_dalam_lingkaran)

import sys

def main():
    n = int(sys.stdin.readline())
    k = int(sys.stdin.readline())
    primes = list(map(int, sys.stdin.readline().split()))
    terkontaminasi = 0
    for i in range(1, 1 << k):
        product = 1
        subset_size = 0
        
        for j in range(k):
            if (i >> j) & 1:
                if product > n / primes[j]:
                    product = n + 1
                    break
                product *= primes[j]
                subset_size += 1
        if product > n:
            continue
        term = n // product
        if subset_size % 2 == 1:
            terkontaminasi += term
        else:
            terkontaminasi -= term  
    print(n - terkontaminasi)
main()


import sys
input = sys.stdin.readline

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a
def mod_pow(a, b, m):
    res = 1
    a %= m
    while b:
        if b & 1:
            res = res * a % m
        a = a * a % m
        b >>= 1
    return res
a, b, m = map(int, input().split())
if gcd(a, m) != 1:
    print(-1)
else:
    print(mod_pow(a, b, m))

def overlap_string(S, P):
    S = input().strip()
    P = input().strip()
    count = 0
    i = 0

    while i <= len(S) - len(P):
        if S[i:i+len(P)] == P:
            count += 1
            i += 1
        else:
            i += 1
    print(count)
overlap_string()

import sys
input = sys.stdin.readline
#Jumlah Bilangan ≤ N yang Kelipatan A atau B 
# tetapi Bukan Kelipatan K
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a
def lcm(a, b):
    return a * b // gcd(a, b)
N, A, B, K = map(int, input().split())
count_a = N // A
count_b = N // B
count_ab = N // lcm(A, B)
total = count_a + count_b - count_ab
count_k = N // K
count_ak = N // lcm(A, K)
count_bk = N // lcm(B, K)
count_abk = N // lcm(lcm(A, B), K)
exclude = count_ak + count_bk - count_abk
print(total - exclude)


#Panjang Substring Terpanjang
# Tanpa Karakter Sama
S = input().strip()
seen = set()
l = 0
res = 0
for r in range(len(S)):
    while S[r] in seen:
        seen.remove(S[l])
        l += 1
    seen.add(S[r])
    res = max(res, r - l + 1)
print(res)


#Jumlah Persegi Sempurna Dalam Persegi Panjang
import sys
input = sys.stdin.readline
L, W = map(int, input().split())
limit = min(L, W)
res = 0
for k in range(1, limit + 1):
    res += (L - k + 1) * (W - k + 1)
print(res)

#Jumlah Bilangan Prima ≤ N yang Tidak Membagi K
def sieve(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(n**0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    return [i for i, v in enumerate(is_prime) if v]
N, K = map(int, input().split())
MOD = 10**9 + 7
primes = sieve(N)
ans = sum(p for p in primes if K % p != 0) % MOD
print(ans)

#Subsequence Palindromik Terpanjang
S = input().strip()
n = len(S)
dp = [[0]*n for _ in range(n)]
for i in range(n-1, -1, -1):
    dp[i][i] = 1
    for j in range(i+1, n):
        if S[i] == S[j]:
            dp[i][j] = dp[i+1][j-1] + 2
        else:
            dp[i][j] = max(dp[i+1][j], dp[i][j-1])
print(dp[0][n-1])


#Jumlah Titik (x,y) di Dalam Persegi Panjang
#  dengan GCD(x,y) = 1
def phi_upto(n):
    phi = [i for i in range(n+1)]
    for i in range(2, n+1):
        if phi[i] == i:
            for j in range(i, n+1, i):
                phi[j] -= phi[j] // i
    return phi
L, W = map(int, input().split())
phi = phi_upto(L)
ans = 0
for i in range(1, L+1):
    ans += phi[i] * (W // i)
print(ans)


#Jumlah Bilangan Prima Coprime dengan N
def sieve(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    return [i for i, v in enumerate(is_prime) if v]
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a
MOD = 10 ** 9 + 7
N = int(input())
primes = sieve(N)
ans = sum(p for p in primes if gcd(p, N) == 1) % MOD
print(ans)


#Jumlah Titik (x, y) dengan 1 ≤ x ≤ A, 1 ≤ y ≤ B 
# dan GCD(x, y) = K
def phi_upto(n):
    phi = [i for i in range(n+1)]
    for i in range(2, n+1):
        if phi[i] == i:
            for j in range(i, n+1, i):
                phi[j] -= phi[j] // i
    return phi
A, B, K = map(int, input().split())
A //= K
B //= K
if A == 0 or B == 0:
    print(0)
else:
    phi = phi_upto(min(A, B))
    ans = 0
    for d in range(1, min(A, B)+1):
        ans += phi[d] * (A // d) * (B // d)
    print(ans)

#Jumlah Substring Palindromik
# yang Unik
def sieve(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    return [i for i, v in enumerate(is_prime) if v]
def gcd(a, b):
    while b:
        a, b = b, a % b
MOD = 10 ** 9 + 7
N = int(input())
primes = sieve(N)
ans = sum(p for p in primes if gcd(p, N) == 1) % MOD
print(ans)
