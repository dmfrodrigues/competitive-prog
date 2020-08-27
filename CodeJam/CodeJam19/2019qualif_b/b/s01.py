import numpy

A = numpy.matrix([[2,1,1,1,1,1],
                  [4,2,1,1,1,1],
                  [8,2,2,1,1,1],
                  [16,4,2,2,1,1],
                  [32,4,2,2,2,1],
                  [64,8,4,2,2,2]])
A_ = numpy.linalg.inv(A)


Y = numpy.matrix([[0],
                  [0],
                  [0],
                  [0],
                  [0],
                  [0]])

s = input()
s = s.split()
T,W = int(s[0]),int(s[1])

for t in range(T):
    print(1); Y[0,0] = int(input())
    print(2); Y[1,0] = int(input())
    print(3); Y[2,0] = int(input())
    print(4); Y[3,0] = int(input())
    print(5); Y[4,0] = int(input())
    print(6); Y[5,0] = int(input())
    X = numpy.matmul(A_,Y)
    for i in range(6):
        X[i,0] = X[i,0]+0.5
    X = X.astype(int)
    print(X[0,0], end = '')
    for i in range(1,6):
        print(' ',X[i,0], sep='',end = '')
    print()
