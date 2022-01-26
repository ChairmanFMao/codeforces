
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Path to a leaf node in the tree without coming in contact with friends
// Current idea is to just find the distance of all ends using dfs
// Ended up looking at solution, we are just doing a bfs from the friends and player

void solve() {
    queue<int> processing;
    int n, k;
    cin >> n >> k;
    vector<int> colours(n+1, -1);
    for (int i = 0,a; i < k; i++) {
        cin >> a;
        processing.push(a);
        colours[a] = 0;
    }
    vector<vector<int>> adj(n+1);
    for (int i = 0,a,b; i < n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    processing.push(1);
    colours[1] = 1;

    while (!processing.empty()) {
        int current = processing.front();
        processing.pop();
        for (int i : adj[current]) {
            if (colours[i] == -1) {
                colours[i] = colours[current];
                processing.push(i);
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if ((int)adj[i].size() == 1 && colours[i] == 1) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";

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
