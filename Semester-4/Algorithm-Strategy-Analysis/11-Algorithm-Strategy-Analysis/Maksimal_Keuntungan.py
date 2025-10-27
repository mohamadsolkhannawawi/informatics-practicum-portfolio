import random

# Fungsi ubah waktu HH:MM ke menit
def time_to_minutes(t: str) -> int:
    h, m = map(int, t.split(":"))
    return h * 60 + m

# Fungsi buat waktu dari menit ke string HH:MM (opsional untuk debugging)
def minutes_to_time(m: int) -> str:
    return f"{m // 60:02d}:{m % 60:02d}"

# Fungsi cari indeks jadwal terakhir sebelum ke-i yang tidak bertabrakan
def find_last_non_conflicting(schedules, i):
    for j in range(i - 1, -1, -1):
        if schedules[j]['end'] <= schedules[i]['start']:
            return j
    return -1

# Fungsi DP untuk mencari jadwal optimal
def schedule_optimization_dp(schedules, max_capacity):
    valid_schedules = [s for s in schedules if s['total'] <= max_capacity]
    valid_schedules.sort(key=lambda x: x['end'])
    n = len(valid_schedules)
    if n == 0:
        return 0, []

    dp = [0] * n
    selected = [[] for _ in range(n)]

    for i in range(n):
        profit_incl = valid_schedules[i]['total']
        incl_names = [valid_schedules[i]['name']]
        l = find_last_non_conflicting(valid_schedules, i)
        if l != -1:
            profit_incl += dp[l]
            incl_names = selected[l] + [valid_schedules[i]['name']]

        if i > 0 and dp[i - 1] > profit_incl:
            dp[i] = dp[i - 1]
            selected[i] = selected[i - 1]
        else:
            dp[i] = profit_incl
            selected[i] = incl_names

    return dp[-1], selected[-1]

# Fungsi generate jadwal acak
def generate_random_schedules(n, max_capacity):
    schedules = []
    for i in range(n):
        name = f"P{i+1}"
        start_hour = random.randint(6, 20)
        duration = random.randint(1, 3)
        start_minute = 0
        start = start_hour * 60 + start_minute
        end = start + duration * 60
        if end > 1440:
            end = 1440
        adults = random.randint(10, 40)
        kids = random.randint(0, 20)
        staff = random.randint(0, 10)
        total = adults + kids + staff
        schedules.append({
            'name': name,
            'start': start,
            'end': end,
            'total': total
        })
    return schedules

# Uji coba 10, 30, dan 100 jadwal
def run_experiment():
    max_capacity = 50

    for size in [10]:
        print(f"UJI COBA UNTUK {size} JADWAL:")
        schedules = generate_random_schedules(size, max_capacity)
        max_profit, chosen = schedule_optimization_dp(schedules, max_capacity)
        print("Jadwal Terpilih:", chosen)
        print("Total Keuntungan Maksimal:", max_profit)

# Jalankan
run_experiment()
