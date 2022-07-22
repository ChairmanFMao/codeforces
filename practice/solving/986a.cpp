#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Kinda like the travelling salesman problem
// Undirected connnected potentially cyclic graph
// We are doing a bfs for each colour from their nodes
// This should work in O(k n) time
// I had an error with the seen flag which led to a wa

void solve() {
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;
	vector<vector<int> > adj(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<vector<int> > shortestGoods(n,vector<int>(k+1,INT_MAX));

	map<int, vector<int> > goodsToNodes;
	for (int i = 0; i < n; i++)
		goodsToNodes[a[i]].push_back(i);

	for (int i = 1; i <= k; i++) {
		vector<int> seen(n,0);
		queue<pair<int,int> > q;
		for (int j : goodsToNodes[i]) {
			q.push({j,0});
			seen[j] = 1;
		}

		while (!q.empty()) {
			pair<int,int> current = q.front();
			q.pop();
			shortestGoods[current.first][i] = current.second;
			for (int j : adj[current.first])
				if (!seen[j]) {
					q.push({j,current.second+1});
					seen[j] = 1;
				}
		}
	}

	for (int i = 0; i < n; i++) {
		int out = 0;
		sort(all(shortestGoods[i]));
		for (int j = 0; j < s; j++)
			out += shortestGoods[i][j];
		cout << out << " ";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

