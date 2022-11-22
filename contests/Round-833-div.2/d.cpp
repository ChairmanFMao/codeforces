#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Can find any integer between 0 and 1<<60
// need to find the representation of multiples of d
// which include the bits in a and the bits in b + more overlap
// just have a and b get to the same number
// then from there try to toggle the rest of the bits
// need to see if there is a subset that we can add which will
// lead to it being divisible by d
// store all of the values mod d and try to dp up?
// I think that this could be doable
// this could lead to O(2^64) ish tho which isn't good
// I'm kinda unsure how to best do this
// The current approach I'm thinking of relies on the value of d
// being small

void solve() {
	ll a, b, d;
	cin >> a >> b >> d;
	ll c = a|b;
	vector<ll> choice;
	for (ll i = 0; i < 60; i++)
		if (!((1ll<<i)&c))
			choice.push_back((1ll<<i)%d);

	sort(all(choice));
	vector<pair<ll,ll> > bad;
	ll current = choice[0];
	for (ll i = 1; i < sz(choice); i++) {
		if (current < choice[i]) {
			bad.push_back({current+1,choice[i]-1});
		}
		current += choice[i];
	}
	bad.push_back({current+1,d});

	ll needed = (d-(c%d))%d, good = 1;
	cout << "needed: " << needed << "\n";
	for (ll i = 0; i < sz(bad); i++) {
		cout << "lower: " << bad[i].f << " val: " << needed << " upper: " << bad[i].s << "\n";
		if (bad[i].f <= needed && needed <= bad[i].s) {
			good = 0;
		}
	}

	cout << good << "\n";
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

