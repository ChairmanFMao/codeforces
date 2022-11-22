#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Unsure what is being asked
// every subarray should be contiguous
// every element should belong to one subarray
// x, y is a range that we check the values of a against
// we just need more elements within x <= a <= y than outside of
// the range for all of the subarrays.
// must also be strictly greater
// Aim is to try to minimise the value of y-x
// we have the split the array into k subarrays
// need to have at least n/2+1 numbers in the range
// might need more depending on where they are in the array
// all values of a <= n, so maybe this could be useful
// for a value of k, there must be one subarray of length
// ceil(n/k) at least and at most n+1-k
// it would only make sense for y and x to be values within a
// use two ptr to generate all the y and x pairs?
// even if found correct y and x values unsure how to create the
// ranges
// just start with y at max and x at min and attempt to move in
// it would be easy to calculate the number of elements which are
// in the range of xy using prefix sums
// prefix sums + binary search for every value of x?
// unsure if there are some edge cases tho due to the value of k
// there need to be at least k more numbers in the range than out
// tle? somehow
// still tle with an optimisation
// I think it might be getting stuck in the binary search or smth
// I added extra stuff to ensure the binary search didn't hang
// I'm not sure why it takes so long to process it
// I have a bit that will take up 2e5 time for every test case
// That bit was the problem and I solved it using a map instead
// of a vector

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	//vector<int> prefix(2e5+1,0);
	//for (int i : a)
		//prefix[i]++;
	//for (int i = 1; i < sz(prefix); i++)
		//prefix[i] += prefix[i-1];

	int small = INT_MAX, big = INT_MIN;
	unordered_map<int,int,custom_hash> m;
	for (int i : a) {
		m[i]++;
		small = min(i,small);
		big = max(i,big);
	}

	for (int i = small-1; i <= big+1; i++)
		m[i] += m[i-1];

	set<int> s(all(a));
	vector<int> v(all(s));

	// This gets us the best pair
	// This should take O(n log n) time
	pair<int,int> best = {2e5,-2e5};
	for (int i : v) {
		int lower = i-1, upper = big+1, mid = 0, pl = -1, pu = -1, itr = 0;
		while (lower <= upper && itr < 25) {
			if (lower == pl && upper == pu)
				break;
			mid = (lower+upper)/2;
			pl = lower; pu = upper;

			int val = m[mid]-m[i-1];
			if (val >= n-val+k) {
				upper = mid;
			} else {
				lower = mid;
			}
			itr++;
		}

		int val = m[upper]-m[i-1];
		if (val < n-val+k)
			continue;

		if (best.f - best.s > upper-i)
			best = {upper,i};
	}

	cout << best.s << " " << best.f << "\n";
	// Now we just need to allocate all of the numbers into ranges
	// Problem is that there might be 1 wide ranges
	// Maybe greedy allocation will work
	// This is linear time
	int current = 0, start = 0, left = k-1;
	for (int i = 0; i < n; i++) {
		if (best.s <= a[i] && a[i] <= best.f) {
			current++;
		} else
			current--;
		if (current == 1 && left > 0) {
			cout << start+1 << " " << i+1 << "\n";
			current = 0;
			start = i+1;
			left--;
		}
	}
	cout << start+1 << " " << n << "\n";
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

