from time import time

# for every quest it is the same value of k
# I think that this is just a binary search basically
# Just needed to ensure that I wasn't getting O(2e5)

t = int(input())
sz = len

for _ in range(t):
    n, c, d = list(map(int,input().split()))
    a = list(map(int,input().split()))

    a.sort(reverse=True)

    prefix = [0 for i in range(sz(a)+1)]

    for i in range(1,sz(a)+1,1):
        prefix[i] = prefix[i-1] + a[i-1]

    # This caters for the edge case of infinite
    if prefix[min(d,sz(a))] >= c:
        print("Infinity")
        continue

    # This cater for the edge case of impossible
    if a[0] * d < c:
        print("Impossible")
        continue;

    # Now we can just do the binary search
    lower = 0; upper = int(2e5)+1; mid = 0; pl = -1; pu = 0;
    while lower <= upper:
        if lower == pl and upper == pu:
            break

        # There is some kind of issue here
        mid = (lower+upper)//2
        pl = lower; pu = upper
        val = prefix[min(mid,sz(a))] * (d//mid) + prefix[min(d%mid,sz(a))]
        if val >= c:
            lower = mid
        else:
            upper = mid

    print(lower-1)

