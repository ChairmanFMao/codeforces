#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	ll n, k;
	cin >> n >> k;

	map<int,ll> m;
	ll bits = 0, most = 0;
	for (int i = 0; i < 31; i++)
		if (n & (1<<i)) {
			bits++;
			most += (1<<i);
			m[i]++;
		}

	if (bits > k || most < k) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";

	for (int i = 30; ~i && bits < k; i--) {
		if (m[i]) {
			ll move = min(k-bits, m[i]);
			m[i-1] += 2 * move;
			m[i] -= move;
			bits += move;
		}
	}

	for (int i = 0; i < 31; i++)
		for (int j = 0; j < m[i]; j++)
			cout << (1<<i) << " ";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

