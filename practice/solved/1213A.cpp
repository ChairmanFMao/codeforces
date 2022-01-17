#include <bits/stdc++.h>
using namespace std;

// First try again :))

void solve() {
    int n;
    cin >> n;
    int odd = 0, even = 0;
    set<int> occupied;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (occupied.count(a) == 0) {
            if (a & 1)
                odd++;
            else
                even++;
        }
    }
    cout << min(odd, even) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}