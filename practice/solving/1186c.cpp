#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I think that this is dp
// I don't think that it would be that bad?
// I just need to somehow avoid O(n^2)
// just store the number of 1 and 0 at each b pos
// Might just need to have 2 ptrs
// get the number of substrings where an even number of characters
// are different from b
// the strings sum need to have the same parity
// wa on test 3, I just needed to update line 31

void solve() {
	string a, b;
	cin >> a >> b;

	int out = 0, current = 0, bVal = 0;
	for (int i = 0; i < sz(b); i++) {
		if (a[i]&1)
			current++;
		if (b[i]&1)
			bVal++;
	}

	out += (current%2) == (bVal%2);
	for (int i = sz(b); i < sz(a); i++) {
		current += (a[i]&1) - (a[i-sz(b)]&1);
		out += (current%2) == (bVal%2);
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

