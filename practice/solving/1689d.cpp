#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Encroach from all of the corners inwards
// I managed to solve it with just the hint from the editorial and some
// discussion with others
const int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<bool> > grid(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			grid[i][j] = s[j] == 'B';
	}

	vector<pair<int,int> > corners, important;
	corners.push_back({0,0});
	corners.push_back({n-1,0});
	corners.push_back({0,m-1});
	corners.push_back({n-1,m-1});
	
	for (int i = 0; i < sz(corners); i++) {
		vector<vector<int> > value(n, vector<int>(m,0));
		value[corners[i].first][corners[i].second] = 1;
		queue<pair<int,int> > q;
		q.push({corners[i].first,corners[i].second});
		while (!q.empty()) {
			pair<int,int> current = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) {
				if (current.first+dy[j] < 0 || current.second + dx[j] < 0 || current.first + dy[j] >= n || current.second + dx[j] >= m)
					continue;
				if (!value[current.first+dy[j]][current.second+dx[j]]) {
					value[current.first+dy[j]][current.second+dx[j]] = value[current.first][current.second]+1;
					q.push({current.first+dy[j],current.second+dx[j]});

				}
			}
		}

		int lowest = INT_MAX;
		pair<int,int> location = {0,0};
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (value[i][j] < lowest && grid[i][j]) {
					lowest = value[i][j];
					location = {i,j};
				}
		important.push_back(location);
	}

	int out = INT_MAX;
	pair<int,int> location;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int current = 0;
			for (int k = 0; k < sz(important); k++)
				current = max(current, abs(i-important[k].first)+abs(j-important[k].second));
			if (current < out) {
				out = current;
				location = {i,j};
			}
		}

	cout << location.first+1 << " " << location.second+1 << "\n";
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

