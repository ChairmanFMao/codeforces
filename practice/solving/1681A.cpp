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
	int m;
	cin >> m;
	vector<int> b(m);
	for (int& i : b)
		cin >> i;

	sort(all(a));
	sort(all(b));
	
	cout << (a[n-1] >= b[m-1] ? "Alice" : "Bob") << "\n";
	cout << (b[m-1] >= a[n-1] ? "Bob" : "Alice") << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

