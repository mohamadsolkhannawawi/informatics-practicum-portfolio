def findAnomali(index, count_A=0, count_T=0, count_C=0, count_G=0):
    if index == n:  
        return -1  
    
    if string[index] == 'A':
        count_A += 1
    elif string[index] == 'T':
        count_T += 1
    elif string[index] == 'C':
        count_C += 1
    elif string[index] == 'G':
        count_G += 1

    if count_A < count_T or count_C < count_G:
        return index + 1  

    return findAnomali(index + 1, count_A, count_T, count_C, count_G)

string = input().strip()
n = len(string)
print(findAnomali(0))
