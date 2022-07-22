#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	string s;
	cin >> s;
	s += 'P';
	
	vector<pair<int,int> > streaks;
	int out = 0, streak = 0;
	char current, start;
	for (int i = 0; i < sz(s); i++) {
		if ((s[i] == 'A' || s[i] == 'B') && !streak) {
			streak = 1;
			current = s[i];
			start = s[i];
		} else if (streak && (s[i] == 'A' || s[i] == 'B') && s[i] != current) {
			streak++;
			current = s[i];
		} else if (streak && s[i] == current) {
			streaks.push_back({streak,start});
			start = current;
			streak = 1;
		} else if (streak && s[i] != current) {
			streaks.push_back({streak,start});
			streak = 0;
		}
	}

	for (int i = 0; i < sz(streaks); i++) {
		if (streaks[i].first >= 5)
			out |= 7;
		else if (streaks[i].first >= 3)
			out |= 4;
		else if (streaks[i].first == 1)
			continue;
		else if (streaks[i].second == 'A')
			out |= 2;
		else
			out |= 1;
	}

	cout << (out == 3 || out >= 5 ? "YES" : "NO") << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

