t = int(input())

for _ in range(t):
    n = int(input())
    a = [int(1e10)]
    b = list(map(int,input().split()))
    for i in range(len(b)):
        if i+1 < len(b) and b[i] == b[i+1]:
            continue
        a.append(b[i])

    a.append(int(1e10))

    out = 0
    for i in range(1,len(a)-1):
        if a[i] < a[i-1] and a[i] < a[i+1]:
            out += 1

    print("YES" if out <= 1 else "NO")

