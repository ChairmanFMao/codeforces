#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Got a WA on test 2
// Thought of a counter example, 11
// WA on pretest 2 again, I have no idea what the error is
// 19 is a counter example to this algorithm

// This epicly worked!

// Turns out the code timed out in reality
// I looked at the solution the day after the contest, I was very close but I should've been attempting to generate the solution in constant time, not linear time
// Turns out my code was close but just not quite there
// Accepted after I made the amendments to my code

void solve() {
    int n;
    cin >> n;

    // Trying to think of a formula that would work for odd numbers
    // This works for all odds that aren't prime
    if (n & 1) {
        if (n % 4 == 1)
            cout << n/2-1 << " " << n/2+1 << " " << 1 << "\n";
        else
            cout << n/2+2 << " " << n/2-2 << " " << 1 << "\n";
    } else {
        cout << n-3 << " " << 2 << " " << 1 << "\n";
        return;
    }
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