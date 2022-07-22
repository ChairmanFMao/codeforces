#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Maybe do this using streaks of letters
// Could do with dfs but time complexity bad
// The time complexity is too bad
string s;
int n;

void solve() {
	int a, b, ab, ba;
	cin >> a >> b >> ab >> ba;
	cin >> s;
	n = sz(s);
	
	vector<int> mutex;
	for (int i = 0; i < n-1; i++) {
		if ((!i || s[i-1] == s[i+1]) && s[i-1] != s[i])
			mutex.push_back(i);
	}

	set<int> unique(all(mutex));

	vector<bool> done(n,0);
	for (int i = 0; i < n; i++) {
		if ((!i || s[i-1] != s[i+1]) && s[i] != s[i+1]) {
			if (s[i] == 'A' && ab) {
				ab--;
				done[i] = 1;
				done[i+1] = 1;
			} else if (s[i] == 'B' && ba) {
				ba--;
				done[i] = 1;
				done[i+1] = 1;
			}
		}
	}

	for (int i : mutex) {
		if (done[i])
			continue;
		if (ba) {
			if (s[i] == 'B' && !done[i+1]) {
				done[i] = 1;
				done[i+1] = 1;
				ba--;
			} else if (!done[i-1]) {
				done[i-1] = 1;
				done[i] = 1;
				ba--;
			}
		} else if (ab) {
			if (s[i] == 'A' && !done[i+1]) {
				done[i] = 1;
				done[i+1] = 1;
				ab--;
			} else if (!done[i-1]) {
				done[i] = 1;
				done[i-1] = 1;
				ab--;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (!done[i]) {
			if (s[i] == 'A')
				a--;
			else
				b--;
		}
	}

	cout << (a == 0 && b == 0 && ab == 0 && ba == 0 ? "YES" : "NO") << "\n";
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

