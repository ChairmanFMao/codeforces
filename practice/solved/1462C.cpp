#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x;
    cin >> x;
    if (x > 45) {
        cout << -1 << "\n";
        return;
    }
    int highest = 9;
    string out = "";
    for (int i = 0; x != 0; i++) {
        if (x >= highest) {
            // This means insert at index zero, there will be 1 character inserted and it will be (char) highest + 48
            out.insert(0, 1, (char) highest + 48);
            x -= highest;
            highest--;
        } else {
            out.insert(0, 1, (char) x + 48);
            x = 0;
        }
    }
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