#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	if (k == 1) {
		cout << (n-1)/2 << "\n";
		return;
	}

	int out = 0;
	for (int i = 1; i < n-1; i++)
		if (a[i] > a[i-1] + a[i+1])
			out++;

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

