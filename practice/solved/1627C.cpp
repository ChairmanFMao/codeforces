
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// This worked and I was very happy as I came up the with solution myself

const int mxN = 1e5;
int n;
vector<vector<int>> adj(mxN+1);
vector<pair<int,int>> edges;
map<pair<int,int>, int> edgeWeights;

void dfs(int node, int prev, int prevValue) {
    for (int i : adj[node]) {
        if (i != prev) {
            pair<int,int> current;
            current.first = min(i,node);
            current.second = i+node-current.first;
            edgeWeights[current] = 5-prevValue;
            dfs(i,node,5-prevValue);
        }
    }
}

void solve() {
    for (int i = 0; i <= mxN; i++)
        adj[i].clear();
    edges.clear();
    cin >> n;
    for (int i = 0,u,v; i < n-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        pair<int,int> current;
        current.first = min(u,v);
        current.second = u+v-current.first;
        edges.push_back(current);
    }
    
    // This checks for if there are any nodes with three connections
    // That type of node would casue the program to not work.
    for (int i = 1; i <= n; i++) {
        if (3 <= (int) adj[i].size()) {
            cout << -1 << "\n";
            return;
        }
    }
    
    // Searches for a leaf node of the tree
    for (int i = 1; i <= n; i++)
        if ((int) adj[i].size() == 1) {
            dfs(i,0,2);
            break;
        }
    for (int i = 0; i < n-1; i++)
        cout << edgeWeights[edges[i]] << " ";
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}
