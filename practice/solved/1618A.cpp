
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int b[7];
    for (int i = 0; i < 7; i++)
        cin >> b[i];
    
    cout << b[0] << " " << b[1] << " " << b[6]-b[1]-b[0] << "\n";
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
