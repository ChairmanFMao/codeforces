#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

const int mxX = 1024;
// can all of the operations be compressed?
// something about simplifying bitwise algebra
// I can get a O((3*1024)**3) solution but it is too slow
// Ended up looking at the tutorial
// Its just some bitwise algebra
void solve() {
	int n;
	cin >> n;

	// Only need to consider bit set and bit not set cases
	vector<int> b = {0,mxX-1};
	for (int i = 0; i < n; i++) {
		char c; int a; cin >> c >> a;
		if (c == '|')
			b[0] |= a, b[1] |= a;
		else if (c == '^')
			b[0] ^= a, b[1] ^= a;
		else if (c == '&')
			b[0] &= a, b[1] &= a;
	}

	vector<int> op = {0,0,1023};
	for (int i = 0; i < 10; i++) {
		if ((b[0]&(1<<i)) && (b[1]&(1<<i))) {
			op[1] |= (1<<i);
		} else if (b[0]&(1<<i)) {
			op[0] |= 1<<i;
		} else if (!(b[1]&(1<<i)) && !(b[0]&(1<<i))) {
			op[2] ^= 1<<i;
		}
	}

	cout << "3\n";
	cout << "^ " << op[0] << "\n";
	cout << "| " << op[1] << "\n";
	cout << "& " << op[2] << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

