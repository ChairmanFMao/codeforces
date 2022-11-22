#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Unweighted tree, needs to go from x to y and pass through
// all of the points within a in the minimum time possible
// its a tree so there is a set path between two nodes
// just need to get the shortest path
// traverse from x to y and set val as 0 across the path
// move inwards from all of the a nodes and add double their
// distance from the line, could move out from the line and it
// might be easier actually
// moving inwards would make it right
// just need to find where the lines inwards intersect
// priority queue sorted by the distances from the thing and merge
// I think should work
// wa on test 2 with improved algorithm
// more wa with debugging
// Finally got accepted without looking at any test cases in 1hr

const int mxN = 2e5;
int n, k, x, y;
vector<vector<int> > adj(mxN);
vector<int> dist(mxN,INT_MAX);
stack<int> st;

class Comp {
	public:
		bool operator() (int a, int b) {
			return dist[a] < dist[b];
		}
};

int dfs(int node, int parent) {
	st.push(node);
	if (node == y)
		return 1;
	for (int u : adj[node]) {
		if (u != parent)
			if (dfs(u, node))
				return 1;
	}
	st.pop();
	return 0;
}

void solve() {
	cin >> n >> k >> x >> y; x--; y--;
	vector<int> a(k);
	for (int& i : a) {
		cin >> i; i--;
	}
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		dist[i] = INT_MAX;
	}
	for (int i = 0; i < n-1; i++) {
		int b, c; cin >> b >> c; b--; c--;
		adj[b].emplace_back(c);
		adj[c].emplace_back(b);
	}

	dfs(x, -1);

	int out = sz(st)-1;
	queue<int> q;
	vector<int> p;
	while (sz(st)) {
		int current = st.top();
		st.pop();
		p.emplace_back(current);
		dist[current] = 0;
		q.push(current);
	}

	while (sz(q)) {
		int current = q.front();
		q.pop();
		for (int u : adj[current])
			if (dist[u] == INT_MAX) {
				dist[u] = dist[current]+1;
				q.push(u);
			}
	}

	set<int> s(all(a));
	vector<int> u(all(s));
	priority_queue<int,vector<int>, Comp> pq;
	vector<int> w(n,0);
	for (int i : u)
		pq.push(i);

	// Now need to move inwards from further out nodes
	set<int> seen;
	while (sz(pq)) {
		int current = pq.top();
		pq.pop();
		if (seen.count(current))
			continue;
		seen.insert(current);
		for (int u : adj[current])
			if (dist[u] < dist[current]) {
				// Unsure if these two transitions here are right
				if (w[u])
					w[u] += w[current]+2;
				else
					w[u] += w[current]+2;

				pq.push(u);
				break;
			}
	}

	//cout << "w: ";
	//for (int i = 0; i < n; i++)
		//cout << w[i] << " ";
	//cout << "\n";

	for (int i : p)
		out += w[i];

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

