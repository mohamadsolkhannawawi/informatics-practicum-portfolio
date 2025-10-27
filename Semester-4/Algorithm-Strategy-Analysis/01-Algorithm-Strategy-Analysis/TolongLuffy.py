def TolongLuffy(N, K, A):
    if (K == 0) :
        return f'"Luffy Kalah"'
    elif (K > N) :
        return f'"Banyaknya benteng tidak cukup dengan yang dibutuhkan"'
    else :
        max_sum = sum(A[:K])
        current_sum = sum(A[:K])
        for i in range(1, N-K+1):
            current_sum = current_sum - A[i-1] + A[i+K-1]
            max_sum = max(max_sum, current_sum)
        return max_sum
    
N = int(input())
K = int(input())
A = list(map(int, input().split(",")))
print(TolongLuffy(N, K, A))