#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Done epicly using maths, completed first try! :)

void solve() {
    int a;
    cin >> a;
    double number = ((double) 360 / (180 - a));
    string out = abs(number - (int) number) < 1e-9 ? "YES" : "NO";
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