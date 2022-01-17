#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int counter = 0;
    while (n != 1) {
        if (n%3 != 0) {
            cout << -1 << "\n";
            return;
        } else if(n%6 == 0) {
            n /= 6;
        } else {
            n *= 2;
        }
        counter++;
    }
    cout << counter << "\n";
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