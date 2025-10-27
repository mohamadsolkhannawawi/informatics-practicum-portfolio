# Problem description
# This program tests the special floating point compare script accompanying DOMjudge.
# The problem input consists of first a line with a single integer, then that many lines,
# with on each line a floating point number (possibly also ± inf or nan). For each floating
# point number, a line should be written containing the reciprocal of the number, within
# 10−6 precision.
# Sample input/output
# Sample input and output for this problem:
# Input Output
# 8
# +0
# 1.0
# 2E0
# 3
# 4.0000000000000
# 5.0000000000001
# Inf
# nan
# inf
# 1.0
# 0.50000000001
# 3.333333333E-1
# 0.25
# 2E-1
# 0
# NaN

n = int(input().strip())
def urutanNumber(n):
    for i in range(n):
        num = input().strip()
        try:
            num = float(num)
            if num == 0:
                print(0)
            elif num == float('inf'):
                print('inf')
            elif num == float('-inf'):
                print('-inf')
            elif num == float('nan'):
                print('NaN')
            else:
                value = 1/num
                print("{:.6f}".format(value))
        except:
            print('NaN')

print(urutanNumber(n))