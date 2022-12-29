def sum(x):
    result = x*(x+1)//2
    return result
t = int(input())
for i in range(t):
    n = int(input())
    a = (n-1) // 3
    b = (n-1) // 5
    c = (n-1) // 15
    print(3*sum(a) + 5*sum(b) - 15*sum(c))