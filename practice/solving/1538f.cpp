#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Looked at solution

void solve() {
	int l, r;
	cin >> l >> r;
	ll out = 0;
	for (int i = 1; i <= 1e9; i *= 10)
		out += max(0,r/i - l/i);

	cout << out << "\n";
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

