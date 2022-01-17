#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Initially had problem with overflow, then it timed out, timed out again on third try
// Accepted on fourth try when I moved away from doing it algorithmically and made a thing that
// calculates the inconvenience in linear time.

void solve() {
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
    }
    ll extra = sum % n;
    ll inconvenience = extra * (n - extra);
    cout << inconvenience << "\n";
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