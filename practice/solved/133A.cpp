#include <bits/stdc++.h>
using namespace std;

// Problem is so mean, I got first submission wrong because one command increments the internal accumulator

void solve() {
    string p;
    cin >> p;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == 'H' || p[i] == 'Q' || p[i] == '9') {
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}