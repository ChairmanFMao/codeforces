#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

const int mxN = 4e3;
int out = 0;
int colours[mxN+5];
vector<vector<int> > adj(mxN+1);

// First is the white number, second is the black number
pair<int,int> dfs(int current) {
	if (!sz(adj[current]))
		return {!colours[current],colours[current]};

	pair<int,int> count = {!colours[current],colours[current]};
	for (int i : adj[current]) {
		pair<int,int> returned = dfs(i);
		if (returned.first == returned.second)
			out++;
		count.first += returned.first;
		count.second += returned.second;
	}

	if (current == 1)
		if (count.first == count.second)
			out++;
	return count;
}

void solve() {
	memset(colours, 0, sizeof colours);
	for (int i = 0; i < mxN; i++)
		adj[i].clear();
	out = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a;
		cin >> a;
		adj[a].push_back(i+2);
	}
	string s;
	cin >> s;
	for (int i = 1; i < sz(s)+1; i++)
		colours[i] = (int)(s[i-1] == 'B');
	
	dfs(1);

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

