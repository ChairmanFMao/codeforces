#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Currently experiencing a wierd error
// Looked at editorial, you need to go from end to start
// apart from that I did good
// We just needed to assume that they went to the worst option

struct State {
	int cost;
	int node;
};

class Compare {
	public:
		bool operator() (State a, State b) {
			return a.cost > b.cost;
		}
};

const int mxN = 2e5;
vector<vector<int> > adj(mxN);
vector<int> shortest(mxN), magnitude(mxN);

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		magnitude[i] = 0;
		shortest[i] = INT_MAX;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[b].push_back(a);
		magnitude[a]++;
	}

	// This is just dijkstra's
	priority_queue<State, vector<State>, Compare> q;
	State s; s.cost = 0; s.node = n-1;
	q.push(s);
	shortest[n-1] = 0;
	while (!q.empty()) {
		State c = q.top(); q.pop();
		if (c.node == 0) {
			cout << c.cost << "\n";
			return;
		}
		if (c.cost > shortest[c.node])
			continue;

		for (int i : adj[c.node]) {
			if (shortest[c.node] + magnitude[i] < shortest[i]) {
				shortest[i] = shortest[c.node]+magnitude[i];
				s.cost = shortest[i]; s.node = i;
				q.push(s);
			}
			--magnitude[i];
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "\n";
	solve();
}

