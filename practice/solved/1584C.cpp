
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& i : a)
        cin >> i;
    for (int& i : b)
        cin >> i;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for (int i = 0; i < n; i++) {
        if (b[i] < a[i] || b[i] > a[i] + 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
