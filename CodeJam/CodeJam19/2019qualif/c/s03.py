import math

def isqrt(n):
    x = n
    y = (x + 1) // 2
    while y < x:
        x = y
        y = (x + n // x) // 2
    return x

def solve(N, v):
    L = len(v)
    vn = [int(0)]*(L+1)
    for i in range(0, L-1):
        if(v[i] == v[i+1]):
            vn[i+1] = isqrt(v[i])
        else:
            vn[i+1] = math.gcd(v[i], v[i+1])
    vn[0] = v[0]//vn[1]
    vn[-1] = v[-1]//vn[-2]

    s = list(set(vn))
    s.sort()

    cr = 'A'
    m = {}
    for i in s:
        m[i] = cr
        cr = chr(ord(cr)+1)

    ret = ""
    for i in vn:
        ret += m[i]
    return ret

T = int(input())
for t in range(T):
    N,L = [int(s) for s in input().split(" ")]
    v = [int(s) for s in input().split(" ")]
    ans = solve(N, v)
    print("Case #%d: %s"%(t+1, ans))
