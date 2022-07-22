#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// If size is odd then mike wins
// I think its most optimal to just reduce by 1 every time

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	int smallest = *min_element(all(a)), index = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == smallest) {
			index = i;
			break;
		}

	cout << (sz(a) & 1 || index&1 ? "Mike" : "Joe") << "\n";
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

