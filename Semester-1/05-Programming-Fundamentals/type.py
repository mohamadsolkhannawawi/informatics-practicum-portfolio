def titik(x,y):
  return [x,y]

def absis(P):
  return P[0]

def ordinat(P):
  return P[1]


def gradien(P1,P2): 
  return (ordinat(P2)-ordinat(P1)/absis(P2)-absis(P1))

def jarakP1(S):
  return (absis(P1)- 0)

def jarakP2(S):
  return (absis(S)-0)

def jarakdekat(P1,P2):
  if jarakP1 > jarakP2:
    return jarakP1
  else:
    return jarakP2


print(titik(gradien(5,6)))




