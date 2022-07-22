#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n;
	string s;
	cin >> n >> s;

	int odd = 0, even = 0;
	// 1 goes first
	for (int i = 0; i < n; i++) {
		if (!(i&1) && (s[i]&1))
			odd++;
		if ((i&1) && !(s[i]&1))
			even++;
	}

	cout << (((n&1) && odd) || (!(n&1) && even == 0) ? 1 : 2) << "\n";
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

