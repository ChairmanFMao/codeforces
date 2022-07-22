#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// One bag to each depot

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> x(n);
	for (ll& i : x)
		cin >> i;
	
	sort(all(x));
	ll out = 0, posB = INT_MIN, negB = INT_MIN;
	deque<ll> pos, neg;
	for (ll i : x) {
		if (i > 0)
			pos.push_front(i);
		else if (i < 0)
			neg.push_back(i);
	}

	while (sz(pos)) {
		out += pos.front() << 1;
		posB = max(posB, pos.front());
		for (int i = 0; i < k && sz(pos); i++)
			pos.pop_front();
	}

	while (sz(neg)) {
		out += abs(neg.front()) << 1;
		negB = max(negB, abs(neg.front()));
		for (int i = 0; i < k && sz(neg); i++)
			neg.pop_front();
	}
	
	if (posB != INT_MIN && negB != INT_MIN)
		out -= posB > negB ? posB : negB;
	else if (posB != INT_MIN)
		out -= posB;
	else if (negB != INT_MIN)
		out -= negB;

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

