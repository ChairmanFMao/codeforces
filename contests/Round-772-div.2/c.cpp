
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Get it in ascending order

void solve() {
    int n;
    cin >> n;
    vector<ll> numbers(n);
    for (ll& i : numbers)
        cin >> i;

    ll prev = -1e9;
    bool asc = 1;
    for (int i = 0; i < n; i++) {
        if (numbers[i] < prev)
            asc = 0;
        prev = numbers[i];
    }

    if (asc) {
        cout << 0 << "\n";
        return;
    }
    
    ll diff = numbers[n-2] - numbers[n-1];
    if (diff > numbers[n-2] || diff > numbers[n-1] || numbers[n-2] > numbers[n-1]) {
        cout << -1 << "\n";
        return;
    }
    
    cout << n-2 << "\n";
    for (int i = 1; i < n-1; i++) {
        cout << i << " " << n-1 << " " << n << "\n";
    }
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

