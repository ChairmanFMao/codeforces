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

	int out = 0, streak = 0;
	for (int i = 0; i < n; i++) {
		if (!a[i]) {
			out += streak;
			streak = 0;
		} else
			streak = 1;
	}
	out += streak;

	cout << min(2,out) << "\n";
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


