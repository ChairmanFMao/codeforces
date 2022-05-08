#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Upsolved this problem after the contest, kinda annoyed that I had
// bad time management in the contest and didn't manage to complete this
// it was just a bit of debugging that I needed to do

int iny, inx, intotal = 0, total, n, m, q;

void next() {
	iny = total/n;
	inx = total%n;
}

void solve() {
	cin >> n >> m >> q;
	vector<vector<bool> > grid(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			grid[i][j] = s[j] == '*';
			total += s[j] == '*';
		}
	}
	
	next();
	for (int i = 0; i <= iny; i++)
		for (int j = 0; j < (i == iny ? inx : n); j++) {
			intotal += (int)grid[j][i];
		}

	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		grid[x][y] = !grid[x][y];
		// Square currently one, previously zero
		if (grid[x][y]) {
			if ((y != iny || x != inx) && grid[inx][iny])
				intotal++;
			total++;
			next();
			if (y < iny || (y == iny && x < inx))
				intotal++;
		} 
		// Square currently zero, previously one
		else {
			total--;
			next();
			if (grid[inx][iny])
				intotal--;
			if (y < iny || (y == iny && x <= inx))
				intotal--;

		}
		
		cout << total-intotal << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "\n";
	solve();
}

