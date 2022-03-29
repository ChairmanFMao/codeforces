
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// I think that I can use a dfs to find the greatest sum and then I can just
// increment the sum by x each time maybe...
// Looked at solution that works in O(n^2) time, should've evaluated constraints more

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> numbers(n), best(n+1, -1e9);
    for (int& i : numbers)
        cin >> i;
    
    // The best array keeps track of the best subarray with length of the index
    for (int i = 0; i < n; i++) {
        int current = 0;
        for (int j = i; j < n; j++) {
            current += numbers[j];
            best[j-i+1] = max(best[j-i+1],current);
        }
    }
    
    // We iterate through all values of k
    int out = 0;
    for (int i = 0; i <= n; i++) {
        // We iterate through all the possible best combinations of each length.
        for (int j = 0; j <= n; j++) {
            out = max(out, best[j] + min(i,j) * x);
        }
        cout << out << " ";
    }
    cout << "\n";
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
