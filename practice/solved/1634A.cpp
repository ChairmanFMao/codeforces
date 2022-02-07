#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Just be careful about edge cases, they waste time and screw you over.

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    string copy = s;
    reverse(copy.begin(),copy.end());
    cout << (k >= 1 && copy != s ? 2 : 1) << "\n";
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
