#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Visit n-1 shops, there are m shops and n-1 friends
// Just need to output the max value of a
// a is the minimum joy that any friend receives
// Could make a brute force that just gets every best shop and finds
// the shop to cut that leads to the least change
// However, that would have horrible time complexity, t = 1e4

void solve() {
	int n, m;
	cin >> m >> n;
	vector<vector<int> > grid(m, vector<int> (n));
	for (vector<int>& i : grid)
		for (int& j : i)
			cin >> j;

	
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

