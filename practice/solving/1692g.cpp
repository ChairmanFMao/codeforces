#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Just need to check for values where the next one is less than half

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	vector<int> streaks;
	int streak = 1;
	for (int i = 0; i < n-1; i++) {
		if (a[i+1]*2 <= a[i]) {
			streaks.push_back(streak);
			streak = 1;
		} else
			streak++;
	}
	streaks.push_back(streak);

	int out = 0;
	for (int i = 0; i < sz(streaks); i++)
		out += max(0,streaks[i]-k);

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

