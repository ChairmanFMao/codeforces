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
	vector<int> p(n);
	for (int& i : p)
		cin >> i;

	for (int i = 0; i < m; i++) {
		int l, r, x; cin >> l >> r >> x; l--; r--; x--;
		if (x < l || x > r) {
			cout << "Yes\n";
			continue;
		}
		int below = 0, above = 0;
		for (int j = l; j <= r; j++) {
			if (p[j] > p[x])
				above++;
			if (p[j] < p[x])
				below++;
		}
		if (l + below == x)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

