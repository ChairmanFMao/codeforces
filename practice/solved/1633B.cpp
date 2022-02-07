
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s;
    cin >> s;
    int one = 0, zero = 0;
    for (char c : s) {
        if (c == '1')
            one++;
        else
            zero++;
    }
    
    if (one == zero)
        cout << one-1 << "\n";
    else
        cout << min(one,zero) << "\n";
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
