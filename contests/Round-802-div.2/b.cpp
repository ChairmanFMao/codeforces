#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Try to get to 9999 or 1111 if leading 9
// Has to be the same length

void solve() {
	ll n;
	string s;
	cin >> n >> s;
	vector<int> number(n+1,0);
	for (int i = 0; i < n; i++)
		number[i+1] = s[i]-48;
	
	int a = 9;
	if (number[1] == 9)
		a = 1;
	vector<int> target(n+1,a), out(n+1,0);

	for (int i = n; ~i; i--) {
		while (number[i] > target[i]) {
			target[i-1]--;
			target[i] += 10;
		}
		out[i] = target[i] - number[i];
	}

	for (int i = 1; i <= n; i++)
		cout << out[i];
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

