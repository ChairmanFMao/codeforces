#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n, c;
	cin >> n >> c;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	map<int,int> m;
	set<int> u;
	for (int i : a) {
		m[i]++;
		u.insert(i);
	}
	
	vector<int> unique(all(u));
	int out = 0;
	for (int i : unique)
		out += min(m[i],c);

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

