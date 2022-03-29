#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Each node needs at least 2 connections, I think we can do this greedily
// Now it gets to the 145th test case, idk what more I need to do
// Looked at solution because I was fumbling around a bit
// I was close but, just doing things in an inefficent way

int n;
const int mxN = 2e5;
vector<int> numbers(2*mxN);

ll best(int index) {
	ll out = 0, top = 1e12;
	for (int i = (index < n ? n : 0); i < (index < n ? 2*n : n); i++) {
		if (top > abs(numbers[i] - numbers[index])) {
			top = abs(numbers[i] - numbers[index]);
			out = i;
		}
	}
	return numbers[out];
}

void solve() {
	cin >> n;
	for (int i = 0; i < 2*n; i++)
		cin >> numbers[i];
	
	ll out = 1e12, current = 0;
	vector<int> used = {0,0};
	vector<ll> one = {numbers[n],best(0),numbers[2*n-1]};
	vector<ll> two = {numbers[n],best(n-1),numbers[2*n-1]};
	ll three = best(n), four = best(2*n-1);
	for (int i = 0; i < 3; i++) {
		used[0] = 0;
		used[1] = 0;
		current += abs(numbers[0] - one[i]);
		if (i == 0)
			used[0]++;
		if (i == 2)
			used[1]++;
		for (int j = 0; j < 3; j++) {
			current += abs(numbers[n-1] - two[j]);
			if (j == 0)
				used[0]++;
			if (j == 2)
				used[1]++;
		
			if (used[0] == 0)
				current += abs(numbers[n] - three);
			if (used[1] == 0)
				current += abs(numbers[2*n-1] - four);
			out = min(current,out);
			current -= abs(numbers[n-1] - two[j]);
			if (used[0] == 0)
				current -= abs(numbers[n] - three);
			if (used[1] == 0)
				current -= abs(numbers[2*n-1] - four);
			if (j == 0)
				used[0]--;
			if (j == 2)
				used[1]--;
		}
		current -= abs(numbers[0] - one[i]);
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

