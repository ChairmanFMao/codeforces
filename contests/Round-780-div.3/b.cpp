#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int n;
	cin >> n;
	vector<int> numbers(n);
	for (int& i : numbers)
		cin >> i;
	
	if (n == 1) {
		cout << (numbers[0] == 1 ? "YES" : "NO") << "\n";
		return;
	}

	sort(numbers.begin(),numbers.end());
	cout << (abs(numbers[n-1] - numbers[n-2]) > 1 ? "NO" : "YES") << "\n";
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

