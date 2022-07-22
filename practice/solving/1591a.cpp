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

	int height = 1;
	for (int i = 0; i < n; i++) {
		if (i < n-1 && !a[i] && !a[i+1]) {
			cout << "-1\n";
			return;
		}
		if (i < n-1 && a[i] && a[i+1])
			height += 5;
		else if (a[i])
			height++;
	}

	cout << height << "\n";
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

