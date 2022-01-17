#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first time, WA test 3, bad algorithm
// Failed second time, WA test 15, forgot an edge case
// Accepted third try!

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    if (a < (double)b/m) {
        cout << a * n << "\n";
        return;
    }
    
    int out = min((n/m) * b +  (n % m) * a, ((n/m)+1) * b);
    cout << out << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}