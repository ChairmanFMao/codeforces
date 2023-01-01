from copy import deepcopy
t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    b = deepcopy(a)

    b.sort()
    out = []
    for i in a:
        if i == b[-1]:
            out.append(i-b[-2])
        else:
            out.append(i-b[-1]);

    for i in out:
        print(i,end=" ")
    print()

