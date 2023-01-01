t = int(input())

for _ in range(t):
    n = int(input())
    s = input()

    biggest = 0
    for c in s:
        biggest = max(ord(c)-96,biggest)

    print(biggest)

