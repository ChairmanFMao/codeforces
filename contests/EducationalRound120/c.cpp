#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Watching worked solution: should just iterate how many numbers aren't copied after reducing the minimum number
// Geothermal is great!

ll fdiv(ll x, ll y) {
    return x >= 0 ? x/y : (x-y+1)/y;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    ll numbers[n];
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        sum += numbers[i];
    }
    sort(numbers,numbers+n);
    reverse(numbers,numbers+n);
    sum -= numbers[n-1];
    // We will iterate over X and test for each value of X, and if it is possible we go with it
    // window sum + (n-x) * (min-a) <= k
    // min-a <= (k - window sum) / (n-x)
    // Using this math we can find a for a given X value and from a we can calculate the number of moves required
    ll moves = 1e12;
    for (int x = 0; x < n; x++) {
        // This is the value that we need to reduce the smallest number to
        ll a = fdiv((k-sum),(x+1));
        // x is the number of copies, a is the required number and min in the minimum number in the array
        moves = min(moves, x + max(numbers[n-1] - a,(ll)0));
        sum -= numbers[x];
    }
    cout << moves << "\n";
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