#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Made a brute force algorithm but, it is just really slow
// Had to look at a solution on geeks for geeks as I didn't really know what to do
// Just used a binary search from the middle element possible for ints to each side, if the times is lower or greater
// Accepted first try!

void solve() {
    ll n, k;
    cin >> n >> k;

    // Create the variables for the lower and upper bounds of the binary search
    ll lower = 1, upper = INT_MAX, out = 0, mid, times;
    while (lower <= upper) {
        // Gets the midpoint of the bounds
        mid = (lower + upper) / 2;
        // Gets the number that mid would be of numbers not divisible by k
        times = mid - mid/n;
        // Changes the bounds depending of the value of times
        if (times > k)
            upper = mid-1;
        else if (times < k)
            lower = mid+1;
        // If k == times then, it will decrement upper and set the current answer as mid, as there may be a better solution that is lower
        else {
            out = mid;
            upper = mid-1;
        }
    }
    cout << out << "\n";
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