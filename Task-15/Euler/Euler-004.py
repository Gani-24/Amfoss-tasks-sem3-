t=int(input())
for i in range(t):
    a=[]
    n=int(input())
    for i in range(101,993,1):
        for j in range(993,101,-1):
            if str(i*j)==str(i*j)[::-1]:
                if n>(i*j):
                    a.append(i*j)
    print(max(a))

