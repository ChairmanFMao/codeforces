t = int(input())

for _ in range(t):
    a = [int(i) for i in input().split()]

    a.sort()
    
    print(a[1])
