def max(a,b):
  return (int((a + b) + abs(a - b))/2)

def min(a,b):
  return(int((a+b) - abs(a-b))/2)

def MO(a,b,c):
  return((a+b+c) - (min(min(a,b),c))- (max(max(a,b,c))))

print(MO(1,2,3))