# Di Turnamen Pokemon di daerah Temcy, Satoshi dan Pikachu sedang berhadapan 
# dengan Charizard yang sangat kuat, meraka harus menghadapinya sampai Health Point (HP) Charizard habis. 
# Pikachu memiliki sejumlah skill yang dapat digunakan untuk menyerang Charizard. 
# Setiap skill memiliki damage yang dihasilkan dan biaya SP (stamina points) yang harus dikeluarkan. 
# Pikachu harus memilih skill yang paling optimal untuk mengalahkan Charizard dengan 
# memaksimalkan damage yang dihasilkan tanpa melebihi batas SP yang dimiliki.

# Tentukan total damage yang dihasilkan oleh Pikachu dan status Charizard apakah KO (kalah) atau Terluka.

# Input Format
# Baris pertama: tiga bilangan bulat positif S= (max tenaga/SP Pikachu), J= (jumlah skill yang dapat dikeluarkan Pikachu), dan H= (Health Point Charizard).
# Baris kedua sampai ke J=: dua bilangan bulat D= (damage yang dihasilkan skill Pikachu) dan P= (SP skill).
# Constraints
# 1≤S≤10^4
# 1≤J≤10^6
# 1≤D≤10^5
# 1≤P≤10^4

# Pikachu tidak dapat memilih skill yang sama untuk melawan Charizard.
# Output Format
# Sebuah string yang menyatakan total damage yang dihasilkan dan status Charizard ("KO" atau "Terluka").

# Sample Input 0
# 10 3 30
# 15 5
# 10 3
# 5 2
# Sample Output 0
# 30 KO

# Sample Input 1
# 5 2 20
# 10 3
# 5 2
# Sample Output 1
# 15 Terluka

def Max_Damage(S, skills, H):
    skills.sort(key=lambda x: (-x[0], x[1]))
    total_damage = 0
    remaining_sp = S

    for D_skill, P_skill in skills: 
        if P_skill <= remaining_sp:
            total_damage += D_skill
            remaining_sp -= P_skill
        if remaining_sp == 0:
            break
    status = "KO" if total_damage >= H else "Terluka"
    return total_damage, status

S_max_sp, J_num_skills, H_charizard_hp = map(int, input().split())
skills_input_list = []
for _ in range(J_num_skills):
    d, p = map(int, input().split())
    skills_input_list.append((d, p))
    
final_damage, charizard_status = Max_Damage(S_max_sp, skills_input_list, H_charizard_hp)
print(final_damage, charizard_status)