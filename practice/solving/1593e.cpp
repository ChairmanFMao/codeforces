#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Need to find all that are of dist k from an edge
// wa test 2, expected 1, found 0
// unsure what happens when the tree splits
// fell for a mistake
// found the edge case in comments
// tle on test 8
// tle on test 15 with optimisation

void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<int> > adj(n);
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}

	vector<int> seen(n,0);
	queue<pair<int,int> > q, possible;
	for (int i = 0; i < n; i++)
		if (sz(adj[i]) <= 1)
			q.push({i,k});

	while (k-- && sz(q)) {
		set<int> already;
		while (sz(q)) {
			pair<int,int> current = q.front();
			q.pop();
			if (!current.s || seen[current.f])
				continue;
			seen[current.f] = 1;
			for (int u : adj[current.f])
				if (!seen[u] && !already.count(u)) {
					possible.push({u,current.s-1});
					already.insert(u);
				}
		}

		set<int> already2;
		while (sz(possible)) {
			pair<int,int> current = possible.front();
			possible.pop();
			int neighbors = 0;
			for (int u : adj[current.f])
				if (!seen[u])
					neighbors++;
			if (neighbors <= 1 && !already2.count(current.f)) {
				q.push(current);
				already2.insert(current.f);
			}
		}
	}

	int out = 0;
	for (int i : seen)
		out += !i;

	cout << out << "\n";
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

