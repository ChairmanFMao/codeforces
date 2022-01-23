
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int a, b;
    cin >> a >> b;
    
    cout << min(min(a,b),(a+b)/4) << "\n";
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
