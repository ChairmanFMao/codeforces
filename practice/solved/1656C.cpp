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

	int one = 0;
	for (int i : a)
		if (i == 1)
			one++;

	if (!one) {
		cout << "YES\n";
		return;
	}

	sort(all(a));
	for (int i = 0; i < n-1; i++) {
		if (a[i] == a[i+1] -1) {
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

