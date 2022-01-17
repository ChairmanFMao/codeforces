#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    int rcount = 0, lcount = 0;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[n];
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (numbers[i] + numbers[j] < l)
                lcount++;
            if (numbers[i] + numbers[j] > r)
                rcount++;
        }
    }
    int out = n * n/2 - rcount - lcount;
    cout << out << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}