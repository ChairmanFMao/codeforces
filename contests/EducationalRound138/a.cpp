#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> rows(n), columns(n);
	for (int i = 0; i < m; i++) {
		int a,b; cin >> a >> b; a--; b--;
		rows[a]++;
		columns[b]++;
	}
	int rmin = 1, cmin = 1;
	for (int i = 0; i < n; i++) {
		if (rows[i] > 2 || columns[i] > 2) {
			cout << "NO\n";
			return;
		}
		rmin = min(rmin,rows[i]);
		cmin = min(cmin,columns[i]);
	}

	cout << (rmin > 0 && cmin > 0 ? "NO" : "YES") << "\n";
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

