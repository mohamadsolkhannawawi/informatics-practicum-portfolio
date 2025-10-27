def activity_selection(activities):
    # Diurutkan berdasarkan waktu selesai
    sorted_activities = sorted(activities, key=lambda x: x[1])
    
    # List untuk menyimpan aktivitas yang dipilih
    selected = []
    
    # Waktu selesai dari aktivitas terakhir yang dipilih
    last_end_time = 0
    
    for activity in sorted_activities:
        start, end = activity
        if start >= last_end_time:
            selected.append(activity)
            last_end_time = end
    
    return selected 

activities = [(1, 3), (2, 6), (5, 7), (8, 9)]
result = activity_selection(activities)
print("Aktivitas yang dipilih:", result)
