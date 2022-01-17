#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first and second tries due to formatting errors, it produces the right things
// Accepted third try after some debugging

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < (n-i)*2; j++)
            cout << " ";
        for (int j = 0; j < i; j++)
            cout << j << " ";
        for (int j = i; j >= 0; j--)
            j == 0 ? cout << j : cout << j << " ";
        cout << "\n";
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < (n-i)*2; j++)
            cout << " ";
        for (int j = 0; j < i; j++)
            cout << j << " ";
        for (int j = i; j >= 0; j--)
            j == 0 ? cout << j : cout << j << " ";
        cout << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}