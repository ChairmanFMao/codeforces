#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	if (!(n&1)) {
		cout << "YES\n";
		return;
	}

	for (int i = 0; i < n-1; i++) {
		if (a[i] >= a[i+1]) {
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

