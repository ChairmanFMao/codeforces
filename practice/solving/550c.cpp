#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// At most 100 digits, can't deal with number normally
// We are removing digits from the number
// 1000 divides by 8, so we only need a 3 digit number divisible by 8
// we also need to check 2 digit numbers and 1 digit numbers

void solve() {
	string s;
	cin >> s;

	for (int i = 0; i < sz(s); i++) {
		if (!((s[i]-48)%8)) {
			cout << "YES\n" << s[i] << "\n";
			return;
		}
		for (int j = i+1; j < sz(s); j++) {
			if (!(((s[i]-48)*10 + s[j]-48)%8)) {
				cout << "YES\n" << s[i] << s[j] << "\n";
				return;
			}
			for (int k = j+1; k < sz(s); k++) {
				if (!(((s[i]-48)*100 + (s[j]-48)*10 + s[k]-48) % 8)) {
					cout << "YES\n" << s[i] << s[j] << s[k] << "\n";
					return;
				}
			}
		}
	}
	cout << "NO\n";
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

