#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first time due to an oversight
// Failed second time due to not rigoursly reading the problem
// Had an O(n^2) algorithm and upgraded to O(n) allowing me to get accepted on third try
// Using a sliding window minimum, very cool!

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> heights;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        heights.push_back(a);
    }
    int index = 1, start = 0;
    for (int i = 0; i < k; i++) {
        start += heights[i];
    }
    int smallest = start;
    for (int i = k; i < n; i++) {
        start += heights[i];
        start -= heights[i-k];
        if (start < smallest) {
            smallest = start;
            index = i-k+2;
        }
    }
    cout << index << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}