#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Only edge case is two next to each other
// need to check if x < 2*y

void solve() {
	ll n, x, y;
	string as, bs;
	cin >> n >> x >> y >> as >> bs;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		a[i] = as[i]&1;
		b[i] = bs[i]&1;
	}

	int paritya = accumulate(all(a),0)%2;
	int parityb = accumulate(all(b),0)%2;

	if (paritya != parityb) {
		cout << "-1\n";
		return;
	}

	vector<int> change;
	for (int i = 0; i < n; i++)
		if (a[i] != b[i])
			change.emplace_back(i);

	ll out = 0;

	if (sz(change) == 2 && change[0]+1 == change[1])
		out += min(x,y+y);
	else
		out += (sz(change)/2) * y;

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

