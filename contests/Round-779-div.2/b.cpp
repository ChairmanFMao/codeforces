#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 998244353;

// I think you just need to do it with odd and even

ll factorial(ll n) {
	ll out = 1;
	for (int i = 1; i <= n; i++)
		out = (out*i)%MOD;
	return out;
}

void solve() {
	int n;
	cin >> n;
	if (n & 1) {
		cout << "0\n";
		return;
	}

	cout << (factorial(n/2)*factorial(n/2))%MOD << "\n";
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

