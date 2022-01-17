#include <bits/stdc++.h>
using namespace std;
#define ll long long

// First try :)

void solve() {
    int n;
    cin >> n;
    ll pushes = 0;
    for (int i = 1; i <= n; i++) {
        pushes += i * (n - i + 1);
        if (i > 1)
            pushes -= i-1;
    }
    cout << pushes << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}