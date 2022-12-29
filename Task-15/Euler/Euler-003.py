t = int(input())
for i in range(t):
    n = int(input())
    while n % 2 == 0:
        p_factor = 2
        n = n//2
    for i in range(3,int(n**(0.5))+1,2):
        while n % i == 0:
            p_factor = i
            n = n//i
    if n > 2:
        p_factor = n
    print(p_factor)