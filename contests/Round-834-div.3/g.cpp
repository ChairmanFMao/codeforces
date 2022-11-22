#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Need to ensure that later ones are still possible
// we are trying to make the lexicographically smallest permuation
// If we move from the back towards the front it will work better

void solve() {
	ll n;
	cin >> n;
	vector<ll> b(n/2);
	for (ll& i : b)
		cin >> i;


	set<ll> seen(all(b)), unseen;
	for (ll i = 1; i <= n; i++)
		if (!seen.count(i))
			unseen.insert(-i);

	if (sz(seen) != n/2) {
		cout << "-1\n";
		return;
	}

	stack<ll> st;
	for (ll i = n/2-1; ~i; i--) {
		auto ptr = unseen.upper_bound(-b[i]);
		if (ptr == unseen.end()) {
			cout << "-1\n";
			return;
		}
		ll val = *ptr;
		st.push(b[i]);
		st.push(-val);
		unseen.erase(val);
	}

	while (sz(st)) {
		cout << st.top() << " ";
		st.pop();
	}
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

