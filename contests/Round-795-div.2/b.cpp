#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// No student gets their own shoes
// There need to be at least 2 of every size

void solve() {
	int n;
	cin >> n;
	map<int,vector<int>> m;
	set<int> u;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		m[a].push_back(i);
		u.insert(a);
	}
	
	vector<int> output(n);
	vector<int> unique(all(u));
	for (int i = 0; i < sz(unique); i++) {
		if (sz(m[unique[i]]) <= 1) {
			cout << "-1\n";
			return;
		}
		for (int j = 0; j < sz(m[unique[i]]); j++) {
			output[m[unique[i]][j]] = m[unique[i]][(j+1)%sz(m[unique[i]])]+1;
		}
	}

	for (int i = 0; i < n; i++)
		cout << output[i] << " ";
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

