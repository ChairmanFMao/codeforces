#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	cin >> n;
	cout << "2\n1 ";
	vector<bool> used(n+1,0);
	for (int i = 2; i <= n; i++) {
		int current = i;
		while (current <= n && !used[current]) {
			cout << current << " ";
			used[current] = 1;
			current <<= 1;
		}
	}

	for (int i = 2; i <= n; i++)
		if (!used[i])
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

