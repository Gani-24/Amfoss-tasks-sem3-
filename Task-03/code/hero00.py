def calculate_max_teams(n, l):
    numofzero = l.count(0)
    if 0 in l:
        l = [x for x in l if x != 0]
        return n - numofzero
    elif len(set(l)) == n:
        return n + 1
    else:
        return n


if True:
    for i in range(int(input())):
        n = int(input())
        l = list(map(int, input().split()))
        max_teams = calculate_max_teams(n, l)
        print(max_teams)