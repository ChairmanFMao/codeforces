#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	for (int i = 1; i < n; i++) {
		a[i] %= a[i-1];
		a[i] += a[i-1];
	}

	for (int i = n-1; i > 0; i--) {
		a[i] %= a[i-1];
		if (a[i]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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

