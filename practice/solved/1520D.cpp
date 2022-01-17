#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Implemented a really bad O(n^2) algorithm, thinking about how to make a more efficient algorithm
// Failed first try, as expected the algorithm timed out on test 5
// Spent a long time thinking but, didn't know what to do, so looked at solution
// Very interesting solution, should've thought about rearranging the equation
// Failed second try, WA test 2, due to bad algorithm
// Failed third try, WA test 5, due to integer overflow
// Accepted fourth try!

void solve() {
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    set<ll> unique;
    map<ll, ll> weights;
    ll out = 0;
    for (ll i = 0; i < n; i++) {
        if (unique.count(numbers[i]-i)) {
            weights[numbers[i]-i]++;
            out += weights[numbers[i]-i];
        }
        unique.insert(numbers[i]-i);
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