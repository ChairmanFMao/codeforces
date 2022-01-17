#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, WA test 9, forgot to do abs value on line 17
// Failed second try, WA test 12, had order wrong for one the test cases
// Accepted third try!

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // Possible cases: diagonal line -> fail, two corners -> good, two side points -> good
    if (x1 == x2)
        cout << x1 + y2 - y1 << " " << y1 << " " << x2 + y2 - y1 << " " << y2 << "\n";
    else if (y1 == y2)
        cout << x1 << " " << y1 + x2 - x1 << " " << x2 << " " << y2 + x2 - x1 << "\n";
    else if (abs(x2 - x1) == abs(y2 - y1))
        cout << x1 << " " << y2 << " " << x2 << " " << y1 << "\n";
    else
        cout << -1 << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}