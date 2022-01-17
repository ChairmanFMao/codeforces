#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Potentially just brute force it, idk
// Failed first try due to forgetting to divide i, j and k
// Accepted second try, I just brute forced it because the bound for n was only 1000

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i <= n; i+=7) {
        for (int j = 0; i + j <= n; j+=5) {
            for (int k = 0; i + j + k <= n; k+=3) {
                if (i + j + k == n) {
                    cout << k/3 << " " << j/5 << " " << i/7 << "\n";
                    return;
                }
            }
        }
    }
    cout << -1 << "\n";
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