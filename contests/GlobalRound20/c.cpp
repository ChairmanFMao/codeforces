#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// There can only be one pair left over
// wa on pretest 2 - can't think of a defying test case

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	vector<pair<int,int>> streaks;
	int streak = 1, start = 0;
	for (int i = 0; i < n-1; i++) {
		if (a[i] == a[i+1])
			streak++;
		else {
			if (streak > 1)
				streaks.push_back({streak,start});
			start = i+1;
			streak = 1;
		}
	}

	if (streak > 1)
		streaks.push_back({streak,start});

	if (sz(streaks) == 0) {
		cout << "0\n";
		return;
	}

	if (sz(streaks) == 1) {
		cout << (streaks[0].first <= 3 ? streaks[0].first - 2 : streaks[0].first - 3) << "\n";
		return;
	}

	int ptr = streaks[sz(streaks)-1].second;
	while (ptr < n && a[ptr] == a[streaks[sz(streaks)-1].second])
		ptr++;
	ptr--;
	cout << ptr - streaks[0].second - 2 << "\n";
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

