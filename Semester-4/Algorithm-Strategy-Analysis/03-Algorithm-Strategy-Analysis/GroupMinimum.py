# Di masa depan, Wall-E, si robot kecil yang bertugas membersihkan Bumi, menemukan tumpukan benda-benda yang perlu disortir. Setiap benda memiliki rentang waktu tertentu (dalam detik) ketika benda tersebut aktif. Wall-E harus mengelompokkan benda-benda ini ke dalam beberapa grup, di mana tidak ada dua benda dalam satu grup yang memiliki waktu aktif yang tumpang tindih. Bantu Wall-E menentukan jumlah grup minimum yang dibutuhkan untuk mengelompokkan semua benda!

# WAJIB MENGGUNAKAN DIVIDE AND CONQUER

# Input Format

# Sebuah array 2D yang berisi rentang waktu aktif setiap benda. Setiap interval direpresentasikan sebagai [lefti, righti], yang berarti benda aktif dari detik ke-lefti hingga detik ke-righti.
# Constraints

# 1 <= jumlah benda <= 10^5
# Setiap interval memiliki 2 elemen: 1 <= lefti <= righti <= 10^6
# Output Format

# Kembalikan jumlah grup minimum yang dibutuhkan.
# Sample Input 0

# [[5, 10], [6, 8], [1, 5], [2, 3], [1, 10]]
# Sample Output 0

# 3
# Sample Input 1

# [[1, 3], [5, 6], [8, 10], [11, 13]]
# Sample Output 1

# 1

def merge_sort_intervals(intervals):
    # Fungsi untuk mengurutkan interval berdasarkan waktu mulai menggunakan Divide and Conquer
    if len(intervals) <= 1:
        return intervals
    
    mid = len(intervals) // 2
    left = merge_sort_intervals(intervals[:mid])
    right = merge_sort_intervals(intervals[mid:])
    
    return merge(left, right)

def merge(left, right):
    # Fungsi untuk menggabungkan dua bagian terurut
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i][0] <= right[j][0]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result

def count_minimum_groups(intervals):
    if not intervals:
        return 0
    
    # Urutkan interval terlebih dahulu
    sorted_intervals = merge_sort_intervals(intervals)
    
    groups = []
    
    for interval in sorted_intervals:
        placed = False
        for group in groups:
            # Jika interval tidak tumpang tindih dengan interval terakhir dalam grup, tambahkan ke grup tersebut
            if group[-1][1] < interval[0]:
                group.append(interval)
                placed = True
                break
        if not placed:
            # Jika tidak ada grup yang cocok, buat grup baru
            groups.append([interval])
    
    return len(groups)

intervals = eval(input())

# Output jumlah minimum grup yang dibutuhkan
print(count_minimum_groups(intervals))


def merge_sort_interval(interval):
    if len(interval) <= 1:
        return interval
    
    tengah = len(interval) // 2
    kiri = merge_sort_interval(interval[:tengah])
    kanan = merge_sort_interval(interval[tengah:])

    return merge_interval(kiri, kanan)

def merge_interval(kiri, kanan):
    hasil = []
    i = 0
    j = 0
    while i < len(kiri) and j < len(kanan):
        if kiri[i][0] <= kanan[j][0]:
            hasil.append(kiri[i])
            i += 1
        else:
            hasil.append(kanan[j])
            j += 1

    hasil.extend(kiri[i:])
    hasil.extend(kanan[j:])
    return hasil

def group_minimum(interval):
    if not interval:
        return 0
    
    interval_terurut = merge_sort_interval(interval)
    group = []
    for i in interval_terurut:
        placed = False
        for g in group:
            if g[-1][1] < i[0]:
                g.append(i)
                placed = True
                break
        if not placed:
            group.append([i])

    return len(group)

interval = eval(input())
print(group_minimum(interval))
    