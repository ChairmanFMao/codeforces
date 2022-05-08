#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	string s;
	cin >> s;

	bool b = 0;
	for (int i = 0; i < sz(s); i++)
		if (s[i] == 'B')
			b = 1;

	if (s[sz(s)-1] != 'B') {
		cout << "NO\n";
		return;
	}

	int c = 0;
	for (int i = 0; i < sz(s); i++) {
		if (s[i] == 'A')
			c++;
		else
			c--;

		if (c < 0) {
			cout << "NO\n";
			return;
		}
	}

	cout << (!b ? "NO" : "YES") << "\n";
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

