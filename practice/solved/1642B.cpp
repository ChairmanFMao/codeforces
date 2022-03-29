
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    set<int> keys;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        keys.insert(a);
    }
    
    int running = (int)keys.size();
    for (int i = 1; i <= n; i++) {
        cout << max(i,running) << " ";
    }
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
