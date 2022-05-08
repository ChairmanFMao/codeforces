#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Need to ensure that we are doing it in lexicograph order
// The combinations need to be distinct as well
// We can condense consecutive * into one, then we can get the length
// I think we would need to use a choose function of a kind
// Had a think about the problem and came back to it with fresh idea
// Managed to solve it, needed bigger numbers as __int128
// Also needed to cap out so that if it is greater than x we don't
// need to increase it more

void solve() {
	ll nl, kl, xl;
	string s;
	cin >> nl >> kl >> xl >> s;
	__int128 n = nl, k = kl, x = xl;

	vector<__int128> streaks;
	ll streak = 0;	
	for (__int128 i = 0; i < n; i++) {
		if (s[i] == '*')
			streak++;
		else {
			if (streak)
				streaks.push_back(streak);
			streak = 0;
		}
	}
	if (streak)
		streaks.push_back(streak);

	vector<__int128> values(sz(streaks));
	for (__int128 i = 0; i < sz(streaks); i++)
		values[i] = k*streaks[i]+1;

	vector<__int128> combos(sz(values));
	__int128 out = 1;
	for (__int128 i = sz(streaks)-1; ~i; i--) {
		combos[i] = out;
		if (out <= x)
			out *= values[i];
	}
	
	x--;
	vector<__int128> stars(sz(values));
	for (__int128 i = 0; i < sz(combos); i++) {
		stars[i] = x/combos[i];
		x %= combos[i];
	}
	
	bool skip = 0;
	ll ptr = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') {
			cout << s[i];
			skip = 0;
		} else if (skip)
			continue;
		else {
			for (__int128 i = 0; i < stars[ptr]; i++)
				cout << 'b';
			ptr++;
			skip = 1;
		}
	}
	cout << "\n";
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

