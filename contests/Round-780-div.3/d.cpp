#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Sliding product wouldn't work due to bad time complexity and can't store numbers
// When number of negs is one or zero

const int mxN = 2e5+1;
int n, s, e;
vector<int> numbers(mxN), neg(mxN), zero(mxN);

int solve2(int start, int end) {

	if (start == end) {
		s = start;
		e = end;
		return (numbers[start] == 2 ? 1 : 0);
	}

	cout << "start: " << start << " end: " << end << "\n";
	vector<int> out(end-start+1), negl;
	int current = 0;
	for (int i = start; i<= end; i++) {
		if (abs(numbers[i]) == 2)
			current++;
		if (numbers[i] < 0)
			negl.push_back(i);
		out[i-start] = current;
	}

	cout << "out: ";
	for (int i = 0; i < (int)out.size(); i++) {
		cout << out[i] << " ";
	}
	cout << "\n";

	int returning = 0;

	cout << "negative " << neg[start] << " " << neg[end+1] << "\n";
	if ((neg[end+1] - neg[start]) % 2 == 0 && neg[end+1] - neg[start] > 1) {
		cout << "negl[0]+1: " << negl[0]+1 << "\n";

		if (out[end-start] - out[negl[0]+1] > returning) {
			s = negl[0]+1;
			e = end;
			returning = out[end-start] - out[negl[0]+1];
		}

		cout << "negl[1]+1: " << negl[1]+1 << "\n";
		if (out[negl[negl.size()-1]-1] > returning) {
			s = start;
			end = negl[negl.size()-1]-1;
			returning = out[negl[negl.size()-1]-1];
		}
	} else {
		returning = out[end-start];
		s = start;
		e = end;
	}
	return returning;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> numbers[i];
	
	// Counts negatives
	int current = 0;
	neg[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (numbers[i] < 0)
			current++;
		neg[i] = current;
	}
	
	// Counts zeros
	current = 0;
	zero[0] = -1;
	for (int i = 0; i < n; i++) {
		if (numbers[i] == 0) {
			current ++;
			zero[current] = i;
		}
	}
	current++;
	zero[current] = n;
	
	int start = n, end = 0, best = 0;
	for (int i = 0; i < current; i++) {
		int a = solve2(zero[i]+1,zero[i+1]-1);
		cout << "a: " <<  a << "\n";
		if (a > best) {
			start = s;
			end = n-e-1;
			best = a;
		}
	}

	cout << start << " " << end << "\n";
}

int main(void) {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cout << "\n";
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

