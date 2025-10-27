# Di Hogwarts, para anak elf dari berbagai penjuru berkumpul dalam Festival Musim Dingin. 
# Mereka datang dengan rasa lapar yang hanya bisa dipuaskan oleh roti ajaib 
# yang dipanggang oleh Penyihir Roti, Master Baguettus.
# Namun, setiap anak elf memiliki tingkat kelaparan (greed factor) yang berbeda-beda, 
# dan setiap roti memiliki ukuran sihir (cookie size) tertentu. 
# Agar seorang anak elf merasa kenyang dan puas, dia harus mendapatkan roti dengan 
# ukuran sihir minimal sebesar tingkat kelaparannya.

# Input Format
# Baris pertama berisi deretan bilangan bulat yang merepresentasikan tingkat kelaparan anak-anak elf, dipisahkan dengan spasi.
# Baris kedua berisi deretan bilangan bulat yang merepresentasikan ukuran sihir dari roti-roti ajaib (cookie sizes), dipisahkan dengan spasi.
# Constraints

# 1 ≤ jumlah anak elf ≤ 3 x 10⁴
# 0 ≤ jumlah roti ajaib ≤ 3 x 10⁴
# 1 <= g[i], s[j] <= 2³¹ - 1 (g[i] =  tingkat kelaparan anak ke-i, s[j] = ukuran sihir roti ke--j)
# Output Format
# Integer

# Sample Input 0
# 1 2 3
# 1 1
# Sample Output 0
# 1

# Sample Input 1
# 1 2
# 1 2 3 
# Sample Output 1
# 2

def Max_Satisfied(greed, cookies):
    greed.sort()
    cookies.sort()
    i = 0
    satisfied = 0
    for hunger in greed :
        while i < len(cookies) and cookies[i] < hunger:
            i += 1
        if i < len(cookies):
            satisfied += 1
            i += 1
    return satisfied

greed = list(map(int, input().split()))
cookies = list(map(int, input().split()))
print(Max_Satisfied(greed, cookies))
