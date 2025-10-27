import random

def is_prime_miller_rabin(n, k=5):
    """
    Menguji apakah n adalah bilangan prima menggunakan Algoritma Miller-Rabin.
    n : bilangan yang diuji
    k : jumlah uji coba (semakin besar, semakin akurat)
    """
    if n <= 1:
        return False
    if n in (2, 3):
        return True
    if n % 2 == 0:
        return False
    
    # Menulis n-1 sebagai 2^s * d dengan d ganjil
    s, d = 0, n - 1
    while d % 2 == 0:
        s += 1
        d //= 2
    
    for _ in range(k):
        a = random.randint(2, n - 2)  # Pilih bilangan acak a ∈ [2, n − 2]
        x = pow(a, d, n)  # Hitung x = a^d mod n
        
        if x == 1 or x == n - 1:
            continue  # Lanjutkan ke iterasi berikutnya
        
        for _ in range(s - 1):
            x = pow(x, 2, n)  # Hitung x = x^2 mod n
            if x == n - 1:
                break  # Lanjutkan ke iterasi berikutnya
        else:
            return False  # Komposit
    
    return True  # Kemungkinan Prima

# Contoh penggunaan
n = int(input("Masukkan bilangan: "))
k = int(input("Masukkan jumlah uji coba: "))
print("Prima" if is_prime_miller_rabin(n, k) else "Komposit")


def miller_rabin(n, k=5):
    # Langkah 1: Jika n <= 1, bukan prima
    if n <= 1:
        return "Komposit"
    
    # Langkah 4: Jika n = 2 atau n = 3, maka prima
    if n == 2 or n == 3:
        return "Prima"
    
    # Langkah 7: Jika n genap selain 2, maka bukan prima
    if n % 2 == 0:
        return "Komposit"
    
    # Langkah 10: Tulis n - 1 sebagai 2^s * d dengan d ganjil
    d = n - 1
    s = 0
    while d % 2 == 0:
        d //= 2
        s += 1
    
    # Langkah 11: Ulangi pengujian sebanyak k kali
    for _ in range(k):
        # Langkah 12: Pilih bilangan acak a dalam rentang [2, n - 2]
        a = random.randint(2, n - 2)
        
        # Langkah 13: Hitung x = a^d mod n
        x = pow(a, d, n)
        
        # Langkah 14: Jika x = 1 atau x = n - 1, lanjutkan ke iterasi berikutnya
        if x == 1 or x == n - 1:
            continue
        
        # Langkah 17: Ulangi s - 1 kali
        for _ in range(s - 1):
            # Langkah 18: Hitung x = x^2 mod n
            x = pow(x, 2, n)
            
            # Langkah 19: Jika x = n - 1, lanjutkan ke iterasi berikutnya
            if x == n - 1:
                break
        else:
            # Langkah 23: Jika tidak ada x yang bernilai n - 1, maka n bukan prima
            return "Komposit"
    
    # Langkah 25: Jika lolos semua pengujian, kemungkinan besar prima
    return "Prima"

# Membaca input jumlah angka yang akan diuji
T = int(input())

# Proses setiap angka dan cetak hasilnya
for _ in range(T):
    n = int(input())
    print(miller_rabin(n))
