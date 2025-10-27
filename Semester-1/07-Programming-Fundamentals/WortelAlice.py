# # alice adalah pecinta no 1 wortel. Ia selalu menjaga wortelnya agar tidak busuk di dalam penyimpanan khusus W. Namun, seringkali wortel dalam penyimpanan tersebut membusuk. Wortel dikatakan membusuk apabila nilai kesegarannya kurang dari 0. buatlah program untuk menghitung banyak wortel busuk di penyimpanan Alice.
# Input Format

# Alice(W)

# Constraints

# -100 ≤ Wi ≤ 100
# panjang W ≤ 100
# Output Format

# sebuah integer yang merupakan jumlah wortel alice yang busuk.

# Sample Input 0

# Alice([1, 2 , 0, -1, -2])
# Sample Output 0

# 2
# Explanation 0

# ada 2 wortel yang mempunyai nilai kesegaran di bawah 0 yaitu -1 dan -2

def FirstElmt(L):
    if L == [] :
        return None
    else:
        return L[0]
    
def Tail(L):
    if L == []:
        return []
    else:
        return L[1:]
    
def IsEmpty(L):
    return L == []
    
def Alice(S) :
    if IsEmpty(S) :
        return 0
    else :
        if FirstElmt(S) < 0 :
            return 1 + Alice(Tail(S))
        else :
            return Alice(Tail(S))
        
print(Alice(input()))