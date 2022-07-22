#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n), b(n);
	for (int& i : a)
		cin >> i;
	for (int& i : b)
		cin >> i;

	sort(all(a));
	sort(all(b));
	for (int i = 0; i < n; i++) {
		if (a[i] + b[n-1-i] > x) {
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

