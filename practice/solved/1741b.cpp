#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Shift all of them by 2

void solve() {
	int n;
	cin >> n;

	if (n == 3) {
		cout << "-1\n";
		return;
	} if (n == 2) {
		cout << "2 1\n";
		return;
	}

	for (int i = 2; i < 2+n; i++)
		cout << (i%n)+1 << " ";
	cout << "\n";
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

