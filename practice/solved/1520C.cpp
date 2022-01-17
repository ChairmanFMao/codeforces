#include <bits/stdc++.h>
using namespace std;
#define ll long long

// First try :))))

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << -1 << "\n";
        return;
    }
    int numbers[n];
    for (int i = 0; i <= n; i++)
        numbers[i] = i * n + 1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n + i; j++) {
            cout << numbers[j%n] + i << " ";
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