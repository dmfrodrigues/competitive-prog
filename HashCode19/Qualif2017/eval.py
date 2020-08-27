import sys
import os
import time

src = sys.argv[1]
app = src.replace('.cpp', '.app')
inp = sys.argv[2]
out = inp.replace('.in', '.out')

print("Compiling... ", sep='', end=''); sys.stdout.flush()
assert(os.system("g++ -Wall %s -o %s"%(src, app)) == 0)
print("Done")
print("Running... ", sep='', end=''); sys.stdout.flush()
t0 = time.perf_counter()
os.system("./%s < %s > %s"%(app, inp, out))
#os.system("./%s < %s"%(app, inp))
t1 = time.perf_counter()-t0
print("Done in %f s"%t1)


print("Getting input... ", sep='', end=''); sys.stdout.flush()
with open(inp) as f:
    c = f.readline()
    V, E, R, C, X = tuple(int(i) for i in c.strip().split(" "))
    c = f.readline()
    S = [int(i) for i in c.strip().split(" ")]
    c = f.readline()
    Ld = [0]*E
    Con = []
    for i in range(0, E):
        Ld[i], K = [int(i) for i in c.strip().split(" ")]
        c = f.readline()
        con = []
        for j in range(0, K):
            con.append(tuple([int(i) for i in c.strip().split(" ")]))
            c = f.readline()
        Con.append(con)
    Req = []
    for i in range(0, R):
        Req.append(tuple([int(i) for i in c.strip().split(" ")]))
        c = f.readline()
print("Done"); sys.stdout.flush()

print("Processing output... "); sys.stdout.flush()
with open(out) as f:
    c = f.readline()
    myC = int(c.strip())
    c = f.readline()
    assert(myC == C)
    CV = []
    for i in range(0, C):
        lst = [int(i) for i in c.strip().split(" ")]
        c = f.readline()
        assert(lst[0] == i)
        lst = lst[1:]
        CV.append(lst)
        totalSpace = sum([S[i] for i in lst])
        #print(lst)
        assert(totalSpace <= X)

    for i in range(len(CV)):
        CV[i] = set(CV[i])

    score = 0
    for t in Req:
        Rv, Re, Rn = t
        #print(Rv, Re, Rn)
        tmplst = [Ld[Re]]+[c[1] for c in Con[Re] if Rv in CV[c[0]]]
        L = min(tmplst)
        #print(L)
        saved = Ld[Re] - L
        score += Rn*saved

    totalNumReq = sum(t[2] for t in Req)
    print("SCORE in ms = %.5f"%(score/totalNumReq))
    print("SCORE as per the problem =", int(1000*score/totalNumReq))
