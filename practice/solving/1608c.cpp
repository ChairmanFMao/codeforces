#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Strength on the map
// Just need to beat strongest on other map
// there are some more complex routes, wa on test 2
// I can think of an O(n^2) method I think with kinda dfs
// I think with some sorts we can get O(n log n) for precalc
// somehow getting mle
// wa on test 21 ;-;

bool comp(pair<int,int> a, pair<int,int> b) {
	return a.f < b.f;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int& i : a)
		cin >> i;
	for (int& i : b)
		cin >> i;

	vector<vector<pair<int,int> > > sorting(2,vector<pair<int,int>>(n));
	vector<map<int,int> > loc(2), loc2(2);
	for (int i = 0; i < n; i++) {
		sorting[0][i] = {a[i],i};
		sorting[1][i] = {b[i],i};
	}

	sort(all(sorting[0]),comp);
	sort(all(sorting[1]),comp);
	for (int i = 0; i < n; i++) {
		loc[0][i] = sorting[0][i].s;
		loc[1][i] = sorting[1][i].s;
		loc2[0][sorting[0][i].s] = i;
		loc2[1][sorting[1][i].s] = i;
	}

	vector<int> out(n,0);
	vector<vector<int> > seen(n,vector<int>(2,0));
	queue<pair<int,int>> q;
	// First is index, second is a(0) or b(1);
	q.push({n-1,0});
	q.push({n-1,1});
	seen[n-1][0] = seen[n-1][1] = 1;
	while (sz(q)) {
		pair<int,int> current = q.front();
		q.pop();

		// This should be right
		out[sorting[current.s][current.f].s] = 1;

		int start = loc2[current.s][loc[current.s^1][current.f]];
		start++;
		while (start < n && !seen[start][current.s^1]) {
			q.push({start,current.s^1});
			seen[start][current.s^1] = 1;
			start++;
		}
	}

	for (int i : out)
		cout << (char)(i+48);
	cout << '\n';
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

