#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> out;
	for (int j = 0; j < m/2; j++) {
		if (j & 1) {
			out.push_back(1);
			out.push_back(0);
		} else {
			out.push_back(0);
			out.push_back(1);
		}
	}

	for (int i = 0; i < n/2; i++) {
		for (int j : out)
			cout << (i & 1 ? j : j^1) << " ";
		cout << "\n";
		for (int j : out)
			cout << (i & 1 ? j^1 : j) << " ";
		cout << "\n";
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

