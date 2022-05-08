#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	string s;
	cin >> s;

	int streak = 1;
	for (int i = 1; i < sz(s); i++) {
		if (s[i] == s[i-1])
			streak++;
		else {
			if (streak == 1) {
				cout << "NO\n";
				return;
			} else {
				streak = 1;
			}
		}
	}

	cout << (streak == 1 ? "NO" : "YES") << "\n";
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

