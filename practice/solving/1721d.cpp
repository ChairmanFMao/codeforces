#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Need there to be n bits set for it to work
// Unsure how to ensure that enough are on the same side
// trying to find a partner that will & to zero
// can try to seperate into groups but gets hard to handle quick
// Segment tree for each bit?
// looked at some solutions and the problem is interesting
// This solution is very cool

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int& i : a)
		cin >> i;
	for (int& i : b)
		cin >> i;

	int out = 0;
	// Sorts all of a and b, reverses b
	sort(all(a));
	sort(all(b));
	reverse(all(b));
	// Iterates through all of the bits
	for (int i = 29; ~i; i--) {
		int flag = 1;
		for (int j = 0; j < n; j++)
			if ((a[j] & (1<<i)) == (b[j] & (1<<i))) {
				flag = 0;
				break;
			}

		// If the bit is set n times and fits
		// we can just add it to the answer
		if (flag) {
			out |= 1<<i;
			continue;
		}

		// Otherwise we remove the bit from all the values
		for (int j = 0; j < n; j++) {
			a[j] &= ~(1<<i);
			b[j] &= ~(1<<i);
		}
		// Then we can just resort the array
		sort(all(a));
		sort(all(b));
		reverse(all(b));
	}

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

