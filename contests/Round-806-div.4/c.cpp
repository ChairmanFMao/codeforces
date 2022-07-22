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
	
	for (int i = 0; i < n; i++) {
		int b;
		string s;
		cin >> b >> s;
		int total = 0;
		for (char c : s)
			total += (c == 'U' ? -1 : 1);
		while (total < 0)
			total += 10;
		cout << (a[i] + total)%10 << " ";
	}
	
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

