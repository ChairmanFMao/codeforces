#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

bool pal(int f, int s) {
	string a = to_string(f), b = to_string(s);
	if (sz(a) == 1)
		a = '0' + a;
	if (sz(b) == 1)
		b = '0' + b;

	for (int i = 0; i < 2; i++)
		if (a[i] != b[1-i])
			return 0;

	return 1;
}

void solve() {
	string s;
	int x;
	cin >> s >> x;

	int hours = (s[0]-48)*10 + (s[1]-48), mins = (s[3]-48)*10 + (s[4]-48);
	int sh = hours, sm = mins, out = 0, first = 1;
	while (hours != sh || mins != sm || first) {
		out += pal(hours,mins);
		mins += x;
		hours += mins/60;
		mins %= 60;
		hours %= 24;
		first = 0;
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

