#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	int p = a[0] & 1;
	for (int i = 0; i < n; i+=2) {
		if ((a[i] & 1) != p) {
			cout << "NO\n";
			return;
		}
	}

	if (n > 1) {
		p = a[1] & 1;
		for (int i = 1; i < n; i+=2) {
			if ((a[i] & 1) != p) {
				cout << "NO\n";
				return;
			}
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

