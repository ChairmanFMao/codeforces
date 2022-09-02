#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I think we will try to work downwards

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	sort(all(a),greater<ll>());
	priority_queue<ll> q;
	ll ptr = 0;
	q.push(accumulate(all(a),0ll));
	while (sz(q) && ptr < n) {
		ll current = q.top();
		if (!current || current < a[ptr])
			break;
		q.pop();
		if (current == a[ptr]) {
			ptr++;
			continue;
		}
		// We add the greater one first
		q.push(current/2 + current%2);
		q.push(current/2);
	}

	cout << (ptr == n ? "YES" : "NO") << "\n";
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

