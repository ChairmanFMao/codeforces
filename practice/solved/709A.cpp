#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first time due to a silly mistake; had a condition that was && instead of seperate ;-;

void solve() {
    int n, b, d;
    cin >> n >> b >> d;
    int waste = 0, current = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a <= b)
            current += a;
        if (current > d) {
            waste++;
            current = 0;
        }
    }
    cout << waste << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}