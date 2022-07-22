#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// I think that this might be dp

const ll MOD = 1e9+7, mxN = 1e5;

int n;
int a[mxN+1], b[mxN+1], d[mxN+1];
map<int,vector<int> > m;
set<int> seen;

void dfs(int current) {
	if (seen.count(current))
		return;

	seen.insert(current);
	for (int i = 0; i < sz(m[a[current]]); i++)
		if (m[a[current]][i] != current)
			dfs(m[a[current]][i]);
	for (int i = 0; i < sz(m[b[current]]); i++)
		if (m[b[current]][i] != current)
			dfs(m[b[current]][i]);
}

ll fact(int current) {
	ll out = 1;
	for (int i = 2; i <= current; i++)
		out *= i;
	return out;
}

void solve() {
	m.clear();
	seen.clear();
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> d[i];

	for (int i = 0; i < n; i++) {
		m[a[i]].push_back(i);
		m[b[i]].push_back(i);
	}

	ll out = 1;
	for (int i = 0; i < n; i++)
		if (d[i] && !seen.count(i))
			dfs(i);
	for (int i = 0; i < n; i++)
		if (!d[i] && !seen.count(i) && a[i] != b[i]) {
			dfs(i);
			out = (out * 2) % MOD;
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

