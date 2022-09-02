#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// n is always even
// ((a + k) * b) mod 4 == 0
// order of pairs matters
// use all the even numbers for b and just make a+k divisible by 2 if k & 1
// else just have each multiple of 4 times an odd one, add to evens to get div by 4

void solve() {
	int n, k;
	cin >> n >> k;

	if (k&1) {
		cout << "YES\n";
		int odd = 1;
		for (int i = 4; i <= n; i+=4) {
			cout << odd << " " << i << "\n";
			odd += 2;
		}
		for (int i = 2; i <= n; i+=4) {
			cout << odd << " " << i << "\n";
			odd += 2;
		}
	} else if (k % 4 == 2) {
		cout << "YES\n";
		int odd = 1;
		for (int i = 4; i <= n; i+=4) {
			cout << odd << " " << i << "\n";
			odd += 2;
		}
		for (int i = 2; i <= n; i+=4) {
			cout << i << " " << odd << "\n";
			odd += 2;
		}
	} else
		cout << "NO\n";
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

