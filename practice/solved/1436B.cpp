#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Used the solution heavily for this problem
// Accepted first try

void solve() {
    int n;
    cin >> n;
    // Should've thought about zero, silly mistake
    vector<vector<int>> numbers(n);

    for (int i = 0; i < n; i++)
        numbers[i].resize(n,0);
    for (int i = 0; i < n; i++) {
        numbers[i][i] = 1;
        numbers[n-i-1][i] = 1;
    }

    // I get how this works, just draw a 5x5 grid and evaluate it if you want to understand it
    if (n & 1) {
        numbers[n/2-1][n/2] = 1;
        numbers[n/2][n/2+1] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << numbers[i][j] << " ";
        }
        cout << "\n";
    }
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
