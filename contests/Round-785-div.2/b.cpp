#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// if for any substring there is a double of 1 character
// You just need a substring with 2 of one character and another
// character that is in the string but left out

void solve() {
	string s;
	cin >> s;

	map<char,int> occurs;
	set<char> unique;
	for (char c : s) {
		occurs[c]++;
		unique.insert(c);
	}

	if (sz(unique) == 1) {
		cout << "YES\n";
		return;
	}

	for (int i = 97; i < 97+26; i++) {
		if (occurs[(char)i] <= 1)
			continue;

		set<char> seen;
		bool flag = 1;
		for (int j = 0; j < sz(s); j++) {
			if (s[j] == (char)i) {
				if (sz(seen) < sz(unique) && !flag) {
					cout << "NO\n";
					return;
				}
				seen.clear();
				flag = 0;
			}
			seen.insert(s[j]);
		}
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

