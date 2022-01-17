#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try! Lets gooooo!

void solve() {
    int n;
    cin >> n;
    int start = 0, number = 1;
    while (start < n) {
        start = (double) 3/2 * number * number + (double) 1/2 * number;
        number++;
    }
    int tri = 0;
    while (n > 0) {
        if ((double) 3/2 * number * number + (double) 1/2 * number > n)
            number--;
        else if (n < 2)
            break;
        else {
            tri++;
            n -= (int) ((double) 3/2 * number * number + (double) 1/2 * number);
        }
    }
    cout << tri << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}