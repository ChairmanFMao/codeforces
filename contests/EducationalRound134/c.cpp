#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Creating b from a
// finding the closest values above for the min
// need to ensure there aren't numbers too big
// min bit is easy, max bit is harder
// need to pair numbers with their biggest possible
// need numbers to take their lowest possible except current
// first available free, don't want O(n^2) tho
// highest free with an id of your kind
// wa on test 2 currently
// might stack and fill, need to cater for this

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int& i : a)
		cin >> i;
	for (int& i : b)
		cin >> i;

	// This section is assured to work fine
	vector<int> lowest(n), lowind(n);
	for (int i = 0; i < n; i++) {
		int low = 0, high = n-1, mid = 0, f = 0;
		while (low <= high) {
			if (f)
				break;
			if (low == high)
				f = 1;
			mid = (low+high)/2;
			if (b[mid] < a[i])
				low = mid+1;
			else
				high = mid;
		}
		lowest[i] = b[mid] - a[i];
		lowind[i] = mid;
	}

	for (int i = 0; i < n; i++)
		cout << lowest[i] << " ";
	cout << "\n";

	// This is what I am less sure about
	// need to not have clustering and an O(n) method probs
	// This currently is O(n^2) due to clustering
	vector<int> highest(n), used(n,0);
	stack<int> free;
	int high = n-1;
	for (int i = n-1; ~i; i--) {
		highest[i] = high;
		int ptr = lowind[i];
		if (!used[ptr]) {
			used[ptr] = 1;
			if (!used[ptr+1] && ptr != n-1)
				free.push(ptr+1);
		} else {
			int c = free.top();
			free.pop();
			used[c] = 1;
			if (!used[c+1])
				free.push(c+1);
		}
		while (used[high])
			high--;
	}

	for (int i = 0; i < n; i++)
		cout << b[highest[i]] - a[i] << " \n"[i==n-1];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

