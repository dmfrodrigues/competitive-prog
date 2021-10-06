def getbin(num):
    lst = []
    while num != 0:
        lst.append(num%2)
        num = num//2
    return lst

def mylog2(num):
    ret = 0
    while num != 0:
        ret = ret+1
        num = num//2
    return ret-1

def solve(num):
    ret = mylog2(num+1)
    num = num - 2**ret + 1
    
    num_bin = getbin(num)
    ret = ret + num_bin.count(1)
    
    return ret
    
C = 0; C = int(input())
in_num = [None]*C
for i in range(0,C):
    in_num[i] = int(input())
solutions = [None]*C
for i in range(0,C):
    solutions[i] = solve(in_num[i])
for i in range(0,C):
    print(solutions[i])
