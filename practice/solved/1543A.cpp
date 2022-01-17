#include <bits/stdc++.h>
using namespace std;

// Third first try in a row :))))))))))

void solve() {
    long long a, b;
    cin >> a >> b;
    long long excitement = max(a,b) - min(a,b);
    if (excitement == 0) {
        cout << 0 << " " << 0 << "\n";
        return;
    }
    long long moves = 0;
    if (a % excitement != 0 && b % excitement != 0)
        moves = min(a % excitement, excitement - a % excitement);
    cout << excitement << " " << moves << "\n";
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