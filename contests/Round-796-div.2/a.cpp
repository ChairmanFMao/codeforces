#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	ll x;
	cin >> x;
	
	ll y = 0, c = 0;
	bool f = 1, r = 1;
	for (int i = 0; i < 32; i++) {
		if (x & (1<<i))
			c++;
	}
	r = (c==1);
	for (int i = 0; i < 32; i++) {
		if (x & (1<<i) && f) {
			y |= (1<<i);
			f = 0;
		}
		if (x ^ (1<<i) && r) {
			y |= (1<<i);
			r = 0;
		}
	}

	cout << y << "\n";
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

