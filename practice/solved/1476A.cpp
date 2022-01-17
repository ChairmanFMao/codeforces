#include <bits/stdc++.h>
using namespace std;
#define ll long long

// First time wrong due to cout precision for doubles being too low
// Accepted second try

void solve() {
    int n, k;
    cin >> n >> k;
    if (n > k)
        k = ceil((double) n / k) * k;
    cout.precision(30);
    cout << ceil((double) k / n) << "\n";
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