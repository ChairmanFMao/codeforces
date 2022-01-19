
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// I failed this the first time because there were some intermediary steps that overflowed the ll cap

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> visits(n);
    for (ll i = 0,a; i < n; i++) {
        cin >> a;
        visits[i] = {a,i};
    }
    
    sort(visits.rbegin(),visits.rend());
    // We will have the midpoint be at 0 for x0
    map<ll,ll> locations;
    
    ll time = 0;
    for (ll i = 0; i < n; i++) {
        if (i & 1) {
            locations[visits[i].second] = (-i-1) / 2;
            time += (i+1) * visits[i].first;
        } else {
            locations[visits[i].second] = (i / 2) + 1;
            time += (i+2) * visits[i].first;
        }
    }
    
    // This is due to the midpoint always being 0
    cout << time << "\n" << 0 << " ";
    for (ll i = 0; i < n; i++)
        cout << locations[i] << " ";
    cout << "\n";
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
