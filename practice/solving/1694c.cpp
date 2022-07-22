#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Passing through and passing back doesn't change a value

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	bool exists = 0;
	for (int i : a)
		if (i)
			exists = 1;

	if (!exists) {
		cout << "YES\n";
		return;
	}

	for (int i = n-1; ~i; i--)
		if (a[i]) {
			a[i]++;
			break;
		}
	a[0]--;

	ll current = 0;
	for (int i : a) {
		current += i;
		if (current < 0) {
			cout << "NO\n";
			return;
		}
	}

	cout << (current ? "NO" : "YES") << "\n";
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

