#Nama File : Mohamad Solkhan Nawawi_24060123120020_Tugas 3_C2.py
#Pembuat   : Mohamad Solkhan Nawawi - 24060123120020
#Tanggal   : 26 September 2023

# DEFINISI DAN SPESIFIKASI TYPE
# type Hero: <a : string, b : string, c : string, d : string, e : string, f : string, g : string, h : string>
# <a,b,c,d,e,f,g,h> adalah sebuah tipe data yang bertujuan untuk mendefinisikan sebuah Hero,
# a adalah nama_hero, b adalah role , c adalah specially , d adalah skill_satu , 
# e adalah skill_dua , f adalah ultimate , g adalah battle_spell, h adalah lane 

# DEFINISI DAN SPESIFIKASI KONSTRUKTOR
#MakeHero : 8 string --> Hero
#MakeHero (a,b,c,d,e,f,g,h) membentuk sebuah Hero dari a, b , c, ,d ,f , g , h dengan
# a adalah nama_hero, b adalah role , c adalah specially , d adalah skill_satu , 
# e adalah skill_dua , f adalah ultimate , g adalah battle_spell, h adalah lane
class Hero:
    def __init__(self,a,b,c,d,e,f,g,h):
        self.nama_hero = a
        self.role = b
        self.specially = c
        self.skill_satu = d
        self.skill_dua = e
        self.ultimate = f
        self.battle_spell = g
        self.lane = h
        
# DEFINISI DAN SPESIFIKASI SELEKTOR
# nama_hero : Hero ---> string
# nama_hero(ML) memberikan nama_hero di Hero Ml
def nama_hero(ML):
    return ML.nama_hero

# role : Hero ---> string
# role(ML) memberikan role di Hero Ml
def role(ML):
    return ML.role

# specially : Hero ---> string
# specially(ML) memberikan specially di Hero Ml
def specially(ML):
    return ML.specially

# skill_satu : Hero ---> string
# skill_satu(ML) memberikan skill_satu di Hero Ml
def skill_satu(ML):
    return ML.skill_satu

# skill_dua : Hero ---> string
# skill_dua(ML) memberikan skill_dua di Hero Ml
def skill_dua(ML):
    return ML.skill_dua

# ultimate : Hero ---> string
# ultimate(ML) memberikan ultimate di Hero Ml
def ultimate(ML):
    return ML.ultimate

# battle_spell : Hero ---> string
# battle_spell(ML) memberikan battle_spell di Hero Ml
def battle_spell(ML):
    return ML.battle_spell

# lane : Hero ---> string
# lane(ML) memberikan lane di Hero Ml
def lane(ML):
    return ML.lane

 
# APLIKASI
hero1 = (Hero("Alucard","Fighter/Assassin","Chase/Damage","Groundsplitter","Whirling Smash","Fision Wave","Retribution","Jungle"))
hero2 = (Hero("Fanny","Assasin","Chase/Reap","Tornado Strike","Steel Cable","Cut Throat","Retribution","Jungle"))

print(nama_hero(hero1))
print(role(hero2))
print(specially(hero1))
print(skill_satu(hero2))
print(skill_dua(hero1))
print(ultimate(hero2))
print(battle_spell(hero1))
print(lane(hero2))




