INF = 1e60

def value(c):
    if ord('A') <= ord(c) and ord(c) <= ord('Z'): return 10 + (ord(c)-ord('A'))
    else: return ord(c)-ord('0')

def subsolve(b, s, c):
    bigNumber = s[c+1] + s[0:c] + s[c+2:] + s[c]
    smallNumber = bigNumber[::-1]
    bigNumber   = int(bigNumber  , base=b)
    smallNumber = int(smallNumber, base=b)
    return bigNumber-smallNumber

def solve(b, s):
    diff = INF
    candidates = []
    for i in range(len(s)-1):
        delta = value(s[i+1])-value(s[i])
        if delta < diff:
            diff = delta
            candidates = [i]
        elif delta == diff:
            candidates.append(i)
    ret = INF
    for c in candidates:
        ret = min(ret, subsolve(b, s, c))
    return ret

N = int(input())
for n in range(N):
    line = input().split(" ")
    b = int(line[0])
    s = line[1]
    s = ''.join(sorted(s))
    print(solve(b, s))
