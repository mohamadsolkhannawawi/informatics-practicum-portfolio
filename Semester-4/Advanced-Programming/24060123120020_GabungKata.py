# Nama file    : 24060123120020_GabungKata.py
# Nama Pembuat : Mohamad Solkhan Nawawi
# NIM          : 24060123120020
# # Deskripsi  : Program untuk menghitung jumlah karakter minimal
#                yang diperlukan untuk menggabungkan
#                dua string sehingga keduanya tetap sebagai substring.

# def gabung_kata(s, t):
#     n = len(s)
#     m = len(t)
#     overlap = 0
#     for i in range(1, min(n, m) + 1):
#         if s[-i:] == t[:i]:
#             overlap = i
#     stringBeda = t[overlap:]
#     hasil = s + stringBeda
#     return len(hasil)

# s = input().strip()
# t = input().strip()
# hasil = gabung_kata(s, t)
# print(hasil)

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
print(hasil)       