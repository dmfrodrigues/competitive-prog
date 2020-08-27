from random import randint
XMAX = 10000000
VMAX = 10000
R = 50000
N = 100000
T = 10
print(T)
for _ in range(T):
    print(N)
    for _ in range(N):
        print("%d %d %d"%(randint(0, XMAX), randint(0, XMAX), randint(0,VMAX)))
    print(R)
    for _ in range(R):
        print("%d %d"   %(randint(0, XMAX), randint(0, XMAX)))
