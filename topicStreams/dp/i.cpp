#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// What if you store all of the max rows
// Then after you update a row just recalculate that row

const int mxN = 5e2;
int n, m, q;
// 1 for eyes, 0 for mouth
bool grid[mxN][mxN];
int scores[mxN];

// Just pass in the row
void calculate(int i) {
	int streak = 0, best = 0;
	for (int j = 0; j < m; j++) {
		if (grid[i][j])
			streak++;
		else {
			best = max(best,streak);
			streak = 0;
		}
	}
	scores[i] = max(best,streak);
}

void solve() {
	memset(scores, 0, sizeof scores);
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];

	for (int i = 0; i < n; i++)
		calculate(i);

	for (int i = 0,a,b; i < q; i++) {
		cin >> a >> b;
		grid[a-1][b-1] ^= 1;
		calculate(a-1);
		cout << *max_element(scores,scores+mxN) << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

