#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// All values set to zero
// Can only increase the value of all the array
// Can decrease ranges to left or right of point in array
// It can be beneficial to not undo moves
// Maybe try to match all the numbers to the same negative value
// Order of operations doesn't matter
// I don't think that it is greedy

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;
	
	ll smallest = INT_MAX, index = 0;
	for (int i = 0; i < n; i++)
		if (a[i] < smallest) {
			index = i;
			smallest = a[i];
		}

	ll out = 0, alter = 0;
	for (int i = 0; i < index; i++) {
		alter = min(smallest-a[i],alter);
		a[i] -= alter;
		if (a[i] > smallest) {
			alter += a[i]-smallest;
			out += a[i] - smallest;
		} else if (a[i] < smallest) {
			out += smallest - a[i];
			smallest = a[i];
		}
	}

	alter = 0;
	for (int i = n-1; i >= index; i--) {
		alter = min(smallest-a[i],alter);
		a[i] -= alter;
		if (a[i] > smallest) {
			alter += a[i] - smallest;
			out += a[i] - smallest;
		} else if (a[i] < smallest) {
			out += smallest - a[i];
			smallest = a[i];
		}
	}

	out += abs(smallest);
	cout << out << "\n";
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

