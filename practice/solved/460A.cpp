#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int days = 0;
    for (int i = 1; n > 0; i++) {
        n--;
        if (i % m == 0)
            n++;
        days++;
    }
    cout << days;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}