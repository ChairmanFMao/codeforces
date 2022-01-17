#include <bits/stdc++.h>
using namespace std;

// Accepted first time :)))))))))

void solve() {
    int n, d;
    cin >> n >> d;
    int mins = 0, jokes = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mins += a;
        if (i != n - 1) {
            mins += 10;
            jokes += 2;
        }
    }
    if (mins > d) {
        cout << -1 << "\n";
        return;
    }
    jokes += (d - mins) / 5;
    cout << jokes << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}