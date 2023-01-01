# Either flip latest 1 or earliest 0 or just none

t = int(input())

sz = len

def calc(v):
    out = 0; zero = 0
    for i in range(sz(v)-1,-1,-1):
        if not v[i]:
            zero += 1
        else:
            out += zero
    return out

for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))

    one = -1; zero = sz(a)
    for i in range(len(a)):
        if a[i]:
            one = max(one,i)
        else:
            zero = min(zero,i)

    out = calc(a)
    if one != -1:
        a[one] = 0
        out = max(out,calc(a))
        a[one] = 1

    if zero != sz(a):
        a[zero] = 1
        out = max(out,calc(a))
        a[zero] = 0

    print(out)


