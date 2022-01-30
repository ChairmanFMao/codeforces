#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n < 3 && s != "11" && s != "00")
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
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
