
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Very simple, just checking if an array is sorted

void solve() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int& i : numbers)
        cin >> i;

    for (int i = 1; i < n; i++) {
        if (numbers[i-1] > numbers[i]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
