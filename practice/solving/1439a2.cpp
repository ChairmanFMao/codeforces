#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// You don't need to minimise the number of operations
// must finish with a 2x2 square for it
// need 1 values in the top right, bottom right and bottom left
// then 0 values in the rightmost column and bottom row
// allowed mxn operations
// maybe try to shift all the ones to a side
// shift all ones to the right and bottom
// then move from the top right down
// move from the bottom left right
// getting wa on test 1
// first step in my thing is not working as expected
// I managed to solve this without help after 2 hrs lol

struct Operation {
	int x1, y1, x2, y2, x3, y3;
};

const int mxN = 100, mxM = 100;
vector<vector<int> > grid(mxN,vector<int>(mxM));
int n, m;

int total() {
	int out = 0;
	out += grid[n-1][m-1];
	out += grid[n-2][m-1];
	out += grid[n-1][m-2];
	out += grid[n-2][m-2];
	return out;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			grid[i][j] = s[j]&1;
	}

	Operation op;
	vector<Operation> ops;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m-1; j++) {
			if (i == n-2 && j == m-2)
				continue;
			if (grid[i][j]) {
				op.x1 = i; op.x2 = i; op.x3 = i+1;
				op.y1 = j; op.y2 = j+1; op.y3 = j;
				ops.push_back(op);
				grid[op.x1][op.y1] ^= 1;
				grid[op.x2][op.y2] ^= 1;
				grid[op.x3][op.y3] ^= 1;
			}
		}
	}

	for (int i = 0; i < n-2; i++) {
		op.y1 = m-1; op.y2 = m-1; op.y3 = m-2;
		op.x1 = i; op.x2 = i+1; op.x3 = i+1;
		if (grid[i][m-2] && grid[i][m-1]) {
			op.x2 = i; op.y2 = m-2;
		} else if (grid[i][m-2]) {
			op.x1 = i; op.y1 = m-2;
		} else if (!grid[i][m-1] && !grid[i][m-2])
			continue;

		ops.push_back(op);
		grid[op.x1][op.y1] ^= 1;
		grid[op.x2][op.y2] ^= 1;
		grid[op.x3][op.y3] ^= 1;
	}

	for (int i = 0; i < m-2; i++) {
		op.x1 = n-1; op.x2 = n-1; op.x3 = n-2;
		op.y1 = i; op.y2 = i+1; op.y3 = i+1;
		if (grid[n-1][i] && grid[n-2][i]) {
			op.y2 = i; op.x2= n-2;
		} else if (grid[n-2][i]) {
			op.y1 = i; op.x1 = n-2;
		} else if (!grid[n-2][i] && !grid[n-1][i])
			continue;

		ops.push_back(op);
		grid[op.x1][op.y1] ^= 1;
		grid[op.x2][op.y2] ^= 1;
		grid[op.x3][op.y3] ^= 1;
	}

	// Just need to handle the bottom right corner now
	// first number is 1, second is 0
	vector<pair<int,int> > c = {{0,0},{1,2},{1,2},{3,0},{3,0}};
	int tot = total();
	while (tot) {
		int count = 0, count2 = 0;
		vector<pair<int,int> > current;
		for (int i = n-2; i < n; i++) {
			for (int j = m-2; j < m; j++) {
				if (count < c[tot].f && grid[i][j]) {
					current.push_back({i,j});
					count++;
				} else if (count2 < c[tot].s && !grid[i][j]) {
					current.push_back({i,j});
					count2++;
				}
			}
		}
		grid[current[0].f][current[0].s] ^= 1;
		grid[current[1].f][current[1].s] ^= 1;
		grid[current[2].f][current[2].s] ^= 1;
		op.x1 = current[0].f; op.y1 = current[0].s;
		op.x2 = current[1].f; op.y2 = current[1].s;
		op.x3 = current[2].f; op.y3 = current[2].s;
		ops.push_back(op);
		tot = total();
	}

	cout << sz(ops) << "\n";

	for (Operation i : ops)
		cout << i.x1+1 << " " << i.y1+1 << " " << i.x2+1 << " " << i.y2+1 << " " << i.x3+1 << " " << i.y3+1 << "\n";
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

