#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	for (ll i = 1; i <= 50; i++) {
		cout << "? " << i << " " << i+1 << endl;
		ll a, b;
		cin >> a;
		cout << "? " << i+1 << " " << i << endl;
		cin >> b;

		if (a == -1 || b == -1) {
			cout << "! " << i << endl;
			return;
		} if (a != b) {
			cout << "! " << a+b << endl;
			return;
		}
	}
}

int main(void) {
	solve();
}

