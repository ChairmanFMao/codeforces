
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// I need to generate the graph and identify the components
// I think to generate the graph you need O(n^2) but, not sure
// Got a TLE due to the O(n^2) I think, could be due to the dfs, idk
// Somehow TLE on pretest 3 again, even with optimisation
// I guess the dfs is what is killing it

const int mxN = 1e5;
vector<vector<int>> adj(mxN+1);
vector<int> numbers(mxN+1), represent(mxN+1, -1);
vector<bool> used(mxN+1);
int n;

void dfs(int index, int colour) {
    represent[index] = colour;
    for (int i : adj[index])
        if (represent[i] == -1)
            dfs(i, colour);
}

void solve() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        represent[i] = -1;
        adj[i].clear();
        used[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> numbers[i];
        used[numbers[i]] = 1;
        for (int j = numbers[i]-1; j > 0; j--) {
            if (!used[j]) {
                adj[numbers[i]].push_back(j);
                adj[j].push_back(numbers[i]);
            }
        }
    }
    
    int colour = 0;
    for (int i = 1; i <= n; i++) {
        if (represent[i] == -1) {
            dfs(i,colour);
            colour++;
        }
    }
    cout << colour << "\n";
    
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
