#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try!
// First of the 1200 grind on pc

void solve() {
    int n;
    cin >> n;
    int boys[n];
    for (int i = 0; i < n; i++)
        cin >> boys[i];
    int m;
    cin >> m;
    int girls[m];
    for (int i = 0; i < m; i++)
        cin >> girls[i];

    sort(boys, boys+n);
    sort(girls, girls+m);
    int pairs = 0, bptr = 0, gptr = 0;
    while (bptr < n && gptr < m) {
        if (abs(boys[bptr] - girls[gptr]) <= 1) {
            pairs++;
            bptr++;
            gptr++;
        } else if (boys[bptr] < girls[gptr])
            bptr++;
        else if (girls[gptr] < boys[bptr])
            gptr++;
    }
    cout << pairs << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}