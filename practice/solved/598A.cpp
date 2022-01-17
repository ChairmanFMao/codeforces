#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Epicly accepted first try!

void solve() {
    ll n;
    cin >> n;

    ll two = 1;
    for (int i = 0 ; i < 30; i++)   
        two *= 2;
    
    ll sum = (n*n + n)/2;
    while (two > 1) {
        if (two <= n)
            sum -= two + two;
        two /= 2;
    }
    sum -= 2;
    cout << sum << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}