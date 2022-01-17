#include <bits/stdc++.h>
using namespace std;

// First try, lets go! :)

void solve() {
    int n;
    cin >> n;
    int total = 0, currentLowest = 1000;
    for (int i = 0; i < n; i++) {
        int a, p;
        cin >> a >> p;
        if (p < currentLowest)
            currentLowest = p;
        total += a * currentLowest;
    }
    cout << total << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}