#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Make sure to look at the problem constraints, if there is an easier way (i.e. brute force lol)

ll powers(ll num) {
    ll out = 0;
    while (!(num & 1)) {
        out++;
        num >>= 1;
    }
    return out;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> numbers(n);
    vector<ll> stripped(n);
    ll original = 0;
    for (ll& i : numbers) {
        cin >> i;
        original += i;
    }
    
    ll pow = 0;
    for (int i = 0; i < n; i++) {
        ll down = powers(numbers[i]);
        stripped[i] = numbers[i] >> down;
        pow += down;
    }
    
    ll temp = 0;
    for (int i = 0; i < n; i++) {
        temp = stripped[i] << pow;
        for (int j = 0; j < n; j++) {
            if (j == i)
                continue;
            temp += stripped[j];
        }
        original = max(original, temp);
    }

    cout << original << "\n";
    
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
 