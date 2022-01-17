#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Somehow got WA on test 3, not really sure how
// Accepted second try, the problem was due to integer overflow, I just had to turn everything into longs

ll calcArea(ll other) {
    ll k;
    cin >> k;
    ll numbers[k];
    for (ll i = 0; i < k; i++)
        cin >> numbers[i];
    return (numbers[k-1] - numbers[0]) * other;
}

void solve() {
    ll w, h;
    cin >> w >> h;

    ll area = 0;
    for (ll i = 0; i < 4; i++)
        area = max(calcArea(i < 2 ? h : w),area);

    cout << area << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}
