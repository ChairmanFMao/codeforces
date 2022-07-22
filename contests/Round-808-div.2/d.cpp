#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Pre sorted in increasing order
// Brute force would lead to O(n^2 log n) time
// Maybe something logarithmic?
// I think there is a trick where stuff cancels out
// b is sorted again from smallest to largest ;-; can't cancel nicely
// I don't think that dp would be used here
// answer will always be >= 0, due to the sorting
// Counting sort? acc, mxA = 5e5 so maybe not
// I think that this might fail the main tests but idk

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	map<int,int> next, current;
	for (int i : a)
		current[i]++;
	
	for (int i = 0; i < n-1; i++) {
		if (sz(current) == 1) {
			cout << "0\n";
			return;
		}
		auto end = current.end();
		end--;
		for (auto it = current.begin(); it != current.end(); it++) {
			if (it != end) {
				auto oneUp = it; oneUp++;
				next[oneUp->f - it->f]++;
			} if (it->s > 1)
				next[0] += it->s -1;
		}
		current = next;
		next.clear();
	}

	cout << current.begin()->f << "\n";
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

