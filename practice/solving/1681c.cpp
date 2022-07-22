#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// max moves is 1e4
// up to 100 elements in the arrays
// I think there will be some O(n^2) method
// Need to store operations as well

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int& i : a)
		cin >> i;
	for (int& i : b)
		cin >> i;

	vector<pair<int,int> > operations;
	
	for (int i = 0; i < n; i++) {
		int index = i, currentA = a[i], currentB = b[i];
		for (int j = i+1; j < n; j++) {
			if (a[j] < currentA || (a[j] == currentA && b[j] < currentB)) {
				currentA = a[j];
				currentB = b[j];
				index = j;
			}
		}
		if (index == i)
			continue;
		operations.push_back({i,index});
		swap(a[i],a[index]);
		swap(b[i],b[index]);
	}

	for (int i = 0; i < n-1; i++) {
		if (a[i] > a[i+1] || b[i] > b[i+1]) {
			cout << "-1\n";
			return;
		}
	}

	cout << sz(operations) << "\n";
	for (pair<int,int>& i : operations)
		cout << i.first+1 << " " << i.second+1 << "\n";
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

