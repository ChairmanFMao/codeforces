#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Need to do something to do with powers of two
// Modified testing to test the program locally
// I got this right, I was so close to it in the contest
// Kinda suprised that it worked but very happy!

const int ans = 4;

int q(int a, int b) {
	int tmp;
	cout << "? " << a << " " << b << endl;
	cin >> tmp;
	return tmp;
	//return __gcd(a+ans,b+ans);
}

void solve() {
	ll out = 0, a = 1, b = 2, tmp;
	for (int i = 0; i < 30; i++) {
		b += (1 << i);
		tmp = q(a,b);
		if (tmp == b-a)
			out |= (1<<i);
		else {
			a += 1<<i;
			b += 1<<i;
		}
	}

	cout << "! " << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "\n";
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

