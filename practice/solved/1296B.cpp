#include <bits/stdc++.h>
using namespace std;

void solve() {
    int s;
    cin >> s;
    int counter = 0;
    int mins = 1000000000;
    while (s > 0) {
        if (s/mins > 0) {
            if (mins >= 10) {
                counter += mins;
                s -= mins;
                s += mins/10;
            } else {
                counter += s;
                s = 0;
            }
        } else {
            if (mins != 1)
                mins /= 10;
        }
    }
    cout << counter << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve();
}