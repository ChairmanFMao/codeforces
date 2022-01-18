
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m;
    cin >> n >> m;

    // Need to paint the seats with the lowest overall manhattan distance
    // Need rahul to take the seat with the lowest remaining manhattan distance
    // Need Tina to take the seat with the largest manhattan distance from rahul
    // Potentially big grid size, so manually generating mahattan is a bad idea
    // Looked at solution as I was kinda stuck
    vector<ll> distances(n*m);
    ll ptr = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            distances[ptr] = max(j,m-j-1) + max(i,n-i-1);
            ptr++;
        }
    }
    sort(distances.begin(),distances.end());
    for (ll i : distances)
        cout << i << " ";
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
