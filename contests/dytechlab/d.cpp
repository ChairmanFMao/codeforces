#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// only optimal to rewire if needing to go along that path
// do dijkstra's and then dp with nodes
// you are basically just cutting one node out of the route
// need to do dijkstra's with traceback
// it is not that simple, you may need to bring a edge from one
// side of the graph to the other
// calculate weight saved and weight moved or smth?
// want the shortest path in terms of nodes then move edge over
// I currently have an algorithm that uses dijkstra's and gets a
// little close, I just need to find how close cheap edges are
// to the shortest path
// min along any path times the length of the path
// wire might have to just be connected to itself

struct State {
	ll node, cost, cheapest;
};

class Comp {
	public:
		bool operator() (State a, State b) {
			return a.cost < b.cost;
		}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,int>> > adj(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w; u--; v--;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}

	// This is just for shortest path
	priority_queue<State, vector<State>, Comp> pq;
	vector<ll> best(n,LONG_LONG_MAX);
	best[0] = 0;
	State s; s.node = 0; s.cost = 0; s.cheapest = INT_MAX;
	pq.push(s);
	while (sz(pq)) {
		s = pq.top();
		if (s.node == n-1) {
			cout << s.cheapest*s.cost << "\n";
			return;
		}
		pq.pop();
		for (pair<ll,ll> u : adj[s.node])
			if (best[u.f] > s.cost+1) {
				best[u.f] = s.cost+1;
				State s2;
				s2.node = u.f; s2.cost = s.cost+1; s2.cheapest = min(s.cheapest, u.s);
				pq.push(s2);
			}
	}
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

