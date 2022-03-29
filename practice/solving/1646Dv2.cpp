
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN = 2e5;
vector<vector<int>> adj(mxN+1);
int values[mxN+1];
// 0 means not set, 1 means good, 2 means bad
int colour[mxN+1];
int n, totalUsed = 0, current;

// TLE on test 6, unsure where the problem is
// can't tell if it is the algorithm or just totalUsed isn't being incremented enough

// Returns the number of neighbors for a node that are yet to be set
int neighbors(int n) {
	int out = 0;
	for (int i : adj[n]) {
		if (!colour[i])
			out++;
		if (colour[i] == 1)
			out += 2;
	}
	return out;
}

// Returns if a node has any neighbors that are set
int invalid(int n) {
	for (int i : adj[n])
		if (colour[i] == 1)
			return 1;
	return 0;
}

// Returns the total of a node's neighbors
int goodTotal(int n) {
	int out = 0;
	for (int i : adj[n])
		out += values[i];
	return out;
}

// Returns the neighboring node
int neighboringNode(int n) {
	for (int i : adj[n])
		if (!colour[i])
			return i;
	return 0;
}

void solve() {
	for (int i = 0; i <= mxN; i++)
		values[i] = 1;
	memset(colour, 0, sizeof colour);
	cin >> n;
	for (int i = 0,a,b; i < n-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	queue<int> q;
	queue<pair<int,int> > special;
	while (totalUsed < n) {
		for (int i = 1; i <= n; i++) {
			if (!colour[i]) {
				if (neighbors(i) == 1) {
					if (neighbors(neighboringNode(i)) == 1)
						special.push({i,neighboringNode(i)});
					else
						q.push(i);
				} else if (neighbors(i) == 0) {
					if (invalid(i)) {
						colour[i] = 2;
						values[i] = 1;
					} else {
						colour[i] = 1;
						values[i] = goodTotal(i);
					}
					totalUsed++;
				}
			}
		}

		while (!q.empty()) {
			current = q.front();
			q.pop();
			if (!colour[adj[current][0]]) {
				values[adj[current][0]] = 1;
				colour[adj[current][0]] = 2;
				totalUsed++;
			}
			values[current] = goodTotal(current);
			colour[current] = 1;
			totalUsed++;
		}

		while (!special.empty()) {
			pair<int,int> temp = special.front();
			int first = temp.first, second = temp.second;
			special.pop();
			
			if (colour[first] || colour[second])
				continue;

			if (goodTotal(first) <= 2 && goodTotal(second) <= 2) {
				values[first] = 1;
				values[second] = 1;
				colour[first] = 1;
				colour[second] = 1;
			} else {
				if (goodTotal(first) > goodTotal(second)) {
					values[first] = 1;
					colour[first] = 2;
					colour[second] = 1;
					values[second] = goodTotal(second);
				} else {
					values[second] = 1;
					colour[second] = 2;
					colour[first] = 1;
					values[first] = goodTotal(first);
				}
			}
			totalUsed += 2;
		}
	}
	
	int weight = 0, good = 0;
	for (int i = 1; i <= n; i++) {
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

