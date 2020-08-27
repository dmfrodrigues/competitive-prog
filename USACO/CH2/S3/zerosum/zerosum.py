"""
ID: dmfrodr1
LANG: PYTHON3
TASK: zerosum
"""

def to_base_3(N, a):
    ret = [0]*N
    for i in range(N-1,-1,-1):
        ret[i] = a%3
        a = a//3
    return ret

def get_string(N, arr):
    s = "1 2 3 4 5 6 7 8 9"
    s = list(s[0:2*N-1])
    for i in range(N-1):
        pos = 2*i+1
        if arr[i] == 0:
            s[pos] = '+'
        elif arr[i] == 1:
            s[pos] = '-'
        elif arr[i] == 2:
            s[pos] = ' '
    return "".join(s)

def to_eval(s):
    s = s.replace(' ', '')
    return s

fin = open ('zerosum.in', 'r')
fout = open ('zerosum.out', 'w')
N = int(fin.readline())
out = []
for i in range(3**(N-1)):
    arr = to_base_3(N-1, i)
    s = get_string(N, arr)
    val = eval(to_eval(s))
    if  val == 0:
        out.append(s)
out = sorted(out)
for s in out:
    fout.write(s+"\n")
fout.close()
