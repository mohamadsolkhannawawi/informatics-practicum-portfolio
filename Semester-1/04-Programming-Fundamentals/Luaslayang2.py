def make_layang2(a,t):
  return [a,t]

def diagonal1(D):
  return D[0]

def diagonal2(D):
  return D[1]

def luas(L):
  return 0.5*diagonal1(L)*diagonal2(L)

print(luas(make_layang2(4.0,6.0)))