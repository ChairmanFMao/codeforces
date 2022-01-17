#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, WA test 3 due to not accounting for all zero coins
// Accepted second try

void solve() {
    int c[5], all = 0;
    for (int i = 0; i < 5; i++) {
        cin >> c[i];
        all += c[i];
    }
    int out = all % 5 == 0 && all > 0 ? all/5 : -1;
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}