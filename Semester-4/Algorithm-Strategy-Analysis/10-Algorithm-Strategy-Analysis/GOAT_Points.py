# Tahun 2050. Setelah mengguncang dunia dengan dribbling sakti dan selebrasi samba 
# di pinggir lapangan, Antony kini telah menjadi manajer legendaris klub Manchester United.
# Dikenal sebagai GOAT Antony, ia membawa filosofi baru: "Menang dengan berbagai gaya."

# Namun, MU sedang krisis finansial akibat membayar gaji AI yang jadi asisten pelatih. 
# Maka, GOAT Antony harus cerdas memanfaatkan anggaran terbatas untuk meminjam 
# pemain-pemain dari berbagai klub.

# Setiap pemain memiliki:
# Biaya peminjaman per bulan (dalam juta euro)
# Kontribusi ke performa MU per bulan, diukur dalam satuan unik: "GOAT Points"
# MU hanya punya b juta euro untuk peminjaman. Untungnya, 
# GOAT Antony boleh meminjam pemain sebagian musim (misalnya 2 dari 6 bulan). 
# Biaya dan kontribusi dihitung proporsional.
# Tugasmu adalah membantu Antony memilih pemain agar total GOAT Points yang didapat 
# MU sebesar mungkin.

# Input Format
# Baris pertama: dua bilangan bulat n dan b — jumlah pemain yang tersedia 
# dan anggaran transfer MU (dalam juta euro).
# Lalu n baris berikutnya: dua bilangan bulat kontribusi[i] dan biaya[i] — kontribusi dan biaya sewa pemain ke-i per bulan.

# Constraints
# 1 ≤ n ≤ 10^5
# 1 ≤ kontribusi[i], biaya[i] ≤ 10^4
# 1 ≤ b ≤ 10^6
# Output Format
# Cetak satu angka bertipe float — total GOAT Points maksimum, dengan dua angka di belakang koma.

# Sample Input 0
# 3 50
# 60 20
# 100 50
# 120 30
# Sample Output 0
# 180.00

# Sample Input 1
# 2 40
# 100 50
# 60 30
# Sample Output 1
# 80.00

def Max_GOAT_Points(n, b, players):
    players.sort(key=lambda x: x[0]/x[1], reverse=True)
    total_points = 0.0
    remaining_budget = b
    
    for kontribusi, biaya in players:
        if remaining_budget == 0:
            break
        if biaya <= remaining_budget:
            total_points += kontribusi
            remaining_budget -= biaya
        else:
            fraction = remaining_budget / biaya
            total_points += kontribusi * fraction
            remaining_budget = 0
    
    return total_points


n, b = map(int, input().split())
players = []
for _ in range(n):
    kontribusi, biaya = map(int, input().split())
    players.append((kontribusi, biaya))

result = Max_GOAT_Points(n, b, players)
print(f"{result:.2f}")