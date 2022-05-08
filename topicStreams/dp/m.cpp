#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Unsure how I am going to get the path used to get to the end
// I think that a dfs might just work, the constraints aren't that bad
// TLE on test 11, I think the dfs didn't work that well
// Unsure why it timed out, I think it should've been good enough

const int mxN = 5e3;
vector<vector<pair<int,int> > > adj(mxN);
deque<int> current, best;
int n, m, t;

void dfs(int node, int time) {
	current.push_back(node);
	if (node == n-1) {
		if (sz(current) > sz(best)) {
			best.clear();
			for (int i = 0; i < sz(current); i++) {
				best.push_back(current.front());
				current.push_back(current.front());
				current.pop_front();
			}
		}
	} else {
		for (pair<int,int> i : adj[node])
			if (time + i.second <= t)
				dfs(i.first, time+i.second);
	}
	current.pop_back();
}

void solve() {
	cin >> n >> m >> t;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		adj[start-1].push_back({end-1,cost});
	}

	dfs(0, 0);

	int out = sz(best);
	cout << out << "\n";
	for (int i = 0; i < out; i++) {
		cout << best.front()+1 << " ";
		best.pop_front();
	}

	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

