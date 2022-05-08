#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Invalid if no r or no b

void solve() {
	int n;
	string s;
	cin >> n >> s;
	
	bool r = 0, b = 0, streak = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') {
			streak = 1;
			r = 1;
		} else if (s[i] == 'B') {
			streak = 1;
			b = 1;
		} else {
			if (streak && (!r || !b)) {
				cout << "NO\n";
				return;
			}
			r = 0;
			b = 0;
			streak = 0;
		}
	}

	if (streak && (!r || !b)) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
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

