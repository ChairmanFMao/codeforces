#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// checking if the integer k on the number line can be coloured
// can start at a[p[i]] or go b[p[i]] from an existing integer
// the numbers are also coloured with p[i]
// this is important because we want to colour k with 1
// if a[0] is greater than or equal k then yes
// otherwise we need a number less than b[0] away from k
// maybe do like dp backwards or smth?
// its almost like a knapsack problem where the weight can vary
// up to b[i] and need to add to a total less than or equal a[i]
// just need to see if it is possible to get the weights to be
// within b[0] from k, using a subset of the others
// unsure what order to do the numbers in
// however, I apart from 1 I don't think the order matters
// getting wa on the first sample case
// with some changes we now fail a different sample case
// wa on pretest 2, I kinda expected it tho as I just added
// another condition into the if to pass the samples

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<pair<ll,ll>> a(n);
	for (pair<ll,ll>& i : a)
		cin >> i.f >> i.s;

	if (a[0].f >= k) {
		cout << "YES\n";
		return;
	}

	ll tot = 0;
	for (ll i = 0; i < n; i++)
		tot += a[i].s;

	for (ll i = 0; i < n; i++) {
		ll furthest = tot - a[i].s + a[i].f;
		if (k <= min(furthest,a[0].f)+a[0].s && k <= furthest) {
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

