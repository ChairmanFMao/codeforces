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

	string out = "";
	for (int i = 0; i < n && sz(out) < 2; i++) {
		if (s[i] & 1)
			out += s[i];
	}

	cout << (sz(out) >= 2 ? out : "-1") << "\n";
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

