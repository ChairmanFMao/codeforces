#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Attempting new approach I discussed with dad
// Still TLE on test 9 even with optimisations
// Ended up looking at the solution after ~3 hours ish
// Its just a bfs with caching - I did something very like this
// The problem wasn't the idea, it was just implementation
// This solution works by traversing all of the points that are part of
// the set and are contiguous, this is much faster than a bfs

const vector<int> dx = {1,-1,0,0}, dy = {0,0,1,-1};

void solve() {
	int n;
	cin >> n;
	vector<pair<int,int> > points(n);
	map<pair<int,int>, pair<int,int> > m;
	set<pair<int,int> > lookup;
	for (int i = 0; i < n; i++) {
		pair<int,int> a;
		cin >> a.first >> a.second;
		points[i] = a;
		lookup.insert(a);
	}

	queue<pair<int,int> > q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			int newx = points[i].first+dx[j], newy = points[i].second+dy[j];
			if (lookup.count({newx,newy}))
				continue;
			m[points[i]] = {newx,newy};
			q.push(points[i]);
			break;
		}
	}

	while (!q.empty()) {
		pair<int,int> c = q.front();
		q.pop();
		if (!lookup.count(c))
			continue;
		
		for (int i = 0; i < 4; i++) {
			int newx = c.first+dx[i], newy = c.second+dy[i];

			if (!lookup.count({newx,newy}) || m.count({newx,newy}))
				continue;

			m[{newx,newy}] = m[{c.first,c.second}];
			q.push({newx,newy});
		}
	}

	for (int i = 0; i < n; i++) {
		cout << m[points[i]].first << " " << m[points[i]].second << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "\n";
	solve();
}

