#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Need to get a in increasing order in n operations
// some may need two operations to change parity
// you can only have one operation on each of the elements
// and one extra for ends
// need to get parity of largest element
// if the largest parity is a we need to make everything above !a
// and everything below a
// could also be done by lowering the larger elements
// need a pair of elements at the top that is odd and even
// only odd sums can set higher up
// only even sums can set lower down
// find greatest element of opposite parity and do that to top
// greatest elements of each parity and kinda treat separately
// find last element of odd parity
// set all odd elements to be it
// then set all even elements to be it
// I think the first element might be the one that matters
// walk down with evens then walk back up with odds
// might be better to walk up with odds then walk back down with
// evens - depends of first element parity
// there is no way to change the parity of a[0]
// get the last odd, set all other odds to it
// set all other evens to the last odd
// leaving everything odd
// get the last even, set all other evens to it
// set all other odds to the last even

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	vector<pair<int,int> > out;
	int p = a[0]&1;
	
	if (p) {
		// Gets the last odd
		int lastOdd = 0;
		for (int i = n-1; ~i; i--)
			if (a[i]&1) {
				lastOdd = i;
				break;
			}

		// Sets all odds to the last odd
		for (int i = 0; i < n; i++)
			if (i != lastOdd && (a[i]&1))
				out.push_back({lastOdd+1,i+1});

		// Sets all evens to the last odd
		for (int i = 0; i < n; i++)
			if (a[i]%2 == 0)
				out.push_back({1,i+1});
	} else {
		// Gets last even
		int lastEven = 0;
		for (int i = n-1; ~i; i--)
			if (a[i]%2==0) {
				lastEven = i;
				break;
			}

		// Sets all evens to the last even
		for (int i = 0; i < n; i++)
			if (i != lastEven && a[i]%2==0)
				out.push_back({lastEven+1,i+1});

		// Sets all the odds to evens
		for (int i = 0; i < n; i++)
			if (a[i]&1)
				out.push_back({1,i+1});
	}

	cout << sz(out) << "\n";
	for (pair<int,int> i : out)
		cout << min(i.f,i.s) << " " << max(i.f,i.s) << "\n";
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

