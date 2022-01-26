#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Unsure of what to do... I don't yet have an idea to generate the weights
// Looked at the editorial, you need to cleverly generate all of the weights
// It works by going upwards from the root node

void solve() {
    int n;
    cin >> n;
    vector<int> b(n+1), p(n+1);
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    
    if (b[p[1]] != p[1]) {
        cout << "-1\n";
        return;
    }

    vector<int> dist(n+1, -1);
    dist[p[1]] = 0;
    for (int i = 2; i <= n; i++) {
        if (dist[b[p[i]]] == -1) {
            cout << "-1\n";
            return;
        }
        dist[p[i]] = dist[p[i-1]] + 1;
    }

    for (int i = 1; i <= n; i++)
        cout << dist[i] - dist[b[i]] << " ";
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

