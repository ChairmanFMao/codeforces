#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// I can think of an O(n^3) but, that will probably timeout
// You actually only need to output one pair
// However, the conditions needs to hold for all k

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	int big = 0, bind = 0, small = 1e9+1, sind = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < small) {
			small = a[i];
			sind = i+1;
		} if (a[i] > big) {
			big = a[i];
			bind = i+1;
		}
	}
	
	cout << sind << " " << bind << "\n";
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

