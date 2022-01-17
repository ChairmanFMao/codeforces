#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    char number = '9';
    string out = "";
    if (n >= 1) {
        out += '9';
    } if (n >= 2) {
        out += '8';
    }
    for (int i = 0; i < n - 2; i++) {
        out += number;
        number++;
        if (number == 58)
            number = 48;
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