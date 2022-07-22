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

	int zero = 0, easy = 0;
	set<int> seen;
	for (int i : a) {
		if (!i) {
			zero++;
			easy = 1;
		} if (seen.count(i))
			easy = 1;
		seen.insert(i);
	}

	cout << n-zero + (easy?0:1) << "\n";
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

