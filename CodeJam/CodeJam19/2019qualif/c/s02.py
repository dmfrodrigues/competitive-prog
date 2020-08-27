import math

def solve(N, v):

    N += 10
    L = len(v)
    numv = [int(0)]*(L+1)

    s = set()
    for i in range(L-1):
        if v[i] != v[i+1]:
            B = math.gcd(v[i], v[i+1])
            A = v[0]//B
            numv[0] = A
            s.add(A)
            break

    for i in range(L):
        n = v[i]//numv[i]
        numv[i+1] = n; s.add(n)

    s = list(s)
    s.sort()
    if len(s) != 26: return "LOL2"

    cr = 'A'
    m = {}
    for i in s:
        m[i] = cr
        cr = chr(ord(cr)+1)

    ret = ""
    for i in numv:
        ret += m[i]
    return ret


T = int(input())
for t in range(T):
    N,L = [int(s) for s in input().split(" ")]
    v = [int(s) for s in input().split(" ")]
    ans = solve(N, v)
    print("Case #%d: %s"%(t+1, ans))
