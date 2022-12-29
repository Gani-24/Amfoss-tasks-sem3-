def fibbo(n):
    f2 = 1
    f1 = 1
    sum = 0
    while True :
        fn = f2 + f1
        if fn >= n:
            return sum
        if fn % 2 == 0:
            sum += fn
        f2, f1 = f1, fn

t = int(input().strip())
for i in range(t):
    n = int(input().strip())
    print(fibbo(n))