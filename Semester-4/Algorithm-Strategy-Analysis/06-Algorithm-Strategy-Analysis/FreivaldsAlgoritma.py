import numpy as np

def freivalds(A, B, C, k=5):
    """
    Algoritma Freivalds untuk memverifikasi apakah A × B = C dengan probabilitas tinggi.
    
    Parameters:
    A, B, C : np.array
        Matriks persegi dengan ukuran (n x n).
    k : int
        Jumlah uji coba untuk meningkatkan akurasi.

    Returns:
    str : "Sama" jika hasil perkalian kemungkinan benar, "Tidak Sama" jika salah.
    """
    n = len(A)  # Ukuran matriks

    for _ in range(k):  # 1: for i = 1 to k do
        r = np.random.randint(0, 2, (n, 1))  # 2: Pilih vektor acak r ∈ {0,1}^n
        x = np.dot(B, r)  # 3: Hitung x ← Br
        y = np.dot(A, x)  # 4: Hitung y ← Ax
        z = np.dot(C, r)  # 5: Hitung z ← Cr
        
        if not np.array_equal(y, z):  # 6: if y ≠ z then
            return "Tidak Sama"  # 7: return False (format output)

    return "Sama"  # 10: return True (format output)


# Membaca input dari user
n = int(input())  # Membaca ukuran matriks

A = np.array([list(map(int, input().split())) for _ in range(n)])  # Membaca matriks A
B = np.array([list(map(int, input().split())) for _ in range(n)])  # Membaca matriks B
C = np.array([list(map(int, input().split())) for _ in range(n)])  # Membaca matriks C

# Menjalankan algoritma Freivalds dan mencetak hasil
print(freivalds(A, B, C))


def matrix_mult(A, B):
    """
    Melakukan perkalian matriks A × B secara manual tanpa NumPy.
    """
    n = len(A)
    result = [[0] * n for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            for k in range(n):
                result[i][j] += A[i][k] * B[k][j]
    
    return result


def freivalds(A, B, C, k=5):
    """
    Algoritma Freivalds untuk memverifikasi apakah A × B = C tanpa NumPy.
    """
    n = len(A)

    for _ in range(k):
        # Membuat vektor acak r ∈ {0,1}^n
        r = [0] * n
        for i in range(n):
            r[i] = 1 if (i % 2 == 0) else 0  # Alternatif pengganti randint

        # Menghitung x = B × r
        x = [0] * n
        for i in range(n):
            for j in range(n):
                x[i] += B[i][j] * r[j]

        # Menghitung y = A × x
        y = [0] * n
        for i in range(n):
            for j in range(n):
                y[i] += A[i][j] * x[j]

        # Menghitung z = C × r
        z = [0] * n
        for i in range(n):
            for j in range(n):
                z[i] += C[i][j] * r[j]

        # Jika y ≠ z, return "Tidak Sama"
        if y != z:
            return "Tidak Sama"

    return "Sama"


# Membaca input dari user
n = int(input())  # Membaca ukuran matriks

A = [list(map(int, input().split())) for _ in range(n)]
B = [list(map(int, input().split())) for _ in range(n)]
C = [list(map(int, input().split())) for _ in range(n)]

# Menjalankan algoritma Freivalds dan mencetak hasil
print(freivalds(A, B, C))


def freivalds(A, B, C, k=5):
    """
    Algoritma Freivalds untuk memverifikasi apakah A × B = C.
    """
    n = len(A)

    for _ in range(k):
        # Membuat vektor acak r ∈ {0,1}^n
        r = [1 if (i % 2 == 0) else 0 for i in range(n)]  

        # Menghitung x = B × r
        x = [sum(B[i][j] * r[j] for j in range(n)) for i in range(n)]

        # Menghitung y = A × x
        y = [sum(A[i][j] * x[j] for j in range(n)) for i in range(n)]

        # Menghitung z = C × r
        z = [sum(C[i][j] * r[j] for j in range(n)) for i in range(n)]

        # Jika y ≠ z, return "Tidak Sama"
        if y != z:
            return "Tidak Sama"

    return "Sama"

# Membaca input dari user
n = int(input())  # Membaca ukuran matriks
A = [list(map(int, input().split())) for _ in range(n)]
B = [list(map(int, input().split())) for _ in range(n)]
C = [list(map(int, input().split())) for _ in range(n)]

# Menjalankan algoritma Freivalds dan mencetak hasil
print(freivalds(A, B, C))
