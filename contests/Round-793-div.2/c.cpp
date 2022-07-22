#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Unsure what to do with the duplicates
// low block, high block, dupes
// Need to split the blocks somehow

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	map<int,int> m;
	for (int i : a)
		m[i]++;

	set<int> unique(all(a));
	vector<int> u(all(unique));
	int doubles = 0;
	for (int i : u)
		if (m[i] > 1)
			doubles++;

	cout << doubles + (sz(u)-doubles+1)/2 << "\n";
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

