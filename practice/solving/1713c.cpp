#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

const int mxN = 1e5;
vector<int> out(mxN);
int n;

// Recur backwards
// matching pairs to the closest square

void recur(int current) {
	if (current < 0)
		return;
	int stop = sqrt(current+current);
	stop *= stop;
	int left = stop - current;
	recur(left-1);
	for (; left <= current; left++, current--) {
		out[left] = current;
		out[current] = left;
	}
}

void solve() {
	cin >> n;

	recur(n-1);
	for (int i = 0; i < n; i++)
		cout << out[i] << " ";
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

