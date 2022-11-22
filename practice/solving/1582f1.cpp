#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Something to do with dp
// The max xor value can be 512
// dp for seen, dp for last value, dp for xor value, bool value
// leads to O(n * 512 * 512) which is too large
// store next biggest for each value, like a dfs
// might be able to work with some intelligent moves?
// just need the values that are possible
// I think that the current solution will timeout
// Improved a bit with a map - tle on test 8
// Just have a map that store the xor to get to that value
// and you only need to iterate over valus that you don't have
// which then leads to O(n * 512)

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	// This goes from the xor value to the last lowest
	vector<int> seen(512,1e9);
	seen[0] = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 512; j++) {
			if (seen[a[i] ^ j] < a[i])
				seen[j] = min(seen[j], a[i]);
		}
	}

	vector<int> out;
	for (int i = 0; i < 512; i++)
		if (seen[i] != 1e9)
			out.emplace_back(i);

	cout << sz(out) << "\n";
	for (int i : out)
		cout << i << " ";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

