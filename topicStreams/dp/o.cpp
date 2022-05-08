#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Going to restart and do it with dp
// Its always best to choose consecutive zeros
// TLE on test 15, current process is O(n^2)
// Optimised the code a bit, now passes
// Kinda uses dp

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	vector<int> zeros;
	for (int i = 0; i < n; i++)
		if (!a[i])
			zeros.push_back(i);

	if (k >= sz(zeros)) { 
		cout << n << "\n";
		for (int i = 0; i < n; i++)
			cout << "1 ";
		cout << "\n";
		return;
	}

	if (k == 0) {
		int streak = 0, local = 0;
		for (int i = 0; i < n; i++) {
			if (a[i])
				streak++;
			else {
				local = max(local,streak);
				streak = 0;
			}
		}
		local = max(local,streak);
		cout << local << "\n";
		for (int i : a)
			cout << i << " ";
		cout << "\n";
		return;
	}

	int best = 0, index = 0;
	for (int i = 0; i < k; i++)
		a[zeros[i]] = 1;

	for (int i = 0; i <= sz(zeros)-k; i++) {
		int local = 0, lptr = zeros[i], rptr = zeros[i+k-1];
		while (lptr >= 0 && a[lptr])
			lptr--;
		while (rptr < n && a[rptr])
			rptr++;
		local = rptr-lptr-1;
		
		if (local > best) {
			best = local;
			index = i;
		}

		a[zeros[i]] = 0;
		if (i+k < sz(zeros))
			a[zeros[i+k]] = 1;
	}

	for (int i = 0; i < n; i++)
		a[i] = 1;
	for (int i = 0; i < sz(zeros); i++)
		a[zeros[i]] = 0;
	for (int i = index; i < index+k; i++)
		a[zeros[i]] = 1;
	cout << best << "\n";
	for (int i : a)
		cout << i << " ";
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

