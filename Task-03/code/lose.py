a, b = map(int, input().split())
t = 0

if a == b:
    print(t)
    exit()

c = b // a
if c < 2 or b % a != 0:
    print(-1)
    exit()

while c % 2 == 0:
    t += 1
    c //= 2

while c % 3 == 0:
    t += 1
    c //= 3

if c > 1:
    print(-1)
    exit()

print(t)
