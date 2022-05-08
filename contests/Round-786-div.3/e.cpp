#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// This problem got hacked and I'm not really sure where I went wrong
// Just didn't check all combinations properly, be more careful

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	int smallest = 1e8, second = 1e9;
	for (int i = 0; i < n; i++) {
		if (a[i] < smallest) {
			second = smallest;
			smallest = a[i];
		} else if (a[i] < second) {
			second = a[i];
		}
	}

	int best = smallest/2 + smallest%2 + second/2 + second%2;
	
	for (int i = 0; i < n-2; i++) {
		int smaller = min(a[i],a[i+2]), bigger = max(a[i],a[i+2]);
		best = min(best, smaller + (bigger-smaller+1)/2);
	}

	for (int i = 0; i < n-1; i++)
		best = min(best, max((a[i] + 1)>>1, max((a[i+1]+1)>>1, (a[i] + a[i+1] + 2)/3)));

	cout << best << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "\n";
	solve();
}

