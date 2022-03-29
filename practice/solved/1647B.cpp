#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Constraints aren't that intensive, brute force

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int> > grid(n, vector<int>(m));
	vector<vector<bool> > used(n, vector<bool>(m, 0));
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			grid[i][j] = stoi(s.substr(j,1));
		}
	}

	queue<pair<int,int> > q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] && !used[i][j]) {
				int size = 0, minI = i, maxI = i, minJ = j, maxJ = j;
				q.push({i,j});
				while (!q.empty()) {
					pair<int,int> current = q.front();
					int f = current.first, s = current.second;
					q.pop();

					if (f < 0 || f >= n || s < 0 || s >= m || !grid[f][s])
						continue;
					
					minI = min(minI, f);
					maxI = max(maxI, f);
					minJ = min(minJ, s);
					maxJ = max(maxJ, s);
					
					if (used[f][s])
						continue;
					
					used[f][s] = 1;
					size++;
					q.push({f+1,s});
					q.push({f-1,s});
					q.push({f,s-1});
					q.push({f,s+1});
				}
				if (size != (maxI - minI+1) * (maxJ - minJ+1)) {
					cout << "NO\n";
					return;
				}
			}
		}
	}
	cout << "YES\n";
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

