
def print_op(s):
    i = next(i for i in range(len(s)) if s[i] == '+' or s[i] == '-' or s[i] == '*')
    op = s[i]
    if op == '+':
        l = s[:i]
        r = s[i+1:]
        ans = str(int(l)+int(r))
        r = op+r
        m = max([len(l), len(r), len(ans)])
        while len(l) < m:
            l = ' '+l
        while len(r) < m:
            r = ' '+r
        while len(ans) < m:
            ans = ' '+ans
        dash = ''
        while len(dash) < m:
            dash = '-'+dash
        print(l)
        print(r)
        print(dash)
        print(ans)
    elif op == '-':
        pass
    elif op == '*':
        pass


t = int(input())
for i in range(t):
    s = input()
    print_op(s)
