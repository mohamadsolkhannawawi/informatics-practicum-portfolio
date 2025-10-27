def make_jajargenjang(a,t):
  return [a,t]

def alas(A):
  return A[0]

def tinggi(T):
  return T[1]

def luas(L):
  return alas(L)*tinggi(L)

print(luas(make_jajargenjang(5.0,6.0)))
