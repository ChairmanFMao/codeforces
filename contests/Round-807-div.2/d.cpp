#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// The number of lights on isn't conserved
// The gaps between groups can be altered
// Ends have to match
// Need to determine how many operations needed

void solve() {
	int n;
	string s, t;
	cin >> n >> s >> t;

	if (s[0] != t[0] || s[n-1] != t[n-1]) {
		cout << "-1\n";
		return;
	}

	vector<pair<int,int>> sGroups, tGroups;
	int streak = 0, start = -1;
	for (int i = 0; i < n; i++) {
		if ((s[i] & 1) && start == -1) {
			streak++;
			start = i;
		} else if (s[i] & 1)
			streak++;
		else {
			if (streak) {
				sGroups.push_back({start,streak});
				streak = 0;
				start = -1;
			}
		}
	}
	if (streak)
		sGroups.push_back({start,streak});

	streak = 0; start = -1;
	for (int i = 0; i < n; i++) {
		if ((t[i] & 1) && start == -1) {
			streak++;
			start = i;
		} else if (t[i] & 1)
			streak++;
		else {
			if (streak) {
				tGroups.push_back({start,streak});
				streak = 0;
				start = -1;
			}
		}
	}
	if (streak)
		tGroups.push_back({start,streak});

	if (sz(sGroups) != sz(tGroups)) {
		cout << "-1\n";
		return;
	}

	ll out = 0;
	for (int i = 0; i < sz(sGroups); i++) {
		int ss = sGroups[i].first, sl = sGroups[i].second;
		int ts = tGroups[i].first, tl = tGroups[i].second;
		out += abs(ts-ss);
		out += abs(ts+tl - (ss+sl));
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

