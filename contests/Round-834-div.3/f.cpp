#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I don't think that this problem is that hard
// Just altering the end one a lot
// finding how many digits from the end are not needed
// count backwards from the last digit
// if the last digit at the end is greater or equal to zero
// we can also do an increment of the row to the left then we
// can get all of the extra ones that it will generate
// we may manage to generate a 1 at the start of the string
// this would be an edge case to look out for

void solve() {
	ll n, p;
	cin >> n >> p;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	set<ll> seen(all(a));
	if (sz(seen) == p) {
		cout << "0\n";
		return;
	}
	ll current = a[n-1], count = 0;
	while (seen.count(current) && count < n) {
		current = (p+current-1)%p;
		count++;
	}

	if (current >= a[n-1]) {
		cout << current - a[n-1] << "\n";
		return;
	}

	ll cur = 1;
	for (ll i = n-2; i >= 0; i--) {
		a[i] += cur;
		cur = a[i]/p;
		a[i] %= p;
		seen.insert(a[i]);
	}

	// There will be an extra one out front
	if (cur)
		seen.insert(1);

	current = a[n-1]; count = 0;
	while (seen.count(current) && count < a[n-1]) {
		current = (p+current-1)%p;
		count++;
	}
	count = a[n-1] - count + p-a[n-1];

	cout << count << "\n";
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

