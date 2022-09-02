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
	string a, b;
	cin >> a >> b;

	int one = 0, zero = 0;
	for (int i = 0; i <= n-m; i++) {
		if (a[i] & 1)
			one = 1;
		else
			zero = 1;
	}

	if (a == b || (a.substr(n-m+1,m-1) == b.substr(1) && ((b[0] == '0' && zero) || (b[0] == '1' && one))))
		cout << "YES\n";
	else
		cout << "NO\n";
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

