def perkalian(x,y):
  if (y==1):
    return x
  else:
    return perkalian(x,y-1)+x
  
print(perkalian(6,6))