#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// I think that O(n^2) will timeout and it does
// mxn*m = 1e5 however, there are not multiple test cases
// We can't use O(n^2), trying to think of a way to make it faster
// What if you separate it out into vertical and horizontal distances
// With a 1D vector how do you get the abs distance of each pair fast
// This solution took me about 90 mins to get, it actually worked well
// My solution was actually very close to what the editorial did
// Very happy that I managed to solve it without help

struct P {
	map<int,int> x;
	set<int> xKey;
	map<int,int> y;
	set<int> yKey;
};

void solve() {
	int n, m;
	cin >> n >> m;
	map<int,P> colours;
	set<int> occurs;
	vector<vector<int> > grid(n, vector<int> (m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			occurs.insert(grid[i][j]);
			colours[grid[i][j]].x[j]++;
			colours[grid[i][j]].y[i]++;
			colours[grid[i][j]].xKey.insert(j);
			colours[grid[i][j]].yKey.insert(i);
		}

	ll out = 0;
	vector<int> u(all(occurs));
	for (int i : u) {
		vector<int> iter(all(colours[i].xKey));
		sort(all(iter));
		ll current = 0, totalOccur = 0;
		for (int j = 0; j < sz(iter); j++) {
			current += colours[i].x[iter[j]]*abs(iter[j] - iter[0]);
			totalOccur += colours[i].x[iter[j]];
		}

		for (int j = 0; j < sz(iter)-1; j++) {
			out += current*(colours[i].x[iter[j]]);
			totalOccur -= colours[i].x[iter[j]];
			current -= totalOccur*(iter[j+1]-iter[j]);
		}

		vector<int> iter2(all(colours[i].yKey));
		sort(all(iter2));
		current = 0, totalOccur = 0;
		for (int j = 0; j < sz(iter2); j++) {
			current += colours[i].y[iter2[j]]*abs(iter2[j] - iter2[0]);
			totalOccur += colours[i].y[iter2[j]];
		}

		for (int j = 0; j < sz(iter2)-1; j++) {
			out += current*(colours[i].y[iter2[j]]);
			totalOccur -= colours[i].y[iter2[j]];
			current -= totalOccur*(iter2[j+1]-iter2[j]);
		}
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "\n";
	solve();
}

