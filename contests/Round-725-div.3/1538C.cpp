#include <bits/stdc++.h>
using namespace std;

// Attempted with an O(n^2) algorithm but failed, time limit exceeded on test 4
// I had to look at solution because I couldn't figure out a way to do it.

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        numbers.push_back(a);
    }
    // The vector needs to be sorted to allow for the later algorithm to work
    sort(numbers.begin(), numbers.end());
    // Due to the adding and subtracting we need to make good a long long as in intermediate stages it passes the integer overflow
    long long good = 0;
    for (int i = 0; i < n; i++) {
        // Gets the index of the first element that has a value greater than r - numbers[i] (enough to make the pair sum <= r)
        good += upper_bound(numbers.begin(), numbers.end(), r - numbers[i]) - numbers.begin();
        // Gets the index of the first element which has a value that is not less than l - numbers[i] (enough to make the pair sum < l)
        good -= lower_bound(numbers.begin(), numbers.end(), l - numbers[i]) - numbers.begin();
        // This little clause deletes the pairings where the current number(numbers[i]) is paired with itself and counted as valid
        if (l <= 2 * numbers[i] && 2 * numbers[i] <= r)
            good--;
    }
    // good is halved here because each pair will have been counted twice with the numbers the other way around
    cout << good / 2 << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}