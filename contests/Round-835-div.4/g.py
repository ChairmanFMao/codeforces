from queue import deque

# The teleport thing is quite interesting
# just need to get to the same value as an edge with b
# got wa on test 2
# can telelport to other ones that would actually be useful
# need to do bfs from b and then get all the xor values
# runtime error on test 20
# still runtime error on test 20
# I think I need to use a bfs instead of a dfs
# This then doesn't need recursion
# This is due to the built in recursion limit python has

def solve():
    global out
    desired = set()
    n, a, b = list(map(int,input().split()))
    a -= 1; b -= 1;
    adj = [[] for i in range(n)]
    out = 0

    def bfs(node, parent, tot):
        global out
        q = deque()
        q.append((node,parent,tot))
        while len(q):
            current = q.popleft()
            if (current[2] in desired) or (current[0] == b and current[2] == 0):
                out = 1
                return;

            for u in adj[current[0]]:
                if u[0] == b and (current[2]^u[1]) != 0:
                    continue
                if u[0] != current[1]:
                    q.append((u[0],current[0],current[2]^u[1]))

    def bfs2(node, parent, tot):
        q = deque()
        q.append((node,parent,tot))
        while len(q):
            current = q.popleft()
            if current[0] != b:
                desired.add(current[2])

            for u in adj[current[0]]:
                if u[0] != current[1]:
                    q.append((u[0],current[0],current[2]^u[1]))

    for i in range(n-1):
        u, v, w = list(map(int,(input().split())))
        u -= 1; v -= 1;
        adj[u].append([v,w])
        adj[v].append([u,w])

    bfs2(b,-1,0)
    bfs(a,-1,0)

    print("YES" if out else "NO")

if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        solve()
