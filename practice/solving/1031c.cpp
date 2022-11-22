#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Need to actually also find the notes
// use triangle number formula
// want to have the bigger number of hours used more efficiently
// getting lots of wa sadly

void solve() {
	ll a, b;
	cin >> a >> b;

	vector<ll> one, num;
	set<ll> seen;

	for (ll i = 1; (i*(i+1))/2 <= a+b; i++)
		num.push_back(i);

	ll ptr = sz(num)-1;
	while (a && ptr >= 0) {
		if (num[ptr] <= a) {
			a -= num[ptr];
			one.push_back(num[ptr]);
			seen.insert(num[ptr]);
		}
		ptr--;
	}

	cout << sz(one) << "\n";
	for (ll i : one)
		cout << i << " ";
	cout << "\n";
	cout << sz(num) - sz(one) << "\n";
	for (ll i = 0; i < sz(num); i++)
		if (!seen.count(num[i]))
			cout << num[i] << " ";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

