#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Need to find out the final desination
// And how far the robot needs to be offset from the ending point
// I think O(n^2) is possible, might just brute force obstacle
// placements everywhere where the robot goes
string s;

bool finish(int bx, int by) {
	int x = 0, y = 0;
	for (int i = 0; i < sz(s); i++) {
		if (s[i] == 'U' && !(x == bx && y+1 == by))
			y++;
		else if (s[i] == 'D' && !(x == bx && y-1 == by))
			y--;
		else if (s[i] == 'R' && !(x+1 == bx && y == by))
			x++;
		else if (s[i] == 'L' && !(x-1 == bx && y == by))
			x--;
	}
	return x == 0 && y == 0;
}

void solve() {
	cin >> s;
	int x = 0, y = 0;
	for (int i = 0; i < sz(s); i++) {
		int nx = x, ny = y;
		if (s[i] == 'U')
			ny = y+1;
		else if (s[i] == 'D')
			ny = y-1;
		else if (s[i] == 'R')
			nx = x+1;
		else if (s[i] == 'L')
			nx = x-1;
		if (finish(nx, ny)) {
			cout << nx << " " << ny << "\n";
			return;
		}
		x = nx;
		y = ny;
	}

	cout << "0 0\n";
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

