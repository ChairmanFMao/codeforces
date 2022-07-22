#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, k;
	string s;
	cin >> n >> s >> k;
	set<char> special;
	for (int i = 0; i < k; i++) {
		char a;
		cin >> a;
		special.insert(a);
	}
	
	int streak = 1, best = 0;
	for (int i = 0; i < n-1; i++) {
		if (special.count(s[i+1])) {
			best = max(best,streak);
			streak = 1;
		} else
			streak++;
	}

	cout << best << "\n";
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

