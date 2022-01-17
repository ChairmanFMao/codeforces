#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    int first;
    cin >> first;
    int big = first, small = first;
    for (int i = 0,a; i < n-1; i++) {
        cin >> a;
        if (a > big)
            big = a;
        if (a < small)
            small = a;
    }

    cout << big - small << "\n";

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
