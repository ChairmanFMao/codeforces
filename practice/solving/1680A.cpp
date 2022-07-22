#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int l, r, l2, r2;
	cin >> l >> r >> l2 >> r2;

	if (l2 > r || l > r2) {
		cout << l+l2 << "\n";
	} else {
		cout << max(l,l2) << "\n";
	}
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

