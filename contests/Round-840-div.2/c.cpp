#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Can replace all the numbers in a range with the abs the two
// elements at the ends of the range
// we want the maximum sum of the elements from this
// This needs to be done in less than O(n^2) as well
// get the max and min element in the array and test if it would
// be beneficial and keep applying this?
// need to compare the closest max to the min
// problems arise if there are multiple maxes or mins
// just use a multiset?
// only optimal to use edges of newly created areas
// leftmost max and rightmost min
// rightmost max and leftmost min
// we also need to do updates to this stuff tho
// I think its only optimal to apply the operation a few times
// doing this might lead to O(n^2)
// if the sum of the range is less than the abs of the ends times
// the length of the range
// advance outwards from every point and take the optimal?
// This could also lead to O(n^2) tho
// maybe dynamic programming? actually idk
// it maybe be optimal to use the operation multiple times
// can't further increase a range once an operation has been used
// I don't think a binary search is really possible
// maybe something with 2ptr
// my solution is getting wa on pretest 3
// still gets wa on pretest 3 even with the changes
// The thing is that this might go to O(n^2) as well
// still wa on pretest 3
// maybe my strategy is not always optimal
// not always best to do it greedily
// between any two local maxima or end of array
// greatest element that occurs later or smallest element
// still gets wa on pretest 3
//
// you can set elements to zero if you have two next to each other
// no matter what value they are
// if n >= 4 then the answer is just mx*n

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	if (n >= 4) {
		cout << (*max_element(all(a)))*n << "\n";
		return;
	}
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

