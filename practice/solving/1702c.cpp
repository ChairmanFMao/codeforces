#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> u(n);
	for (int& i : u)
		cin >> i;

	map<int,int> first, last;
	for (int i = 0; i < n; i++) {
		if (!first[u[i]])
			first[u[i]] = i+1;
		last[u[i]] = i+1;
	}

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		cout << (first[a] < last[b] && first[a] && first[b] ? "YES" : "NO") << "\n";
	}
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

