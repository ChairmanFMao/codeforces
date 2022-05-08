#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN = 2e5;
vector<int> numbers(mxN);
int n;

// Solved after the contest, I was using the same method just a lot calmer
// I was kinda stressing out during the contest and it made it difficult
// Didn't even get any help for this one, just implemented it better

vector<int> solve2(int start, int end) {
	// Checks for the number of negatives in the subarray
	vector<int> neg;
	for (int i = start+1; i < end; i++)
		if (numbers[i] < 0)
			neg.push_back(i);
	
	// First is the score, left bound, right bound
	vector<int> out = {0,start,end};
	
	// This if there is an odd number of negatives in the window
	if ((int)neg.size() % 2) {
		int current = 0;
		for (int i = start+1; i < neg[0]; i++)
			if (abs(numbers[i]) == 2)
				current++;
		if (current > out[0]) {
			out[0] = current;
			out[1] = start;
			out[2] = neg[0];
		}

		current = 0;
		for (int i = neg[0]+1; i < end; i++)
			if (abs(numbers[i]) == 2)
				current++;
		if (current > out[0]) {
			out[0] = current;
			out[1] = neg[0];
			out[2] = end;
		}

		current = 0;
		for (int i = start+1; i < neg[neg.size()-1]; i++)
			if (abs(numbers[i]) == 2)
				current++;
		if (current > out[0]) {
			out[0] = current;
			out[1] = start;
			out[2] = neg[neg.size()-1];
		}

		current = 0;
		for (int i = neg[neg.size()-1]+1; i < end; i++)
			if (abs(numbers[i] == 2))
				current++;
		if (current > out[0]) {
			out[0] = current;
			out[1] = neg[neg.size()-1];
			out[2] = end;
		}
	} else
		// We can just find the number of twos in the range if the negs cancel out
		for (int i = start+1; i < end; i++)
			if (abs(numbers[i]) == 2)
				out[0]++;

	return out;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> numbers[i];

	vector<int> zeros;
	zeros.push_back(-1);
	for (int i = 0; i < n; i++)
		if (!numbers[i])
			zeros.push_back(i);
	zeros.push_back(n);
	
	vector<int> temp;
	int out = 0, left = n, right = 0;
	for (int i = 0; i < (int)zeros.size()-1; i++) {
		temp = solve2(zeros[i],zeros[i+1]);
		if (temp[0] > out) {
			out = temp[0];
			left = temp[1]+1;
			right = n - temp[2];
		}
	}
	
	cout << left << " " << right << "\n";
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

