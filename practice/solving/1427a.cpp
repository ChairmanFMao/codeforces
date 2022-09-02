#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	int total = 0;
	for (int i : a)
		total += i;

	if (total == 0) {
		cout << "NO\n";
		return;
	} else if (total > 0)
		sort(all(a),greater<int>());
	else 
		sort(all(a));

	cout << "YES\n";
	for (int i : a)
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

