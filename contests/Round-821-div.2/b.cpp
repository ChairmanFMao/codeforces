#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Every player has won either x or y games
// wa on pretest 2 somehow
// 1, 3 1 0

void solve() {
	int n, x, y;
	cin >> n >> x >> y;

	if ((x && y) || (!x && !y)) {
		cout << "-1\n";
		return;
	}

	if ((n-1) % max(x,y)) {
		cout << "-1\n";
		return;
	}

	int wins = max(x,y);
	int current = 1, other = 2, count = 0;
	while (max(other,current) <= n) {
		if (count < wins) {
			cout << current << " ";
			other++;
		} else if (count == wins) {
			current = other;
			cout << current << " ";
			other++;
			count = 0;
		}
		count++;
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

