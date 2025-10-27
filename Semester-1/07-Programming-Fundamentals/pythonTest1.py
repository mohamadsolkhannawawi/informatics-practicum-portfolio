#Nama File : dna.py
#Pembuat   : IRVINO KENT SETIAWAN-24060123120008
#Tanggal   : 16-11-2004

# ==== DEFINISI ====
# Modul dna.py adalah bentuk realisasi dari soal-soal DNA

# ====ALGORTIMA ====

#FUNGSI LOKAL
#DEFINISI DAN SPESIFIKASI FUNGSI LOKAL
#Konso(e,L): menambahkan elemen e kepada list sebagai first elemen list
#output : List
def konso(e,L):
    if L == []:
        return [e]
    else:
        return [e] + L

#Konsi(e,L): menambahkan elemen e kepada list sebagai last elemen list
#output : List
def konsi(e,L):
    if L == []:
        return [e]
    else:
        return L + [e]

#FirstElmt(L): mengembalikan elemen pertama dari sebuah list
#output : character
def FirstElmt(L):
    if L == []:
        return None
    else:
        return L[0]

#tail(L): mengembalikan list selain first elemen list
#output : list
def tail(L):
    if L == []:
        return []
    else:
        return L[1:]

#ToString(L): mengembalikan list ke dalam bentuk string
#output : string
def ToString(L):
    return ''.join(L)

#TIPE DATA BENTUKAN DNA
#DEFINISI DAN SPESIFIKASI TIPE DATA DNA
#type DNA <a,b,c,d,e,f,g,h> merupakan type data yang terbentuk dari character entah 
# 'A', 'T', 'C', dan 'G' dimana setiap character menunjukkan sebuah neuclotide

#DEFINISI DAN SPESIFIKASI KONSTRUKTOR
#MakeDNA: 8 char --> DNA
#MakeDNA (a,b,c,d,e,f,g,h) membentuk sebuah DNA dari a sampai h dengan a sampai
# h sebagai neuclotide
def DNA (a,b,c,d,e,f,g,h):
    return [a,b,c,d,e,f,g,h]
  
#DEFINISI DAN SPESIFIKASI SELEKTOR
#nucleotideX: DNA,integer --> char
#nucleotideX(DNA,X) memberikan nucleotide DNA ke X
def nucleotideX (DNA,X):
    i = X-1
    return DNA[i]
  
#DEFINISI DAN SPESIFIKASI FUNGSI
#DNAtoRNA: DNA --> list
#DNATORNA(DNA) mengembalikan bentuk RNA dari DNA input dengan A = U, G = C, 
# C = G, dan T = A
def DNAtoRNA (DNA):
    if DNA == []:
        return []
    elif FirstElmt(DNA) == 'A':
        return konso('U',DNAtoRNA(tail(DNA)))
    elif FirstElmt(DNA) == 'G':
        return konso('C',DNAtoRNA(tail(DNA)))
    elif FirstElmt(DNA) == 'C':
        return konso('G',DNAtoRNA(tail(DNA)))
    else:
        return konso('A',DNAtoRNA(tail(DNA)))
  
#StringDNAtoRNA (DNA) mengembalikan bentuk string dari DNAtoRNA(DNA)
def StringDNAtoRNA (DNA):
    return ToString(DNAtoRNA(DNA))
  
#DNAtoBinary: DNA --> list
#DNAtoBinary(DNA) mengembalikan bentuk Binary dari DNA input dengan A = 00, G = 01, 
# C = 10, dan T = 11  
def DNAtoBinary (DNA):
    if DNA == []:
        return []
    elif FirstElmt(DNA) == 'A':
        return konso('00',DNAtoBinary(tail(DNA)))
    elif FirstElmt(DNA) == 'C':
        return konso('01',DNAtoBinary(tail(DNA)))
    elif FirstElmt(DNA) == 'G':
        return konso('10',DNAtoBinary(tail(DNA)))
    else:
        return konso('11',DNAtoBinary(tail(DNA)))
  
#StringDNAtoBinary (DNA) mengembalikan bentuk string dari DNAtoBinary(DNA)
def StringDNAtoBinary(DNA):
    return ToString(DNAtoBinary(DNA))
  
#NbNeuclotide : DNA --> integer
# NbNeuclotide(DNA) mengembalikan banyaknya neuclotide yang ada
# dan menghiraukan elemen kosong  
def NbNeuclotide(DNA):
    if DNA == []:
        return 0
    elif FirstElmt(DNA) == '':
        return NbNeuclotide(tail(DNA))
    else:
        return 1 + NbNeuclotide(tail(DNA))
  
#ManyX : DNA,char --> integer
# ManyX(DNA,X) mengembalikan banyaknya neuclotide dengan char X  
def ManyX(DNA,X):
    if DNA == []:
        return 0
    elif FirstElmt(DNA) != X:
        return ManyX(tail(DNA),X)
    else:
        return 1 + ManyX(tail(DNA),X)
  
#FrekuensiX :DNA,X --> real
# FrekuensiX(DNA,X) mengembalikan frekuensi dari banyaknya neuclotide dengan char X
# per banyaknya elemen neuclotide
def FrekuensiX(DNA,X):
    return ManyX(DNA,X) / NbNeuclotide(DNA)
  
#InversRNA : DNA --> list
# InversRNA(DNA) mengembalikan invers dari rna  
def InversRNA(DNA):
    if DNA == []:
        return []
    elif  FirstElmt(DNA) == 'A':
        return konsi('U',InversRNA(tail(DNA)))
    elif  FirstElmt(DNA) == 'C':
        return konsi('G',InversRNA(tail(DNA)))
    elif  FirstElmt(DNA) == 'G':
        return konsi('C',InversRNA(tail(DNA)))
    else:
        return konsi('A',InversRNA(tail(DNA)))
  
#InversBinary : DNA --> list
# InversBinary(DNA) mengembalikan invers dari binary 
def InversBinary(DNA):
    if DNA == []:
        return []
    elif FirstElmt(DNA) == 'A':
        return konsi('00',InversBinary(tail(DNA)))
    elif FirstElmt(DNA) == 'C':
        return konsi('01',InversBinary(tail(DNA)))
    elif FirstElmt(DNA) == 'G':
        return konsi('10',InversBinary(tail(DNA)))
    else:
        return konsi('11',InversBinary(tail(DNA)))
  
#UpdateXtoY : DNA,X,Y --> DNA
# UpdateXtoY(DNA,X,Y) menggantikan elemen X dengan Y  
def UpdateXtoY(DNA,X,Y):
    if DNA == []:
        return []
    elif FirstElmt(DNA) == X:
        return konso(Y,UpdateXtoY(tail(DNA),X,Y))
    else:
        return konso(FirstElmt(DNA),UpdateXtoY(tail(DNA),X,Y))
  
# ====APLIKASI ====
print(DNA('A','C','G','T','T','C','G','T'))
print(nucleotideX(DNA('A','C','G','T','T','C','G','T'),1))
print(DNAtoRNA(DNA('A','C','G','T','T','C','G','T')))
print(StringDNAtoRNA(DNA('A','C','G','T','T','C','G','T')))
print(DNAtoBinary(DNA('A','C','G','T','T','C','G','T')))
print(StringDNAtoBinary(DNA('A','C','G','T','T','C','G','T')))
print(NbNeuclotide((DNA('','C','','T','T','C','G','T'))))
print(ManyX((DNA('A','C','C','T','T','C','G','T')),'T'))
print(FrekuensiX((DNA('A','C','C','T','T','C','G','T')),'T'))
print(InversRNA(DNA('A','C','G','T','T','C','G','T')))
print(InversBinary(DNA('A','C','G','T','T','C','G','T')))
print(UpdateXtoY(DNA('A','C','G','T','T','C','G','T'),'T','B'))

# ==== SOAL BONUS ====