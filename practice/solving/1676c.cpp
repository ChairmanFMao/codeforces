#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int> > all;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vector<int> total;
		for (char c : s)
			total.push_back(c-97);
		all.push_back(total);
	}

	int out = 1e9;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int dif = 0;
			for (int k = 0; k < m; k++)
				dif += abs(all[i][k] - all[j][k]);
			out = min(out,dif);
		}
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

