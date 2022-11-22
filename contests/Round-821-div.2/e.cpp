#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just need to check if x < y
// if so then we want to do all pairs first
// can just greedily do it I think
// you can do a funny thing where you move all of the 1 values
// just get the (abs-1)*x from all of the nearest 1 wanted
// need to chose which ones to move along and which to just swap
// need to switch on the closest ones
// need to switch off the furthest ones
// greedily match to all the ones possible?
// something O(n^2) would work here
// try matching each on to each off?
// for each of the on's spread out to find closest available?

void solve() {
	ll n, x, y;
	string as, bs;
	cin >> n >> x >> y >> as >> bs;
	vector<ll> a(n), b(n);
	for (ll i = 0; i < n; i++) {
		a[i] = as[i]&1;
		b[i] = bs[i]&1;
	}

	ll asum = accumulate(all(a),0);
	ll bsum = accumulate(all(b),0);

	if (asum%2 != bsum%2) {
		cout << "-1\n";
		return;
	}

	// This doesn't effect the problem
	// without loss of generality
	ll on = abs(asum-bsum);
	if (asum-bsum < 0) {
		for (int i = 0; i < n; i++) {
			a[i] ^= 1;
			b[i] ^= 1;
		}
	}
	set<int> good;

	for (int i = 0; i < n; i++) {
		if (!b[i])
			continue;
		for (int j = 0; j < n; j++) {
			if (i-j >= 0 && a[i-j] && !good.count(i-j)) {
				good.insert(i-j);
				break;
			} if (i+j < n && a[i+j] && !good.count(i+j)) {
				good.insert(i+j);
				break;
			}
		}
	}

	vector<int> notGood;
	for (int i = 0; i < n; i++)
		if (!good.count(i) && a[i]) {
			notGood.push_back(i);
			a[i] ^= 1;
		}

	// Now I can pair them up and decide which is cheaper
	int aptr = 0, bptr = 0;
	vector<pair<int,int> > pairs;
	while (aptr < n && bptr < n) {
		while (!a[aptr])
			aptr++;
		while (!b[bptr])
			bptr++;

		pairs.push_back({aptr,bptr});
		aptr++;
		bptr++;
	}

	vector<ll> values;
	for (int i = 0; i < sz(pairs); i++)
		values.push_back(max(0ll,x*abs(aptr-bptr)));

	sort(all(values));

	ll out = accumulate(all(values),0ll);

	for (int i = 0; i < sz(values); i++) {
		if ((sz(values)-i)&1)
			continue;
		ll current = 0;
		for (int j = 0; j < i; j++)
			current += values[j];
		current += y*(sz(values)-i);

		cout << "i: " << i << " current: " << current << "\n";

		out = min(out,current);
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

