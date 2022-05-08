#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;
	
	a[0]++;

	for (int i = 0; i < n-1; i++) {
		if (a[i] < a[i+1]-2) {
			cout << "NO\n";
			return;
		} else if (a[i] == a[i+1]-2)
			a[i+1]--;
		else if (a[i] == a[i+1])
			a[i+1]++;

	}

	cout << "YES\n";
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

