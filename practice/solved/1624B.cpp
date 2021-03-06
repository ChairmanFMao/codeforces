#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll a,b,c;
    cin >> a >> b >> c;
    
    int ac = c-a, ab = b-a, bc = c-b;
    
    if (((b + ab) % c == 0 && b+ab>0) || ((b-bc) % a == 0 && b-bc>0) || ((a+ac/2) % b == 0 && ac % 2 == 0))
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
