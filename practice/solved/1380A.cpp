#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try with the time limit exceeded on test 2 due to a brute force O(n^3) algorithm
// Failed second try, WA test 2
// Accepted third try with tweaks to the algorithm to store the leftSmallest and rightSmallest as pairs with the index of the value that had the left/right smallest value

void solve() {
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    
    int left = 10000, li=-1, right = 10000, ri=-1;
    vector<pair<int,int>> leftSmallest(n), rightSmallest(n);
    for (int i = 0; i < n; i++) {
        if (numbers[i] < left) {
            left = numbers[i];
            li = i;
        }
        leftSmallest[i] = {left,li};
        if (numbers[n-i-1] < right) {
            right = numbers[n-i-1];
            ri = n-i-1;
        }
        rightSmallest[n-i-1] = {right,ri};
    }
    for (int i = 1; i < n-1; i++) {
        if (leftSmallest[i-1].first < numbers[i] && numbers[i] > rightSmallest[i+1].first) {
            cout << "YES" << "\n";
            cout << leftSmallest[i-1].second+1 << " " << i+1 << " " << rightSmallest[i+1].second+1 << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
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