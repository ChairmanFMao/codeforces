
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// All of the numbers used must be distinct

vector<ll> totals, facts;
map<ll,ll> cost;

void combinations(ll subtotal, ll next, ll moves) {
    totals.push_back(subtotal);
    cost[subtotal] = moves;
    if (next == (int)facts.size()-1)
        return;
    for (int i = next+1; i < (int)facts.size(); i++) {
        combinations(subtotal + facts[i], i, moves+1);
    }
}

void solve() {
    ll n;
    cin >> n;
 
    ll small = INT_MAX;
    for (int i = 0; i < (int)totals.size(); i++)
        if (small > __builtin_popcountll(n-totals[i]) + cost[totals[i]])
            small = __builtin_popcountll(n-totals[i]) + cost[totals[i]];
    
    cout << small << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Gets all of the factorials
    facts.push_back(0);
    ll total = 1;
    for (ll i = 1; i < 16; i++) {
        total *= i;
        facts.push_back(total);
    }
    
    // Generates all of the combinations
    combinations(0,0,0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}
