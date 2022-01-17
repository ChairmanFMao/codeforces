#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int players[k];
    for (int i = 0; i < k; i++)
        players[i] = 0;
    int cards = n/k;
    players[0] += min(m, cards);
    m -= min(m, cards);
    int rounds = 0;
    while (m > 0) {
        for (int i = 1; i < k; i++) {
            players[i]++;
            m--;
        }
        rounds++;
    }
    cout << players[0] - rounds << "\n";
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