#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	cin >> n;
	vector<int> w(n);
	for (int& i : w)
		cin >> i;

	int best = 0, a = 0, b = 0, aptr = 0, bptr = n-1;
	while (aptr <= bptr) {
		if (a == b)
			best = aptr + (n-1-bptr);
		if (a <= b) {
			a += w[aptr];
			aptr++;
		} else {
			b += w[bptr];
			bptr--;
		}
	}

	if (a == b)
		best = aptr + (n-1-bptr);

	cout << best << "\n";
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

