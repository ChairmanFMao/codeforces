#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string out = min(n,m) % 2 == 0 ? "Malvika" : "Akshat";
    cout << out;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}