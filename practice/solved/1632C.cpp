#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// I can think of an easy solution that is O(n^2) however, this will
// probably timeout as 1 <= a < b <= 1e6
// I think you need to maintain O(n) or O(n log n) to win
// What if you increment b before the addition and or operations
// Maybe a representation of bits in a map with operations to get there?
// Just check if the double apserand of a and b == a
// Looked at some of the editorial, the hint is that it is optimal
// to apply the third operation at most once
// Possibilties: there may be 0 operations of 1 or 2 done
// 1 3 2
// 2 3 1
// I got accepted after making a linear time solution.
// I should've tried to look for an observation like the hint

void solve() {
	int a, b;
	cin >> a >> b;

	int out = b-a;
	for (int i = a; i <= b; i++) {
		out = min(out, (i|b) - b + i-a + 1);
	}
	int pow = 1;
	while (pow < b)
		pow <<= 1;
	
	for (int i = b; i <= pow-1; i++) {
		out = min(out, (i|a) - i + i-b + 1);
	}

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

