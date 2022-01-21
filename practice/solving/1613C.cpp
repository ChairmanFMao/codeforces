
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN = 100;
vector<ll> numbers(mxN);
ll n, h;

bool damage(ll k) {
    ll out = 0;
    for (int i = 0; i < n-1; i++) {
        out += min(k, numbers[i+1] - numbers[i]);
    }
    out += k;
    return out >= h;
}

void solve() {
    cin >> n >> h;
    ll current;
    for (int i = 0; i < n; i++) {
        cin >> current;
        numbers[i] = current;
    }
    
    // I think binary search with just values of k
    
    unsigned ll lower = 0, upper = 1e18, mid, best = 1e18;
    while (lower <= upper) {
        mid = (lower + upper)/2;
        if (damage((ll)mid)) {
            best = min(mid,best);
            upper = mid-1;
        } else
            lower = mid+1;
    }
    cout << best << "\n";
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
