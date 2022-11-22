#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Max number of operations
// deletes the max prefix no matter if it is same character
// just always take characters from the closest streak until
// length of 1

void solve() {
	int n;
	string s;
	cin >> n >> s;

	vector<int> streaks;
	int streak = 1;
	for (int i = 1; i <= n; i++) {
		if (i == n)
			streaks.emplace_back(streak);
		else if (s[i] == s[i-1])
			streak++;
		else {
			streaks.emplace_back(streak);
			streak = 1;
		}
	}

	stack<pair<int,int> > mult;
	for (int i = sz(streaks)-1; ~i; i--)
		if (streaks[i] > 1)
			mult.push({i,streaks[i]});

	int out = 0, ptr = 0;
	while (ptr < sz(streaks)) {
		if (sz(mult)) {
			int i = -1;
			pair<int,int> current;
			while (i < ptr && sz(mult)) {
				current = mult.top();
				mult.pop();
				i = current.f;
			}
			if (!sz(mult) && i < ptr)
				ptr++;
			else {
				current.s--;
				if (current.s > 1)
					mult.push(current);
			}
		} else
			ptr++;
		ptr++;
		out++;
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

