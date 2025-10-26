# #Deretint:integer --> integer
# #{Deretint(n) mengembalikan jumlah deret integer
# # Deretint(6) = 1+2+3+4+5+6 , output 21}
# #Realisasi dalam python

# def DeretInt(n):
#   if n == 0 :
#     return 0
#   elif n == 1:
#     return 1
#   else :
#     return n + DeretInt(n-1)
  

# print(DeretInt(3))
# print(DeretInt(6))
# print(DeretInt(12))

# def Deretbeda3(n):
#   if n == 0 :
#     return 0
#   elif n == 1 :
#     return 3
#   else:
#     return n*3 +Deretbeda3(n-1)
  
# print(Deretbeda3(2))
# print(Deretbeda3(3))

# def Deretgeo3(n):
#   if n == 0 :
#     return 0
#   elif n == 1 :
#     return 1
#   else :
#     return 3**(n) + Deretgeo3(n-1)
  
# print(Deretgeo3(3))

# def DeretInt(n):
#   if n == 0 :
#     return 0
#   # elif n == 1:
#   #   return 1
#   else :
#     return n + DeretInt(n-1)
  
# print(DeretInt(1))

def Deretgeo3(n):
  if n == 0 :
    return 0
  # elif n == 1 :
  #   return 1
  else :
    return 3**(n-1) + Deretgeo3(n-1)
  
print(Deretgeo3(2))
print(Deretgeo3(3))
print(Deretgeo3(4))