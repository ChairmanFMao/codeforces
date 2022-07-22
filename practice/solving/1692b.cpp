#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	cin >> n;
	set<int> s;
	map<int,int> occurs;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		occurs[a]++;
		s.insert(a);
	}

	vector<int> u(all(s));
	ll out = 0;
	for (int i : u)
		out += occurs[i]-1;
	
	cout << sz(s) - out%2 << "\n";
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

