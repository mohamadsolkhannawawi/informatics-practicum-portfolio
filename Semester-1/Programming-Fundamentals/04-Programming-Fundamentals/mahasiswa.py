def make_mhs(nama,nim,ipk):
  return [nama,nim,ipk]

def nama(M):
  return M[0]

def nim(M):
  return M[1]

def ipk(M):
  return M[2]

def banyak_sks(M):
  if (ipk(M) < 2.0 ):
    return "18 SKS"
  elif (ipk(M) >= 2.0 and ipk(M) <= 2.49 ):
    return "20 SKS"
  elif (ipk(M) >= 2.55 and ipk(M) <=2.99):
    return "22 SKS"
  else:
    return "24 SKS"
 
def cek_ipk(M):
  if (ipk(M) > 3.5):
    return "TRUE"
  else :
    return "FALSE"


print(cek_ipk(make_mhs("Solkhan","24060123120020",4.00)))
