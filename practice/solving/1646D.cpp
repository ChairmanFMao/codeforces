#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN = 2e5;
vector<vector<int>> adj(mxN+1);
int values[mxN+1];
// 0 means not set, 1 means good, 2 means bad
int colour[mxN+1];
int n, totalUsed = 0, current;

// Currently the number of good and weight are both underestimated
// Potentially thinking of taking off the leaves and then getting a new graph and
// then just pruning those leaves until the whole graph is processed

// Returns the number of neighbors for a node that are yet to be set
int neighbors(int n) {
	int out = 0;
	for (int i : adj[n])
		if (!colour[i])
			out++;
	return out;
}

void solve() {
	memset(values, 0, sizeof values);
	memset(colour, 0, sizeof colour);
	cin >> n;
	for (int i = 0,a,b; i < n-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	// This is just to cater to the edge case
	if (n == 2) {
		cout << "2 2\n1 1";
		return;
	}
		
	// Gets all of the leaf nodes in a starting queue
	queue<int> q;
	for (int i = 1; i <= mxN; i++)
		if (adj[i].size() == 1) {
			q.push(adj[i][0]);
			values[i] = 1;
			values[adj[i][0]] = 1;
			colour[i] = 1;
			colour[adj[i][0]] = 2;
		}
	
	// Keeps processing the queue while there are nodes to be done
	while (!q.empty()) {
		current = q.front();
		q.pop();

		int subtotal = 0, unused = 0;
		bool invalid = 0;
		if (colour[current] == 1) {
			for (int i : adj[current]) {
				subtotal += values[i];
				if (!colour[i])
					unused++;
				if (colour[i] == 1)
					invalid = 1;
			}
			values[current] = invalid ? 1 : unused + subtotal;
			if (invalid)
				colour[current] = 2;
		} else
			values[current] = 1;

		for (int i : adj[current])
			if (!colour[i]) {
				colour[i] = 3 - colour[current];
				q.push(i);
			}
	}

	int weight = 0, good = 0;
	for (int i = 1; i < mxN; i++) {
		weight += values[i];
		good += colour[i] == 1 ? 1 : 0;
	}

	cout << good << " " << weight << "\n";
	for (int i = 1; i <= n; i++)
		cout << values[i] << " ";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "\n";
	solve();
}

