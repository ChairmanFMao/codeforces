#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int,int> occurs;
	for (int& i : a) {
		cin >> i;
		occurs[i]++;
	}

	for (int i = 0; i < n; i++) {
		if (occurs[a[i]] >= 3) {
			cout << a[i] << "\n";
			return;
		}
	}

	cout << "-1\n";
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

