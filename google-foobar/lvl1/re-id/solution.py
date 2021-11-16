def sieve(n):
    res = []
    
    v = [1]*n
    v[0] = v[1] = 0
    for i in range(2,n):
        if v[i] == 1:
            res.append(i)
            for j in range(2*i, n, i):
                v[j] = 0

    return res

def number_digits(n):
    if(n < 0): return -1
    if(n < 10): return 1

    sz = 1
    while n >= 10:
        n //= 10
        sz += 1
    
    return sz

def to_array(n):
    sz = number_digits(n)
    ret = [0]*sz
    for i in range(sz):
        ret[i] = n%10
        n //= 10
    ret = reversed(ret)
    return ret

def solution(n):
    primes = sieve(100000)
    sz = sum([number_digits(p) for p in primes])

    arr = [0]*sz
    idx = 0
    for p in primes:
        parr = to_array(p)
        for d in parr:
            arr[idx] = d
            idx += 1
    

    ret = \
        str(arr[n  ]) + \
        str(arr[n+1]) + \
        str(arr[n+2]) + \
        str(arr[n+3]) + \
        str(arr[n+4])

    print(ret)

solution(3)
