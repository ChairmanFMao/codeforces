#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// manhattan distance
// just do with maths
// must be able to make way across and way down
// also must have bit not in there

struct Po {
	int x, y, v;
};

void solve() {
	int n, m, sx, sy, d;
	cin >> n >> m >> sx >> sy >> d;

	int one = 1, two = 1;
	for (int i = 1; i <= n; i++) {
		bool a = abs(sx-i) + abs(sy-1) <= d;
		bool b = abs(sx-i) + abs(sy-m) <= d;
		one &= !a;
		two &= !b;
	}
	for (int i = 1; i <= m; i++) {
		bool a = abs(sx-n) + abs(sy-i) <= d;
		bool b = abs(sx-1) + abs(sy-i) <= d;
		one &= !a;
		two &= !b;
	}
	cout << (one||two ? n+m-2 : -1) << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
		solve();
}

