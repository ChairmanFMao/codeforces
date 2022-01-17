#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Watched Geothermal tutorial for this problem

vector<ll> numbers;
int n;

bool check(ll desired) {
    // We make a temporary copy of numbers which we can freely alter
    vector<ll> altered = numbers;
    // We are traversing the vector from back to front here
    for (int i = n-1; i >= 2; i--) {
        if (altered[i] < desired)
            return 0;
        // This min condition needs to be here so that the stones total doesn't go negative
        ll extra = min(altered[i] - desired, numbers[i]);
        // This adds the extra stones to the piles behind
        altered[i-1] += extra / 3;
        altered[i-2] += (extra / 3) * 2;
    }
    return min(altered[0], altered[1]) >= desired;
}

void solve() {
    numbers.clear();
    cin >> n;
    for (int i = 0,a; i < n; i++) {
        cin >> a;
        numbers.push_back(a);
    }

    ll lower = 0, upper = 1e10;
    while (lower < upper) {
        ll mid = (lower + upper + 1) / 2;
        if (check(mid))
            lower = mid;
        else
            upper = mid-1;
    }
    cout << lower << "\n";
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