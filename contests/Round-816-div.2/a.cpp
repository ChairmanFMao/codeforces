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

	if (n == 1 && m == 1) {
		cout << "0\n";
		return;
	}

	if (n < m) {
		cout << m + n + n - 2 << "\n";
	} else {
		cout << n + m + m - 2 << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

