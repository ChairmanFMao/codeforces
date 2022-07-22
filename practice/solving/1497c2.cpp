#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Thinking about decomposing the number with binary

void solve() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k-3; i++) {
		cout << "1 ";
		n--;
	}

	if (n & 1) {
		cout << 1 << " " << n/2 << " " << n/2 << "\n";
	} else if (n % 4 == 2) {
		cout << 2 << " " << n/2-1 << " " << n/2-1 << "\n";
	} else {
		cout << n/2 << " " << n/4 << " " << n/4 << "\n";
	}
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

