#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Relatively small number of test cases, some brute force maybe
// X can be made with the product of any number of beautiful numbers
// Unsure where to implement dp here
// Looked at solution because I wanted to finish it before 27/3/2022 contest

ll factor(ll n) {
	for (int i = 2; i*i <= n; i++)
		if (!(n%i))
			return i;
	return -1;
}

void solve() {
	ll x, d;
	cin >> x >> d;
	
	ll count = 0;
	while (!(x%d)) {
		count++;
		x/=d;
	}
	
	// There is only 1 factor of d in x so it can't be the product of 2 good numbers
	if (count==1) {
		cout << "NO\n";
		return;
	}
	
	// This assumes that the count >= 2 and x is a composite number, easily done
	if (factor(x) != -1) {
		cout << "YES\n";
		return;
	}
	
	// d is a power of a prime number
	if (factor(d) != -1 && d == factor(d) * factor(d)) {
		// This is impossible because it would need d^3 and x is already a factor of d
		// This would required a d * x terms and a d^2 term, but d^2 term is impossible
		if (x == factor(d) && count == 3) {
			cout << "NO\n";
			return;
		}
	}
	
	// d is composite and not the power of a prime
	if (count > 2 && factor(d) != -1) {
		cout << "YES\n";
		return;
	}

	// Otherwise you can't split the number
	cout << "NO\n";
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

