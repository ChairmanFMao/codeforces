#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just check if it is possible to turn a into b
// kinda circular
// there shouldn't be massive jumps in b
// shift it so that the minimums match
// then just brute force from there?
// could lead to O(n^2) I think tho
// start from the right move to the left O(n) maybe?

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int& i : a)
		cin >> i;
	for (int& i : b)
		cin >> i;

	// Sets all of a to be at least minimum of b
	int small = *min_element(all(b));
	for (int& i : a)
		i = max(i,small);

	for (int i = 0; i < n; i++)
		if (a[i] > b[i]) {
			cout << "NO\n";
			return;
		}

	vector<int> equal;
	for (int i = 0; i < n; i++)
		if (a[i] == b[i])
			equal.push_back(i);

	for (int i = 0; i < sz(equal); i++) {
		int start = equal[i]-1;
		if (start < 0)
			start += n;
		while (a[start] != b[start]) {
			if (a[start] <= a[(start+1)%n])
				a[start] = min(a[(start+1)%n]+1,b[start]);

			if (a[start] != b[start]) {
				cout << "NO\n";
				return;
			}
			start--;
			if (start < 0)
				start += n;
		}
	}

	cout << "YES\n";
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

