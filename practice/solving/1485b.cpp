#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n, q, k;
	cin >> n >> q >> k;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	vector<ll> preCacl(n,0);
	preCacl[0] = a[0]-1; preCacl[n-1] = k-a[n-1]-1;
	for (int i = 1; i < n-1; i++) {
		preCacl[i] = a[i+1]-a[i-1]-2;
	}

	vector<ll> prefix(n+1,0);
	for (int i = 0; i < n; i++)
		prefix[i+1] = prefix[i] + preCacl[i];

	for (int i = 0 ; i < q; i++) {
		int l, r; cin >> l >> r; l--; r--;
		ll out = a[l+1]-1 + k-a[r-1]-2;
		if (l == r) {
			cout << k-1 << "\n";
			continue;
		}
		cout << out + prefix[r] - prefix[l+1] << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

