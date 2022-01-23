#include <bits/stdc++.h>
using namespace std;
#define ll long long

// I am currently thinking of doing a breadth first search, but idk
// I made an observation that I think is correct, but I'm not sure, it wasn't correct ;-;
// Ended up looking at solution because I was kinda stumped.
// Kinda just copied most of the solution

void solve() {
    ll a, b, x;
    cin >> a >> b >> x;

    ll count;
    while (1) {
        if (a == x || b == x) {
            cout << "YES\n";
            return;
        }
        if (a < b)
            swap(a,b);
        if (b > a-b)
            b = a - b;
        if (x > max(a,b) || !a || !b)
            break;
        count = max(1ll,(a-max(b,x))/(b+b));
        a -= b * count;
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
