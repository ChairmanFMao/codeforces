#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

bool comp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b) {
	return a.f < b.f;
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	// There are m runners
	// Just need the m smallest values assigned well
	// The rest of them don't matter
	vector<vector<int> > grid(n,vector<int>(m));
	vector<vector<int> > used(n,vector<int>(m,0));

	vector<pair<int,pair<int,int> > > values;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			values.push_back({grid[i][j], {i,j}});
		}
	}

	sort(all(values), comp);
	vector<vector<int> > out(n,vector<int>(m,0));
	for (int i = 0; i < m; i++) {
		out[(values[i].s).f][i] = values[i].f;

		used[(values[i].s).f][(values[i].s).s] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!out[i][j])
				for (int k = 0; k < m; k++)
					if (!used[i][k]) {
						used[i][k] = 1;
						out[i][j] = grid[i][k];
						break;
					}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << out[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

