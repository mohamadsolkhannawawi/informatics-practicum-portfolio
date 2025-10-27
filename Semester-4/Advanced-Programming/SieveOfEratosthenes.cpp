#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk membangkitkan sieve of Eratosthenes
void generateSieve(int n, int sieve[]) {
    // Inisialisasi semua elemen menjadi 0 (asumsi prima)
    for (int i = 0; i <= n; i++) {
        sieve[i] = 0;
    }

    // Algoritma utama Sieve
    for (int x = 2; x <= n; x++) {
        if (sieve[x]) continue; // Jika sudah ditandai bukan prima, lewati
        for (int u = 2 * x; u <= n; u += x) {
            sieve[u] = 1; // Tandai kelipatan x sebagai bukan prima
        }
    }
}

// Contoh penggunaan
int main() {
    int n = 20;
    int* sieve = (int*) malloc((n + 1) * sizeof(int));

    generateSieve(n, sieve);

    printf("Bilangan prima dari 2 sampai %d:\n", n);
    for (int i = 2; i <= n; i++) {
        if (!sieve[i]) {
            printf("%d ", i); // Jika tidak ditandai, berarti prima
        }
    }

    printf("\n");

    free(sieve);
    return 0;
}

import sys
def bilangan_keberuntungan():
    n = int(sys.stdin.readline())
    k = int(sys.stdin.readline())
    primes = list(map(int, sys.stdin.readline().split()))
    total_sial = 0
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
            total_sial += term
        else:
            total_sial -= term  
    print(n - total_sial)
bilangan_keberuntungan()


def periode_string(s):
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
    lps = periode_string(s)
    len_border = lps[-1]
    k = n - len_border
    if n % k == 0:
        print(k)
    else:
        print(n)
solve()


