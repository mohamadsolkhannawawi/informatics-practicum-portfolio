def pengurangan(x,y):
  if (y == 0):
    return x
  else:
    return pengurangan(x,y-1)-1
  
print(pengurangan(6,3))