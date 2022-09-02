#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Sum of absolute values less than 1e9
// Could just try to make every pair equal each other
// n doesn't have to be even
// Unsure where division by zero would be

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	int flag = -1, first = 0;
	if (n&1) {
		for (int i = 1; i < n; i++)
			if (a[i] + a[0] != 0)
				flag = i;
		if (flag != -1) {
			a[flag] += a[0];
			first = 1;
		} else {
			for (int i = 0; i < n-1; i++)
				if (a[i] + a[n-1] != 0)
					flag = i;
			a[flag] += a[n-1];
			first = 2;
		}
	}
	vector<int> out;
	for (int i = first%2; i+1 < n; i+=2) {
		int lcm = (abs(a[i])*abs(a[i+1]))/__gcd(abs(a[i]),abs(a[i+1]));
		if ((a[i] < 0 && a[i+1] < 0) || (a[i] > 0 && a[i+1] > 0)) {
			out.push_back(-lcm/a[i]);
			out.push_back(lcm/a[i+1]);
		} else if (a[i] < 0 && a[i+1] > 0) {
			out.push_back(-lcm/a[i]);
			out.push_back(lcm/a[i+1]);
		} else {
			out.push_back(lcm/a[i]);
			out.push_back(-lcm/a[i+1]);
		}
	}

	if (n&1 && first == 1)
		cout << out[flag-1] << " ";
	for (int i : out)
		cout << i << " ";
	if (n&1 && first == 2)
		cout << out[flag] << " ";
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

