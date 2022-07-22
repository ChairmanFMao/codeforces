#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// only segments of different colours can be connected
// O(n^2) time will not be good enough here
// MLE on pretest 3

const int mxN = 2e5;
vector<int> adj[mxN];
bool seen[mxN];

struct Segment {
	int start;
	int end;
	int colour;
};

void dfs(int index) {
	seen[index] = 1;
	for (int i = 0; i < sz(adj[index]); i++)
		if (!seen[adj[index][i]])
			dfs(adj[index][i]);
}

void solve() {
	memset(seen, 0, sizeof seen);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		adj[i].clear();

	vector<Segment> seg(n);
	for (Segment& s : seg)
		cin >> s.colour >> s.start >> s.end;

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (((seg[i].start >= seg[j].start && seg[i].start <= seg[j].end) || (seg[j].start >= seg[i].start && seg[j].start <= seg[i].end)) && seg[j].colour != seg[i].colour) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	int out = 0;
	for (int i = 0; i < n; i++)
		if (!seen[i]) {
			dfs(i);
			out++;
		}

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

