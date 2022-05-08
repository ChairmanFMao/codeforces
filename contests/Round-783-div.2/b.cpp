#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	sort(all(a),greater<int>());
	ll out = a[0] + n;
	for (int i = 0; i < n-1; i++) {
		out += a[i];
	}

	cout << (out > m ? "NO" : "YES") << "\n";
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

