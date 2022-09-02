#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Ensure that there are no g next to b
// Fill in walls around all b
// Check that all g can make it to the exit
// just bfs from exit and make a set?

// 0 means empty
// 1 means wall
// 2 means g
// 3 means b

void solve() {
	int n, m;
	cin >> n >> m;
	int good = 0;
	vector<vector<int> > grid(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			grid[i][j] = s[j] == '.' ? 0 : s[j] == '#' ? 1 : s[j] == 'G' ? 2 : 3;
			if (grid[i][j] == 2)
				good++;
		}
	}

	// Checks for g next to b
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int flag = 0;
			if (grid[i][j] == 3) {
				if (i && grid[i-1][j] == 2)
					flag++;
				if (i<n-1 && grid[i+1][j] == 2)
					flag++;
				if (j && grid[i][j-1] == 2)
					flag++;
				if (j<m-1 && grid[i][j+1] == 2)
					flag++;
			}

			if (flag) {
				cout << "NO\n";
				return;
			}
		}
	}

	// Fills in walls around b
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 3) {
				if (i && !grid[i-1][j])
					grid[i-1][j] = 1;
				if (i<n-1 && !grid[i+1][j])
					grid[i+1][j] = 1;
				if (j && !grid[i][j-1])
					grid[i][j-1] = 1;
				if (j<m-1 && !grid[i][j+1])
					grid[i][j+1] = 1;
			}
		}
	}

	// Bfs all reachable nodes from the exit
	set<pair<int,int> > s;
	queue<pair<int,int>> q;
	q.push({n-1,m-1});

	while (!q.empty()) {
		pair<int,int> c = q.front();
		q.pop();
		if (grid[c.f][c.s] == 1 || s.count(c))
			continue;

		s.insert(c);
		if (c.f)
			q.push({c.f-1,c.s});
		if (c.f<n-1)
			q.push({c.f+1,c.s});
		if (c.s)
			q.push({c.f,c.s-1});
		if (c.s<m-1)
			q.push({c.f,c.s+1});
	}

	int goodS = 0;
	vector<pair<int,int> > u(all(s));
	for (pair<int,int> i : u) {
		if (grid[i.f][i.s] == 3) {
			cout << "NO\n";
			return;
		} if (grid[i.f][i.s] == 2)
			goodS++;
	}
	cout << (goodS == good ? "YES" : "NO") << "\n";
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

