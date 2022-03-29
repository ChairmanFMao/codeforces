
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, x;
    cin >> n >> x;
    map<ll,ll> occurs;
    set<ll> unique;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        occurs[a]++;
        unique.insert(a);
    }
    
    vector<ll> numbers(unique.begin(),unique.end());
    sort(numbers.begin(),numbers.end());
    ll out = 0;
    for (int i = 0; i < (int)numbers.size(); i++) {
        if (occurs[numbers[i]*x]) {
            ll away = min(occurs[numbers[i]*x], occurs[numbers[i]]);
            occurs[numbers[i]*x] -= away;
            occurs[numbers[i]] -= away;
        }
        out += occurs[numbers[i]];
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
