def solve(N, v):
    N += 10
    L = len(v)
    vn = [int(0)]*(L+1)

    for n in range(2, N+1):
        if v[0]%n == 0:
            vn[0] = n
    
    for i in range(L):
        n = v[i]//numv[i]
        numv[i+1] = n; s.add(n)
    print(list(s), numv)
    s = list(s)
    s.sort()

    if len(s) != 26: return "LOL2"

    cr = 'A'
    m = {}
    for i in s:
        m[int(i)] = cr
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
