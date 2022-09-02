#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I think that this can be done efficiently with dp
// We would kinda do a dfs from the root and store values along the way
// This would lead to an O(n + m) calculation due to the dfs
// Problem is slightly different to what I was thinking but I don't think its that bad
// just n binary searches? O(n log n) probably

struct Edge {
	int red, blue, target;
};

const int mxN = 2e5;
vector<vector<Edge> > adj(mxN);
vector<int> out(mxN);

vector<ll> prefix = {0};
ll bTotal = 0;

int bs() {
	int lower = 0, upper = sz(prefix), mid = 0, flag = 0;
	while (lower < upper) {
		if (flag)
			break;
		if (lower == upper - 1)
			flag = 1;

		mid = (lower+upper)/2;

		if (prefix[mid] <= bTotal)
			lower = mid;
		else
			upper = mid;
	}

	return lower;
}

void dfs(int node) {
	if (node)
		out[node] = bs();
	for (Edge u : adj[node]) {
		bTotal += u.blue;
		prefix.push_back(prefix[sz(prefix)-1] + u.red);
		dfs(u.target);
		bTotal -= u.blue;
		prefix.pop_back();
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		out[i] = 0;
	}
	for (int i = 0; i < n-1; i++) {
		int p, a, b;
		cin >> p >> a >> b;
		p--;
		Edge e;
		e.blue = a; e.red = b; e.target = i+1;
		adj[p].push_back(e);
	}

	dfs(0);

	for (int i = 1; i < n; i++)
		cout << out[i] << " \n"[i == n-1];
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

