def pembagian(x,y):
  if (x<y):
    return 0
  else:
    return pembagian(x-y,y) + 1

print(pembagian(16,4))

