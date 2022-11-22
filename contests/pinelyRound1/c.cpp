#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// If grid[i][j], a[i] must be a subset of a[j]
// otherwise a[i] must not be a subset of a[j]
// This is probably brute forceable by the constraints
// all of the sets also need to contain at least 1 element
// to be a proper subset, a[i] != a[j]
// start with each subset with their element
// if 1 then all of a[i] not in a[j] is united into it
// This passed first try!

void solve() {
	ll n;
	cin >> n;
	vector<vector<ll> > grid(n,vector<ll>(n,0));
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (ll j = 0; j < n; j++)
			grid[i][j] = s[j] == '1';
	}

	vector<set<ll> > a(n);
	for (ll i = 0; i < n; i++)
		a[i].insert(i);

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			if (grid[i][j]) {
				for (auto l = a[i].begin(); l != a[i].end(); l++)
					a[j].insert(*l);
			}
		}
	}

	for (ll i = 0; i < n; i++) {
		cout << sz(a[i]) << " ";
		for (auto j = a[i].begin(); j != a[i].end(); j++)
			cout << (*j)+1 << " ";
		cout << "\n";
	}
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

