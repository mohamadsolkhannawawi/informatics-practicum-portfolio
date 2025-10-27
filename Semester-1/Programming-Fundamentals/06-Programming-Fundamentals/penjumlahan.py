def penjumlahan(x,y):
  if (y==0):
    return x
  else:
    return penjumlahan(x,y-1) + 1
  
print(penjumlahan(3,3))