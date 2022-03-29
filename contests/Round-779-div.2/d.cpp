#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Looked at some solutions right after the contest ended, I spend 1hr 30 on this during the contest - Geothermal solutions are very cool
// You are just looked at the bits and checking if there are any alterations

void solve() {
	ll l, r;
	cin >> l >> r;
	vector<int> numbers(r-l+1);
	for (int& i : numbers)
		cin >> i;
	
	vector<int > oldBits(17, 0), newBits(17,0);

	for (int i = l; i <= r; i++) {
		for (int j = 0; j < 17; j++) {
			if (i & (1 << j))
				oldBits[j]++;
			if (numbers[i-l] & (1 << j))
				newBits[j]++;
		}
	}

	int out = 0;
	for (int i = 0; i < 17; i++)
		if (oldBits[i] != newBits[i])
			out |= (1 << i);

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

