# Nama File : 24060123120020_LC.py
# Nama      : Mohamad Solkhan Nawawi
# Kelas     : C
# Tanggal   : 28 Mei 2025
# Deskripsi : Program untuk mengoptimalkan jadwal dengan Dynamic Programming (DP)
#             Live Coding ASA 28 Mei 2025

import math
import random

# Fungsi untuk mengonversi waktu ke menit
def time_to_minutes(t):
    h, m = map(int, t.split(":"))
    return h * 60 + m

# Fungsi untuk mengonversi menit ke waktu HH:MM
def minutes_to_time(m):
    h, mn = divmod(m, 60)
    return "%02d:%02d" % (h, mn)

def find_last_non_conflicting(schedules, i):
    # Dicari mulai dari jadwal sebelum i, berhenti jika sudah mencapai indeks 0, looping mundur atau decrement
    for j in range(i - 1, -1, -1): 
        if schedules[j]['end'] <= schedules[i]['start']:
            return j
    return -1

# Tampilkan tabel jadwal sesuai format pada soal, dengan tambahan kolom Total
def print_schedules_table(schedules):
    print("\nTABEL JADWAL:")
    # Header tabel, diformat agar rata kiri sesuai lebar kolom
    print(f"{'Nama':<5} {'Mulai':<6} {'Selesai':<7} {'Dewasa':<7} {'Anak':<5} {'Staf':<5} {'Total':<5}")
    for s in schedules:
        # Tampilkan setiap jadwal dalam schedule
        print(f"{s['name']:<5} {minutes_to_time(s['start']):<6} {minutes_to_time(s['end']):<7} {s['adults']:<7} {s['kids']:<5} {s['staff']:<5} {s['total']:<5}")
    print()

def schedule_optimization_dp(schedules, max_capacity):
    valid_schedules = [s for s in schedules if s['total'] <= max_capacity] # Memastikan jumlah orang dalam jadwal tidak melebihi kapasitas
    valid_schedules.sort(key=lambda x: x['end']) # Diurutkan berdasarkan waktu selesai
    n = len(valid_schedules)
    if n == 0:
        return 0, []

    print_schedules_table(valid_schedules)

    dp = [0] * n
    selected = [[] for _ in range(n)] # Inisialisasi DP dan daftar terpilih

    print("Langkah-langkah DP:")
    for i in range(n):
        profit_incl = valid_schedules[i]['total'] # Hitung keuntungan jika memasukkan jadwal ke-i
        incl_names = [valid_schedules[i]['name']] # Nama jadwal yang dipilih
        l = find_last_non_conflicting(valid_schedules, i)
        if l != -1:
            profit_incl += dp[l]
            incl_names = selected[l] + [valid_schedules[i]['name']]

        # Bandingkan keuntungan dengan DP sebelumnya
        if i > 0 and dp[i - 1] > profit_incl:
            dp[i] = dp[i - 1]
            selected[i] = selected[i - 1]
            print(f"Step {i}: Pilih DP[{i-1}] ({dp[i-1]}) > profit_incl ({profit_incl}), DP[{i}] = {dp[i]}, Jadwal: {selected[i]}")
        else:
            dp[i] = profit_incl
            selected[i] = incl_names
            print(f"Step {i}: Pilih profit_incl ({profit_incl}) >= DP[{i-1}] ({dp[i-1] if i>0 else 0}), DP[{i}] = {dp[i]}, Jadwal: {selected[i]}")

    return dp[-1], selected[-1] # Jadwal terpilih dan total keuntungan

# Generate jadwal dengan kolom Dewasa, Anak, Staf, Total
def generate_random_schedules(n, max_capacity):
    schedules = []
    for i in range(n):
        name = f"P{i+1}"
        start_hour = random.randint(6, 20)
        duration = random.randint(1, 3)
        start_minute = 0
        start = start_hour * 60 + start_minute
        end = start + duration * 60
        if end > 1440: # Jika waktu selesai melebihi 24 jam, atur ke 1440 (24:00)
            end = 1440
        adults = random.randint(10, 40)
        kids_raw = random.randint(0, 20)
        kids = math.ceil(kids_raw / 2)
        staff = random.randint(0, 10)
        total = adults + kids + staff
        schedules.append({
            'name': name,
            'start': start,
            'end': end,
            'adults': adults,
            'kids': kids_raw,
            'staff': staff,
            'total': total
        })
    return schedules

def run_experiment():
    max_capacity = 50

    for size in [10]:
        print(f"\nUJI COBA UNTUK {size} JADWAL:")
        schedules = generate_random_schedules(size, max_capacity)
        max_profit, chosen = schedule_optimization_dp(schedules, max_capacity)
        print("\nJadwal Terpilih:", chosen)
        print("Total Keuntungan Maksimal:", max_profit)

# Jalankan
run_experiment()

print("\nKompleksitas algoritma: O(n^2) karena pencarian jadwal non-konflik dilakukan secara linear untuk setiap jadwal.")