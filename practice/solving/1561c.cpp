#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Strictly greater

bool comp(pair<int,int> a, pair<int,int> b) {
	return a.first < b.first;
}

void solve() {
	int n;
	cin >> n;
	vector<pair<ll,ll>> req;
	for (int i = 0; i < n; i++) {
		ll k;
		cin >> k;
		vector<ll> a(k);
		for (ll& i : a)
			cin >> i;
		ll out = 0;
		for (ll j = 0; j < k; j++)
			out = max(out, a[j]+1-j);

		req.push_back({out,k});
	}
	sort(all(req),comp);

	ll start = 0, add = 0;
	for (int i = 0; i < n; i++) {
		if (start + add < req[i].f)
			start = req[i].f - add;
		add += req[i].s;
	}
	
	cout << start << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
		solve();
}

