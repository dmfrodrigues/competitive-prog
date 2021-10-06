def next_permutation(v):
    N = len(v)

    found_k = False
    for k in range(N-2, -1, -1):
        if v[k] < v[k+1]:
            found_k = True
            break
    if not found_k:
        v = reversed(v)
        return False

    for l in range(N-1, k, -1):
        if v[k] < v[l]:
            break

    v[l], v[k] = v[k], v[l]
    
    v[k+1:] = reversed(v[k+1:])

    return True

def assemble(v):
    ret = 0
    for d in v:
        ret = 10*ret + d
    return ret

def solution(v):
    v.sort()
    N = len(v)

    sol = 0

    for mask in range(1 << N):
        v1 = [v[i] for i in range(len(v)) if (1 << i)&mask]

        while True:
            n = assemble(v1)
            if n%3 == 0: sol = max(sol, n)
            if not next_permutation(v1): break            
    
    return sol
