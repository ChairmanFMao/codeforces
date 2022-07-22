#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// We either have the choice of paying cki or a present below ki

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> k(n), c(m);
	for (int& i : k)
		cin >> i;
	for (int& i : c)
		cin >> i;

	sort(all(k));
	for (int i = 0; i < n; i++)
		k[i] = c[k[i]-1];

	ll ptr = n-1;
	for (int i = 0; i < n && ~ptr && k[ptr] > c[i]; i++) {
		k[ptr] = c[i];
		ptr--;
	}

	ll out = 0;
	for (int i : k)
		out += i;

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

