"""
Deskripsi
Hedar merupakan seorang siswa yang sangat dermawan, ia selalu meminjamkan penanya kepada
teman sekelasnya hingga penanya tidak diketahui lagi siapa yang sedang memegangnya.
Suatu hari pena hedar kehabisan tinta. Beruntung hedar ingat bahwa ia pernah meminjamkan
penanya kepada a, ia pun meminta penanya kepada a. Bukannya mendapat penanya kembali a,
malah berkata bahwa penanya di berikan kepada Pa. hedar pun meminta penanya kepada Pa,
namun, Pa memberitahu bahwa penanya ada pada temannya yang lain. Kesal, hedar pun
menandai temannya yang sudah pernah ditanya, dan jika temannya mendapat 2 tanda atau telah
ditanya 2 kali oleh Hedar maka hedar pun akan mengambil paksa pena milih kawannya tersebut
dan menghentikan pencarian penanya.
Jika dalam kelas tersebut terdapat N orang siswa tidak termasuk Hedar, yang dinomori dari 1
sampai N, dengan tiap siswa akan mengaku telah memberikan pena Hedar terhadap orang lain,
bantulah Hedar menemukan orang yang akan ditandai 2 kali oleh hedar jika ia mulai mencari
penanya dengan menanyai siswa a.
Format Masukan
Pada baris pertama berisi sebuah bilangan N dimana 2 ≤ N ≤ 1000.
Pada baris kedua berisi N buah bilangan Pi yang merepresentasikan nomor siswa yang ditunjuk
oleh siswa ke-i pada bilangan ke-i, dimana 1 ≤ Pi ≤ N.
Format Keluaran
Keluaran terdiri dari N baris yang merupakan orang yang akan ditandai 2 kali oleh hedar jika ia
mulai mencari penanya dengan menanyai siswa a.
Contoh masukan 1
3
2 3 2

Contoh keluaran 1
2 2 3

Penjelasan Masukan 1
Representasi graph yang terbentuk dari tunjuk-tunjukan siswa yang meminjam pena Hedar
adalah.

Jika a = 1, maka hedar akan menanyai 1, lalu 2, lalu 3, lalu 2. Pada Urutan tersebut 2 akan
mendapat tanda sebanyak 2 kali, sehingga hedar akan mengambil paksa pena dari siswa no 2.
Jika a = 2, maka hedar akan menanyai 2, lalu 3, lalu 2. Pada Urutan tersebut 2 akan mendapat
tanda sebanyak 2 kali, sehingga hedar akan mengambil paksa pena dari siswa no 2.
Jika a = 3, maka hedar akan menanyai 3, lalu 2, lalu 3, Pada Urutan tersebut 3 akan mendapat
tanda sebanyak 2 kali, sehingga hedar akan mengambil paksa pena dari siswa no 3.
"""

def dfs(penunjuk, now, counter):
    if counter[now] == 2:
        return now + 1  
    counter[now] += 1
    return dfs(penunjuk, penunjuk[now] - 1, counter)

n = int(input())
penunjuk = list(map(int, input().split()))

for a in range(n):
    counter = [0] * n
    hasil = dfs(penunjuk, a, counter)
    print(hasil, end=' ')