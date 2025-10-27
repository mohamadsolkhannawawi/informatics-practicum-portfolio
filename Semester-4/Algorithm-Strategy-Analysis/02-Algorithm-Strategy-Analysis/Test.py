def createPermutasi(urutan, sisa, N): # semua permutasi yang mungkin, dibuat dulu
    if len(urutan) == N: # jika sudah sepanjang N cek apakah zigzag
        if cekZigZag(urutan):
            print("".join(map(str, urutan)))  
        return
    
    for angka in sisa:
        sisa_baru = sisa[:] # Masukkan sisa ke variabel baru
        sisa_baru.remove(angka) # Hapus setiap angka yang sudah digunakan  
        createPermutasi(urutan + [angka], sisa_baru, N) #Rekursi ke sisa yang baru

def cekZigZag(urutan):
    for i in range(1, len(urutan) - 1): #Mulai dari 1 karena , langsung mencari tengah
        kiri, tengah, kanan = urutan[i-1], urutan[i], urutan[i+1]
        if not ((tengah > kiri and tengah > kanan) or (tengah < kiri and tengah < kanan)): # Jika tidak zigzag = false
            return False  
    return True #jika memenuhi True

# Input & Mulai Rekursi
N = int(input().strip())
angka = list(range(1, N + 1))
createPermutasi([], angka, N)
