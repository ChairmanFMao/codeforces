#include <bits/stdc++.h>
using namespace std;
#define ll long long

// t <= 500 and n <= 2e3 - very small constraints, some kind of brute force
// Fix elements from the right to left, I think this isn't that hard...

void solve() {
	int n;
	cin >> n;
	deque<int> start, target;
	vector<int> uses(n, 0);
	for (int i = 0,a; i < n; i++) {
		cin >> a;
		target.push_front(i+1);
		start.push_front(a);
	}

	for (int i = n-1; ~i; i--) {
		while (start.front() != target.front()) {
			uses[i]++;
			start.push_front(start.back());
			start.pop_back();
		}
		start.pop_front();
		target.pop_front();
	}

	for (int i : uses)
		cout << i << " ";
	cout << "\n";
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

