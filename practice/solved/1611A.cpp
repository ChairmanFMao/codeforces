
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string n;
    cin >> n;

    bool odd = 1;
    for (int i = 0; i < (int) n.size(); i++)
        if (n[i] % 2 == 0)
            odd = 0;
    
    if (odd) {
        cout << "-1\n";
        return;
    }

    if (n[n.size()-1] % 2 == 0)
        cout << 0 << "\n";
    else if (n[0] % 2 == 0)
        cout << 1 << "\n";
    else
        cout << 2 << "\n";
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
