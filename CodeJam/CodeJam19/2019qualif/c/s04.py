from math import gcd

def solve(N, v):
    N += 10
    L = len(v)
    vn = [int(0)]*(L+1)

    for i in range(0, L-1):
        if v[i] != v[i+1]:
            n = i+1
            vn[n] = gcd(v[i], v[i+1])
            break

    for i in range(n-1, -1, -1):
        vn[i] = v[i]//vn[i+1]
    for i in range(n+1, L+1):
        vn[i] = v[i-1]//vn[i-1]

    s = list(set(vn))
    s.sort()

    cr = 'A'
    m = {}
    for i in s:
        m[int(i)] = cr
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
