#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// I have done a problem like this before
// I forgotten how to do it though
// Adel can't buy all the cupcakes which is very annoying
// Just need to iterate twice: starting from 0 and 1 for n-1 moves
// This ensures the 1 to n range isn't included

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	ll out = 0;
	for (int i : a)
		out += i;

	ll output = INT_MIN, current = 0;
	for (int i = 1; i < n; i++) {
		if (current + a[i] <= 0)
			current = 0;
		else
			current += a[i];
		output = max(output, current);
	}

	current = 0;
	for (int i = 0; i < n-1; i++) {
		if (current + a[i] <= 0)
			current = 0;
		else
			current += a[i];
		output = max(output,current);
	}

	cout << (output < out ? "YES" : "NO") << "\n";
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

