def get_generous(N):
    ret = 0
    while N >= (1<<ret)-1:
        ret += 1
    return ret-1

def get_stingy(N):
    if N <= 1: return 1
    if N <= 2: return 2
    
    a, b = 1, 1
    N -= 2
    ret = 2

    while N >= 0:
        c = a+b
        N -= c
        a, b = b, c
        ret += 1

    return ret-1

def solution(N):
    a = get_generous(N)
    b = get_stingy(N)
    return b-a
