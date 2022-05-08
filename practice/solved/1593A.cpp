#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int big = max(a,max(b,c));
	int cnt = (a == big) + (b==big) + (c==big);
	cout << (a == big ? cnt != 1 :  big+1-a) << " " << (b == big ? cnt != 1 : big+1-b) << " " << (c == big? cnt != 1 : big+1-c) << "\n";
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

