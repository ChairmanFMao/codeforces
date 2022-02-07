
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fight (ll hh, ll hd, ll mh, ll md) {
    ll heroHits = (mh / hd) + ((mh % hd) ? 1 : 0);
    ll monsterHits = (hh / md) + ((hh % md) ? 1 : 0);
    return heroHits <= monsterHits;
}

void solve() {
    ll hh, hd, mh, md, k, w, a;
    cin >> hh >> hd >> mh >> md >> k >> w >> a;

    // Unsure how to determine the optimal spending of coins.
    // I can think of a very simple brute force but, I think that it will be too slow
    // Turns out that it wasn't too slow and it worked in like 46ms somehow.
    for (ll i = 0; i <= k; i++) {
        if (fight(hh + (k - i)*a, hd + (i * w), mh, md)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
