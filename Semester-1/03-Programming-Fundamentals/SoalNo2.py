def ubah(x):
  if x == "A":
    return 4
  elif x == "B":
    return 3
  elif x == "C":
    return 2
  elif x == "D":
    return 1
  else:
    return 0
  
def rata2(a,b,c,d,e):
  return((ubah(a)*3 + ubah(b)*3 + ubah(c)*3 +ubah(d)*3 + ubah(e)*3)/5)

def beasiswa(semester,status,a,b,c,d,e):
  if (semester )