#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n, oh, om;
	cin >> n >> oh >> om;
	int out = INT_MAX;

	for (int i = 0; i < n; i++) {
		int ch = oh, cm = om, sh, sm, current = 0;
		cin >> sh >> sm;
		while (ch != sh || cm != sm) {
			cm++;
			if (cm >= 60) {
				ch += cm/60;
				cm %= 60;
			} if (ch >= 24)
				ch %= 24;
			current++;
		}
		out = min(out,current);
	}

	cout << out/60 << " " << out % 60 << "\n";
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

