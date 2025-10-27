# si a punya input berupa berbagai bilangan integer dengan mengikuti pola (seperti aritmatika, geometri, fibonancy, pangkat 2, dan bilangan prima). diantara bilangan 2 tsb, ada 1 angka yang tidak sesuain dengan pola yang terdapat di input. tugas kalian mencari index list dengan angka yang tidak sesuai tersebut dengan divide and conquer

# Input Format

# 1 3 5 6 9

# Constraints

# bilangan integer

# Output Format

# 3

# Sample Input 0

# 2 4 6 8 9
# Sample Output 0

# 4
# Sample Input 1

# 3 6 12 20 48
# Sample Output 1

# 3


import math
from fractions import Fraction

def is_arithmetic(arr):
    if len(arr) < 2:
        return True
    diff = arr[1] - arr[0]
    return all(arr[i] - arr[i - 1] == diff for i in range(2, len(arr)))

def find_geometric_anomaly(arr):
    n = len(arr)
    possible_ratios = []

    # Coba semua kombinasi rasio awal
    for i in range(n):
        for j in range(i + 1, n):
            if arr[i] != 0:
                possible_ratios.append(Fraction(arr[j], arr[i]))

    for ratio in set(possible_ratios):
        mismatch = []
        expected = arr[0]
        for idx, val in enumerate(arr):
            if val != expected:
                mismatch.append(idx)
            expected *= ratio

        if len(mismatch) == 1:
            return mismatch[0]

    return -1

def is_fibonacci(arr):
    if len(arr) < 3:
        return True
    for i in range(2, len(arr)):
        if arr[i] != arr[i - 1] + arr[i - 2]:
            return False
    return True

def is_power_of_two(arr):
    return all(num > 0 and (num & (num - 1)) == 0 for num in arr)

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def is_prime_sequence(arr):
    return all(is_prime(num) for num in arr)

def find_anomaly(arr):
    if is_arithmetic(arr[:-1]) or is_arithmetic(arr[1:]):
        for i in range(len(arr)):
            temp = arr[:i] + arr[i+1:]
            if is_arithmetic(temp):
                return i

    geo_index = find_geometric_anomaly(arr)
    if geo_index != -1:
        return geo_index

    for check in [is_fibonacci, is_power_of_two, is_prime_sequence]:
        for i in range(len(arr)):
            temp = arr[:i] + arr[i+1:]
            if check(temp):
                return i

    return -1

def main():
    arr = list(map(int, input().split()))
    index = find_anomaly(arr)
    print(index)

if __name__ == "__main__":
    main()


import math  # Import modul math untuk fungsi matematika seperti sqrt dan isclose

def is_arithmetic(arr):
    # Periksa jika array memiliki kurang dari 2 elemen, otomatis dianggap aritmetika
    if len(arr) < 2:
        return True
    # Hitung selisih antara dua elemen pertama
    diff = arr[1] - arr[0]
    # Periksa apakah semua selisih elemen berikutnya sama dengan diff
    for i in range(2, len(arr)):
        if arr[i] - arr[i - 1] != diff:
            return False
    return True

def find_geometric_anomaly(arr):
    n = len(arr)  # Panjang array
    possible_ratios = []  # Daftar untuk menyimpan rasio yang mungkin

    # Coba semua kombinasi rasio awal antara dua elemen berbeda
    for i in range(n):
        for j in range(i + 1, n):
            if arr[i] != 0:  # Hindari pembagian dengan nol
                possible_ratios.append(arr[j] / arr[i])

    # Periksa setiap rasio unik yang ditemukan
    for ratio in set(possible_ratios):
        mismatch = []  # Menyimpan indeks elemen yang tidak sesuai dengan rasio
        expected = arr[0]  # Nilai pertama sebagai acuan
        for idx, val in enumerate(arr):
            # Bandingkan nilai saat ini dengan nilai yang diharapkan menggunakan toleransi
            if not math.isclose(val, expected, rel_tol=1e-9):
                mismatch.append(idx)
            expected *= ratio  # Perbarui nilai yang diharapkan dengan mengalikan rasio

        # Jika hanya ada satu ketidaksesuaian, kembalikan indeksnya
        if len(mismatch) == 1:
            return mismatch[0]

    return -1  # Jika tidak ditemukan anomali, kembalikan -1

def is_fibonacci(arr):
    # Deret dengan kurang dari 3 elemen dianggap sebagai Fibonacci
    if len(arr) < 3:
        return True
    # Periksa apakah setiap elemen adalah penjumlahan dua elemen sebelumnya
    for i in range(2, len(arr)):
        if arr[i] != arr[i - 1] + arr[i - 2]:
            return False
    return True

def is_power_of_two(arr):
    # Periksa apakah setiap elemen adalah pangkat dua menggunakan operasi bitwise
    return all(num > 0 and (num & (num - 1)) == 0 for num in arr)

def is_prime(n):
    # Bilangan kurang dari atau sama dengan 1 bukan bilangan prima
    if n <= 1:
        return False
    # Cek pembagi dari 2 hingga akar kuadrat dari n
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def is_prime_sequence(arr):
    # Periksa apakah semua elemen dalam array adalah bilangan prima
    return all(is_prime(num) for num in arr)

def find_anomaly(arr):
    # Cek anomali dalam deret aritmetika dengan menghapus satu elemen
    if is_arithmetic(arr[:-1]) or is_arithmetic(arr[1:]):
        for i in range(len(arr)):
            temp = arr[:i] + arr[i+1:]  # Buat array baru tanpa elemen ke-i
            if is_arithmetic(temp):
                return i  # Kembalikan indeks anomali jika ditemukan

    # Cek anomali dalam deret geometrik
    geo_index = find_geometric_anomaly(arr)
    if geo_index != -1:
        return geo_index

    # Cek anomali dalam deret Fibonacci, pangkat dua, atau bilangan prima
    for check in [is_fibonacci, is_power_of_two, is_prime_sequence]:
        for i in range(len(arr)):
            temp = arr[:i] + arr[i+1:]  # Buat array baru tanpa elemen ke-i
            if check(temp):
                return i  # Kembalikan indeks anomali jika ditemukan

    return -1  # Jika tidak ditemukan anomali, kembalikan -1

def main():
    # Input array dari pengguna dan ubah ke dalam bentuk list integer
    arr = list(map(int, input().split()))
    # Cari indeks anomali dalam array
    index = find_anomaly(arr)
    # Cetak hasil indeks anomali
    print(index)

# Eksekusi fungsi main jika program dijalankan langsung
if __name__ == "__main__":
    main()

def isAritmatika(arr):
    if len(arr) < 2:
        return True
    selisih = arr[1] - arr[0]
    for i in range(2, len(arr)):
        if arr[i] - arr[i -1] != selisih:
            return False
    return True

def isGeometri(arr):
    n = len(arr)
    if n < 2:
        return -1
    
    mismatch = []

    for i in range(1, n):
        if arr[0] == 0 or arr[i] == 0:
            continue  # Hindari pembagian nol
        ratio = arr[i] / arr[0]
        
        expected = arr[0]
        temp_mismatch = []
        
        for idx, val in enumerate(arr):
            if not math.isclose(val, expected, rel_tol=1e-6):
                temp_mismatch.append(idx)
            expected *= ratio

        if len(temp_mismatch) == 1:
            return temp_mismatch[0]

    return -1

def isFibonacci(arr):
    if len(arr) < 3:
        return True
    for i in range(2, len(arr)):
        if arr[i] != arr[i - 1] + arr[i - 2]:
            return False
    return True

def isPangkatDua(arr):
    for num in arr:
        if num <= 0 or (num & (num - 1)) != 0:
            return False
    return True

def isPrima(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def isPrimaSequence(arr):
    for num in arr:
        if not isPrima(num):
            return False
    return True

def findAnomaly(arr):
    if isAritmatika(arr[:-1]) or isAritmatika(arr[1:]):
        for i in range(len(arr)):
            temp = arr[:i] + arr[i+1:]
            if isAritmatika(temp):
                return i

    geo_index = isGeometri(arr)
    if geo_index != -1:
        return geo_index

    for check in [isFibonacci, isPangkatDua, isPrimaSequence]:
        for i in range(len(arr)):
            temp = arr[:i] + arr[i+1:]
            if check(temp):
                return i

    return -1

arr = list(map(int, input().split()))
index = find_anomaly(arr)
print(index)


def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def isqrt(n):
    """Integer square root implementation without math library"""
    if n < 0:
        raise ValueError("Square root not defined for negative numbers")
    if n == 0 or n == 1:
        return n
    
    # Binary search implementation for integer square root
    left, right = 1, n
    while left <= right:
        mid = (left + right) // 2
        if mid * mid == n:
            return mid
        elif mid * mid < n:
            left = mid + 1
        else:
            right = mid - 1
    
    return right  # Return the integer part of the square root

def is_perfect_square(n):
    r = isqrt(n)
    return r * r == n

def count_primes(seq):
    return sum(1 for x in seq if is_prime(x))

def full_prime_expected(n):
    expected = []
    candidate = 2
    while len(expected) < n:
        if is_prime(candidate):
            expected.append(candidate)
        candidate += 1
    return expected

def prime_expected(seq):
    n = len(seq)
    return full_prime_expected(n)

def prime_expected_cont(seq, count):
    n = len(seq)
    full = full_prime_expected(n + count)
    return full[n:]

def arithmetic_expected(seq):
    d = seq[1] - seq[0]
    return [seq[0] + d * i for i in range(len(seq))]

def arithmetic_expected_cont(seq, count):
    d = seq[1] - seq[0]
    start = seq[-1]
    return [start + d * (i+1) for i in range(count)]

def geometric_expected(seq):
    r = seq[1] / seq[0]
    return [int(seq[0] * (r ** i)) for i in range(len(seq))]

def geometric_expected_cont(seq, count):
    r = seq[1] / seq[0]
    start = seq[-1]
    return [int(start * (r ** (i+1))) for i in range(count)]

def fibonacci_expected(seq):
    if len(seq) < 2:
        return seq[:]
    exp = seq[:2]
    for i in range(2, len(seq)):
        exp.append(exp[i-1] + exp[i-2])
    return exp

def fibonacci_expected_cont(seq, count):
    if len(seq) < 2:
        return []
    a, b = seq[-2], seq[-1]
    res = []
    for i in range(count):
        c = a + b
        res.append(c)
        a, b = b, c
    return res

def square_expected(seq):
    s = isqrt(seq[0])
    return [(s + i) ** 2 for i in range(len(seq))]

def square_expected_cont(seq, count):
    s = isqrt(seq[0])
    last_root = isqrt(seq[-1]) if is_perfect_square(seq[-1]) else s + len(seq) - 1
    return [(last_root + i + 1) ** 2 for i in range(count)]

def count_mismatches(actual, expected):
    mismatches = 0
    first_mismatch_index = None
    
    for i, (a, e) in enumerate(zip(actual, expected)):
        if a != e:
            mismatches += 1
            if first_mismatch_index is None:
                first_mismatch_index = i
                
    return mismatches, first_mismatch_index

pattern_candidates = [
    ("square", square_expected, square_expected_cont),
    ("arithmetic", arithmetic_expected, arithmetic_expected_cont),
    ("geometric", geometric_expected, geometric_expected_cont),
    ("fibonacci", fibonacci_expected, fibonacci_expected_cont),
    ("prime", prime_expected, prime_expected_cont)
]

def detect_pattern_tolerant(seq):
    best = (None, None, None, float('inf'), None)
    
    for name, exp_func, cont_func in pattern_candidates:
        if name == "square" and not is_perfect_square(seq[0]):
            continue
        if name == "geometric" and seq[0] == 0:
            continue
            
        exp_seq = exp_func(seq)
        mismatches, first_index = count_mismatches(seq, exp_seq)
        
        if mismatches < best[3]:
            best = (name, exp_func, cont_func, mismatches, first_index)
            
    return best

def main():
    data = list(map(int, input().split()))
    n = len(data)

    if count_primes(data) >= len(data) / 2:
        expected_full = full_prime_expected(n)
        mismatches, first_index = count_mismatches(data, expected_full)
        
        if mismatches > 0:
            print(first_index)
        else:
            print("Full input follows prime pattern.")
        return

    mid = (n + 1) // 2
    left = data[:mid]
    right = data[mid:]

    left_result = detect_pattern_tolerant(left)
    right_result = detect_pattern_tolerant(right)
    
    left_pattern, left_exp_func, left_cont_func, left_mismatch_count, left_first_mismatch = left_result
    right_pattern, right_exp_func, right_cont_func, right_mismatch_count, right_first_mismatch = right_result

    if left_pattern is not None and left_mismatch_count > 0:
        candidate_side = "left"
    elif right_pattern is not None and right_mismatch_count > 0:
        candidate_side = "right"
    else:
        if left_pattern is None and right_pattern is None:
            print("No pattern recognized on both sides.")
            return
        if left_pattern is None:
            candidate_side = "right"
        elif right_pattern is None:
            candidate_side = "left"
        else:
            candidate_side = "left" if len(left) >= len(right) else "right"

    if candidate_side == "left":
        candidate_list = left
        candidate_offset = 0
        pattern_name = left_pattern
        cont_func = left_cont_func
        mismatch_count = left_mismatch_count
        first_mismatch_index = left_first_mismatch
        other_side = right
        other_offset = mid
    else:
        candidate_list = right
        candidate_offset = mid
        pattern_name = right_pattern
        cont_func = right_cont_func
        mismatch_count = right_mismatch_count
        first_mismatch_index = right_first_mismatch
        other_side = left
        other_offset = 0

    if mismatch_count > 0:
        print(candidate_offset + first_mismatch_index)
    else:
        expected_other = cont_func(candidate_list, len(other_side))
        mismatches, first_mismatch = count_mismatches(other_side, expected_other)
        
        if mismatches > 0:
            print(other_offset + first_mismatch)
        else:
            print("Both sides follow the pattern.")

main()
