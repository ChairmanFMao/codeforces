#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Brute force is impossible
// c is very small, I think it could be useful
// I think something recursive might be good
const int mxC = 40;
vector<pair<ll,ll>> ops(mxC);
string s;
ll n, c, q;

char dfs(ll index) {
	ll start = sz(s);
	if (index < start)
		return s[index];
	
	for (ll i = 0; i < c; i++) {
		start += ops[i].second - ops[i].first + 1;
		if (index < start)
			return dfs(ops[i].first + index - (start - (ops[i].second - ops[i].first + 1)));
	}

	return '?';
}

void solve() {
	cin >> n >> c >> q;
	cin >> s;
	for (ll i = 0; i < c; i++) {
		cin >> ops[i].first >> ops[i].second;
		ops[i].first--; ops[i].second--;
	}
	vector<ll> queries(q);
	for (ll& i : queries) {
		cin >> i; i--;
	}

	for (ll i : queries)
		cout << dfs(i) << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

