#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// just greedy and leads to O(32 q)
// make a 2d array with costs associated for each?
// I think you can just do it with greedy acc
const int BITS = 31;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	vector<ll> powers(BITS,0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < BITS; j++)
			if ((1<<j) == a[i])
				powers[j]++;

	for (int i = 0; i < q; i++) {
		ll b; cin >> b;
		ll out = 0;
		vector<ll> current(all(powers));
		for (int i = BITS-1; ~i; i--) {
			if (b >= (1<<i)) {
				int add = min(b/(1<<i),powers[i]);
				b -= add * (1<<i);
				out += add;
			}
		}

		cout << (b ? -1 : out) << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

