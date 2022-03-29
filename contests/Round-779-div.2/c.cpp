#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Power of the i-1 th cyclic shift of the permutation p
// The power of a prefix maximum is the number of distinct elements in it
// There must be at a shift with a value of 1 and a value of 2
// number of test cases is quite high, need something efficient
// This current solution doesn't work

void solve() {
	int n;
	cin >> n;
	vector<int> numbers(n);
	for (int& i : numbers)
		cin >> i;

	int one = 0;
	for (int i = 0; i < n; i++)
		if (numbers[i] == 1)
			one++;

	if (one != 1) {
		cout << "NO\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (numbers[(i+1)%n] > numbers[i]) {
			if (numbers[(i+1)%n] - numbers[i] > 1) {
				cout << "NO\n";
				return;
			}
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

