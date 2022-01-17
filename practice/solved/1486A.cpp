#include <bits/stdc++.h>
using namespace std;

// Had a problem where I was breaking out the loop and screwing up the inputs

void solve() {
    int n;
    cin >> n;
    long long blocks = 0, required = 0;
    bool good = 1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        blocks += a;
        required += i;
        if (blocks < required)
            good = 0;
    }
    string out = blocks >= required && good ? "YES" : "NO";
    cout << out << "\n";
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