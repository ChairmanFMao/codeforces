#include <bits/stdc++.h>
using namespace std;
#define ll long long

// First try, WA on test 2, I was messing up the diagonals
// Second try, WA on test 2, didn't look at all the possibilities
// Acc third try! I was overcomplicating a simple problem

void solve() {
    int n, m;
    cin >> n >> m;
    bool mDiag = 0, oDiag = 0;
    int numbers[4];
    for (int i = 0; i < n; i++) {
        cin >> numbers[0] >> numbers[1] >> numbers[2] >> numbers[3];
        if (numbers[0] == numbers[3])
            mDiag = 1;
        if (numbers[1] == numbers[2])
            oDiag = 1;
    }
    if (m & 1 || !oDiag)
        cout << "NO" << "\n";
    else
        cout << "YES" << "\n";
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