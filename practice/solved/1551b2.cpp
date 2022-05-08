#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, k;
	cin >> n >> k;
	map<int,vector<int>> occurs;
	set<int> seen;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		occurs[a].push_back(i);
		seen.insert(a);
	}

	vector<vector<int> > attribute(k);
	int aptr = 0;
	vector<int> u(all(seen));
	for (int i : u) {
		if (sz(occurs[i]) >= k) {
			for (int j = 0; j < k; j++)
				attribute[j].push_back(occurs[i][j]);
		}
		else {
			for (int j = 0; j < sz(occurs[i]); j++) {
				attribute[aptr].push_back(occurs[i][j]);
				aptr = (aptr + 1) % k;
			}
		}
	}

	int smallest = 1e9;
	for (int i = 0; i < k; i++)
		smallest = min(smallest, sz(attribute[i]));
	
	vector<int> out(n, 0);
	for (int i = 0; i < k; i++)
		for (int j = 0; j < smallest; j++)
			out[attribute[i][j]] = i+1;

	for (int i : out)
		cout << i << " ";
	cout << "\n";
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

