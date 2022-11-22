#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// The flips are large
// can either convert everything to 0 or have a flip point at the
// first 1 that you find
// iterate over that point, might lead O(n^2) tho
// we are going to do all to zero and all to one
// could be done with dp maybe?

void solve() {
	int n;
	string s;
	cin >> n >> s;

	vector<pair<int,int> > streaks;
	int streak = 0, last = s[0];
	for (int i = 0; i < n; i++) {
		if (s[i] == last)
			streak++;
		else {
			streaks.push_back({streak,last-48});
			streak = 1;
			last = s[i];
		}
	}
	if (streak)
		streaks.push_back({streak,last-48});

	vector<int> allz;
	int tot = 0, sw = 0;
	for (int i = 0; i < sz(streaks); i++) {
		allz.push_back(tot);
		if (streaks[i].s^sw == 1) {
			tot += 2;
			sw++;
		}
	}
	allz.push_back(tot);

	int ops = INT_MAX, other = 0;
	for (int i = sz(streaks)-1; ~i; i--) {
		ops = min(ops,allz[i]+other);
		if (i == sz(streaks)-1 && streaks[i].s == 0)
			other++;
		else if (streaks[i].s == 0)
			other += 2;
	}

	cout << ops << "\n";
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

