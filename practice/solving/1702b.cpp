#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	string s;
	cin >> s;

	set<char> u;
	int out = 1, ptr = 0;
	while (ptr < sz(s)) {
		while (sz(u) < 4 && ptr < sz(s)) {
			if (u.count(s[ptr]))
				ptr++;
			else {
				if (sz(u) == 3) {
					out++;
					u.clear();
					break;
				} else
					u.insert(s[ptr]);
			}
		}
	}

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

