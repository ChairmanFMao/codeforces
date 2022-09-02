#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Minimum possible for the and then or
// for each value in a you choose a value in b
// values capped at 2**9 = 512
// m and n also capped at 200
// Can make a very inefficient solution
// greedy isn't always optimum
// O(512 * n * m) would pass I think

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int& i : a)
		cin >> i;
	for (int& i : b)
		cin >> i;

	for (int i = 0; i < 512; i++) {
		int flag1 = 1;
		for (int j = 0; j < n; j++) {
			int flag2 = 0;
			for (int k = 0; k < m; k++)
				if (((a[j]&b[k])|i) == i) {
					flag2 = 1;
					break;
				}

			if (!flag2) {
				flag1 = 0;
				break;
			}
		}
		if (flag1) {
			cout << i << "\n";
			return;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

