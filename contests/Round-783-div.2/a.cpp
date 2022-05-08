#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, m;
	cin >> n >> m;

	if ((n == 1 && m > 2) || (m == 1 && n > 2)) {
		cout << "-1\n";
		return;
	}

	n--;
	m--;

	cout << 2*min(n,m) + 4*((max(n,m)-min(n,m))/2) + ((max(n,m)-min(n,m))%2 == 1 ? 1 : 0) << "\n";
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

