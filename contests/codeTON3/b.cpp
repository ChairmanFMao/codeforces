#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n;
	string s;
	cin >> n >> s;

	ll streak = 0, current = s[0], best = 0;
	ll one = 0, zero = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == current)
			streak++;
		else {
			current = s[i];
			streak = 1;
		}
		if (s[i] == '1')
			one++;
		else
			zero++;
		best = max(streak,best);
	}

	cout << max(best*best,one*zero) << "\n";
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

