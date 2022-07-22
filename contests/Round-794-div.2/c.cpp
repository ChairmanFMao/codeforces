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

	sort(all(a));
	vector<int> newA;
	int ptr = 0, ptr2 = n/2;
	while (ptr < n/2 || ptr2 < n) {
		if (ptr < n/2) {
			newA.push_back(a[ptr]);
			ptr++;
		}
		if (ptr2 < n) {
			newA.push_back(a[ptr2]);
			ptr2++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (newA[n-1] >= newA[i] && newA[1] <= newA[i]) {
				cout << "NO\n";
				return;
			} if (newA[n-1] <= newA[i] && newA[1] >= newA[i]) {
				cout << "NO\n";
				return;
			}
		} else if (i == n-1) {
			if (newA[0] >= newA[i] && newA[n-2] <= newA[i]) {
				cout << "NO\n";
				return;
			} if (newA[0] <= newA[i] && newA[n-2] >= newA[i]) {
				cout << "NO\n";
				return;
			}
		} else {
			if (newA[i+1] >= newA[i] && newA[i-1] <= newA[i]) {
				cout << "NO\n";
				return;
			} if (newA[i+1] <= newA[i] && newA[i-1] >= newA[i]) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
	for (int i : newA)
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

