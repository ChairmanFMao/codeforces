#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Execute as many commands as possible
// can start in ([0,n], [0,m])

void solve() {
	int n, m;
	string s;
	cin >> n >> m >> s;
	int x = 0, y = 0, minx = 0, maxx = 0, miny = 0, maxy = 0;
	for (int i = 0; i < sz(s); i++) {
		if (s[i] == 'L')
			x--;
		else if (s[i] == 'R')
			x++;
		else if (s[i] == 'U')
			y--;
		else if (s[i] == 'D')
			y++;

		int oldmix = minx, oldmax = maxx, oldmiy = miny, oldmay = maxy;
		minx = min(minx,x);
		maxx = max(maxx,x);
		miny = min(miny,y);
		maxy = max(maxy,y);

		if (maxx - minx >= m) {
			cout << abs(oldmiy)+1 << " " << abs(oldmix)+1 << "\n";
			return;
		} else if (maxy - miny >= n) {
			cout << abs(oldmiy)+1 << " " << abs(oldmix)+1 << "\n";
			return;
		}
	}

	cout << abs(miny)+1 << " " << abs(minx)+1 << "\n";
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

