#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n,vector<int>(m));
	for (vector<int>& i : a)
		for (int& j : i)
			cin >> j;

	for (int i = n-1; ~i; i--)
		for (int j = m-1; ~j; j--)
			if (!a[i][j])
				a[i][j] = min(a[i+1][j],a[i][j+1])-1;

	ll out = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool e = i > 0 && a[i-1][j] >= a[i][j];
			bool b = j > 0 && a[i][j-1] >= a[i][j];
			bool c = i < n-1 && a[i+1][j] <= a[i][j];
			bool d = j < m-1 && a[i][j+1] <= a[i][j];
			if (e||b||c||d) {
				cout << "-1\n";
				return;
			}
			out += a[i][j];
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

