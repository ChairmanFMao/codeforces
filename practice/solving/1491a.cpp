#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	map<int,int> m;
	for (int i : a)
		m[i]++;

	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;
			x--;
			m[a[x]]--;
			a[x] ^= 1;
			m[a[x]]++;
		} else {
			int k;
			cin >> k;
			cout << ((k-1) < m[1] ? 1 : 0) << "\n";
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

