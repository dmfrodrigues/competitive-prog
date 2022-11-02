def process(s):
    while True:
        a = s.find('#')
        if a == -1: return s
        else:
            if a == 0:
                s = s[1:]
            else:
                s = s[0:a-1] + s[a+1:]

s = input()
t = input()
s = process(s)
t = process(t)
print(s == t)
