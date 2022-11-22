#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Each row and column has at most 2 targets
// a boomerang can only hit a max of 3 targets
// boomerangs make a 90 turn to the right on hit
// store suitable ones for 2 and 3
// I think I could do this thing with a segtree but idk

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	vector<vector<int> > c(n);
	map<int,vector<int>> row;
	int ptr = 0;
	for (int i = 0; i < n; i++)
		if (a[i]) {
			c[i].push_back(ptr);
			row[ptr].push_back(i);
			ptr++;
		}

	// Need to use a stack to ensure later ones are maintained
	stack<int> two;
	for (int i = n-1; ~i; i--) {
		if (a[i] == 1)
			two.push(i);
		else if (a[i] == 2) {
			if (!sz(two)) {
				cout << "-1\n";
				return;
			}
			int current = two.top();
			two.pop();
			row[c[i][0]].pop_back();
			c[i][0] = c[current][0];
			row[c[i][0]].push_back(i);
		}
	}

	queue<int> three;
	for (int i = n-1; ~i; i--) {
		if (a[i] == 3) {
			if (!sz(three)) {
				cout << "-1\n";
				return;
			}
			int current = three.front();
			three.pop();
			row[current].push_back(i);
			c[current].push_back(c[i][0]);
		}
		if (sz(c[i]) != 1)
			continue;
		int flag = 0;
		for (int j : row[c[i][0]])
			if (j < i)
				flag = 1;
		if (flag)
			continue;

		three.push(i);
	}

	int total = 0;
	for (int i = 0; i < n; i++)
		total += sz(c[i]);
	cout << total << "\n";


	for (int i = 0; i < n; i++)
		for (int j = 0; j < sz(c[i]); j++)
			cout << c[i][j]+1 << " " << i+1 << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

