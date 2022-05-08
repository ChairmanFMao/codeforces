#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// try to minimize score
// In each operation, score += ai / aj
// Also all of the elements left over are summed up
// There is an edge case where the greedy isn't working
// I think you can make a very inefficient algorithm and it will work
// due to the very low constraints for the problem
// perhaps start with the best operation on the left and work to right
// working to the right works for all except one case

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<bool> used(n, 0);
	for (int& i : a)
		cin >> i;
	
	ll score = 0;
	sort(all(a));
	for (int i = 0; i < n-k-k; i++)
		score += a[i];

	for (int i = 0; i < k; i++)
		score += a[n-k-k+i] / a[n-k+i];

	cout << score << "\n";
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

