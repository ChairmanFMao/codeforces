#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Find the gap with the shortest length, then move one of the elements?
// Store all of the gaps and try to move an exam to the best empty spot
// When we remove the gap we need to merge the two gaps that match up
// Currently WA on test 2, part 40 - expected 7 instead of 5
// Unsure where the error is - look forward to debugging later

void solve() {
	int n, d;
	cin >> n >> d;
	vector<int> numbers, gaps;
	numbers.push_back(0);
	for (int i = 0,a; i < n; i++) {
		cin >> a;
		numbers.push_back(a);
	}
	numbers.push_back(d+2);

	// This is just an edge case where you can't insert any exam in a different spot
	if (n == d) {
		cout << "0\n";
		return;
	}
	
	// This gets the sizes of all the of the gaps
	for (int i = 0; i < (int)numbers.size()-1; i++)
		gaps.push_back(numbers[i+1] - numbers[i]-1);
	
	// This gets the index of the smallest gap
	int index = 0, lowest = 1e9;
	for (int i = 0; i < (int)gaps.size()-1; i++)
		if (lowest >= gaps[i]) {
			index = i;
			lowest = gaps[i];
		}
	
	// We make copies of numbers and gaps for the thing to work
	vector<int> gCopy1(gaps.begin(), gaps.end()), gCopy2(gaps.begin(), gaps.end());
	int out = lowest, newGap = 0;

	// This is if the gap isn't the first element - testing removing left
	if (index > 0) {
		gCopy1[index-1] += gCopy1[index] +1;
		gCopy1[index] = 0;
		
		newGap = (*max_element(gCopy1.begin(),gCopy1.end())-1)/2;
		gCopy1.pop_back();
		gCopy1.push_back(newGap);
		gCopy1[index] = 1e9;

		out = max(out, *min_element(gCopy1.begin(),gCopy1.end()));
	} 
	// This is if the gap isn't the last element - testing removing right
	if (index < (int)gaps.size()-1) {
		gCopy2[index+1] += gCopy2[index] +1;
		gCopy2[index] = 0;

		newGap = (*max_element(gCopy2.begin(),gCopy2.end())-1)/2;
		gCopy2.pop_back();
		gCopy2.push_back(newGap);
		gCopy2[index] = 1e9;

		out = max(out, *min_element(gCopy2.begin(),gCopy2.end()));
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

