#include <bits/stdc++.h>
using namespace std;

// Completed on laptop, this is a directed graph question btw
// Redid this question a while later as it always bugged me how
// inefficient my solution was at that time

const int mxN = 2000;
vector<int> adj(mxN+1);

int dfs(int a) {
    if (adj[a] == 0)
        return 1;
    return dfs(adj[a]) + 1;
}

void solve() {
    int n;
    cin >> n;
    
    for (int i = 0,a; i < n; i++) {
        cin >> a;
        if (a != -1)
            adj[i+1] = a;
    }
    int out = 0;
    for (int i = 1; i <= n; i++)
        out = max(out,dfs(i));
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}