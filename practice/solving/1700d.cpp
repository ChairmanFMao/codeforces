#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Its always best to turn on higher pipes
// I can think of an O(n^2) solution
// There can be lower locks that won't contribute after they are filled
// Read an interesting comment that does it in O(n)

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int& i : v)
		cin >> i;
	int q;
	cin >> q;
	vector<ll> t(q);
	for (ll& i : t)
		cin >> i;

	ll maxOp = 0, total = 0;
	for (int i = 0; i < n; i++) {
		total += v[i];
		maxOp = max(maxOp, total/(i+1) + (total%(i+1) ? 1 : 0));
	}

	for (int i = 0; i < q; i++) {
		cout << (t[i] < maxOp ? -1 : (total/t[i] + (total%t[i] ? 1 : 0))) << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

