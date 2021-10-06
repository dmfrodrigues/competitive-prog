
T = 0; T = int(input())
vtr = [None]*(T)
for i in range(0,T):
    vtr[i] = int(input())
max_val = max(vtr)

is_cubefree = [True]*(max_val+1)
num = 2; cube = num**3
while cube < max_val+1:
    cube = num**3;
    for i in range(cube,max_val+1,cube):
        is_cubefree[i] = False
    num = num+1; cube = num**3
        
index_cubefree = [None]*(max_val+1)
index_cubefree[0] = 0
for i in range(1,max_val+1):
    index_cubefree[i] = index_cubefree[i-1]
    if is_cubefree[i]:
        index_cubefree[i] = index_cubefree[i]+1
        
for i in range(0,T):
    str = "Case %d: "%(i+1)
    if not is_cubefree[vtr[i]]:
        str = str + "Not Cube Free"
    else:
        str = str + "%d"%index_cubefree[vtr[i]]
    print(str)