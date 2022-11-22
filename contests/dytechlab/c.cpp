#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Can go diagonal
// I think they just can't reach corners?
// can move the formation in moves of 2
// the colour of the square of each is maintained
// can't get to the odd one out with different parity

void solve() {
	int n;
	cin >> n;
	vector<pair<int,int> > c(3);
	for (pair<int,int>& i : c)
		cin >> i.f >> i.s;
	int x, y;
	cin >> x >> y;

	pair<int,int> bad = {0,0};
	for (int i = 0; i < 3; i++)
		for (int j = i+1; j < 3; j++) {
			if (c[i].f == c[j].f)
				bad.f = c[i].f;
			if (c[i].s == c[j].s)
				bad.s = c[i].s;
		}

	// Checks for corner
	if ((bad.f == 1 || bad.f == n) && (bad.s == 1 || bad.s == n)) {
		for (int i = 0; i < 3; i++)
			if (x == c[i].f && y == c[i].s) {
				cout << "YES\n";
				return;
			}
		if (x == bad.f || y == bad.s) {
			cout << "YES\n";
			return;
		}
		cout << "NO\n";
		return;
	}

	// 1 means black, 0 means white
	int col = (x+y)%2;

	// Checks for if same colour as two
	if (col != (bad.f+bad.s)%2) {
		cout << "YES\n";
		return;
	}

	

	// Does the other thing
	if ((x%2 == bad.f%2) + (y%2 == bad.s%2) == 2) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
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

