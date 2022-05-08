#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

const int mxN = 4e4, MOD = 1e9+7;
ll dp[mxN+1];
vector<int> palindromes;

void solve() {
	int n;
	cin >> n;

	cout << dp[n] << "\n";
}

void calc() {
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	for (int i = 0; i < sz(palindromes); i++) {
		for (int j = 0; j <= mxN; j++) {
			if (j+palindromes[i] > mxN)
				break;
			dp[j+palindromes[i]] = (dp[j+palindromes[i]] + dp[j]) % MOD;
		}
	}
}

bool palindrome(int n) {
	string s = to_string(n);
	for (int i = 0; i < sz(s)/2; i++)
		if (s[i] != s[sz(s)-1-i])
			return 0;

	return 1;
}

void createPalindromes() {
	for (int i = 1; i <= mxN; i++)
		if (palindrome(i))
			palindromes.push_back(i);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	createPalindromes();
	calc();
	cout << "\n";
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

