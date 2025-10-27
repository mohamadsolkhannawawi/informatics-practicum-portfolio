# Fungsi untuk membuat complementary strand secara manual tanpa dictionary
def complementary_strand_manual(dna):
    result = ""  
    i = 0
    while i < len(dna):  
        base = dna[i]
        if base == 'A':
            result = result + 'T'
        elif base == 'T':
            result = result + 'A'
        elif base == 'C':
            result = result + 'G'
        elif base == 'G':
            result = result + 'C'
        i += 1  
    return result

# Fungsi untuk menghitung kecocokan maksimal secara manual
def max_match_manual(human_dna, virus_dna):
    virus_comp = complementary_strand_manual(virus_dna)

    virus_length = 0
    for _ in virus_dna:  # Hitung panjang virus DNA manual
        virus_length += 1

    human_length = 0
    for _ in human_dna:  # Hitung panjang DNA manusia manual
        human_length += 1

    i = 0
    max_match = 0
    while i <= (human_length - virus_length):  
        match_count = 0  
        j = 0
        while j < virus_length:  
            if human_dna[i + j] == virus_comp[j]:  
                match_count += 1
            j += 1

        if match_count > max_match:  
            max_match = match_count
        i += 1  

    return max_match

# Fungsi utama sesuai format input-output yang diminta
def diagnose_manual():
    human_dna = input().strip()  # Baca input DNA manusia
    virus_dna = input().strip()  # Baca input DNA virus
    
    max_match = max_match_manual(human_dna, virus_dna)

    # Hitung persentase kecocokan secara manual
    virus_length = 0
    for _ in virus_dna:
        virus_length += 1

    match_percentage = (max_match * 100) / virus_length

    if match_percentage >= 50:
        print("Terinfeksi")
    else:
        print("Tidak Terinfeksi")
    
    print(max_match)  # Cetak jumlah kecocokan maksimal

# Menjalankan fungsi utama
diagnose_manual()
