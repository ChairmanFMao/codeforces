#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Unsure of how to solve this problem, had to look at solution after 27 mins of struggling
// Achieved using a very inefficient O(n^3) algorithm
// Accepted first try!

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    
    int out[n];
    memset(out, 0, n*4);
    out[n-1] = INT_MAX;
    // Starting point
    for (int i = 1; i < 50; i++) {
        // Difference
        for (int j = 1; j < 50; j++) {
            // Set used to easily check if numbers were present
            set<int> numbers;
            // Generation of the array/set
            for (int k = i; numbers.size() < n; k+=j)
                numbers.insert(k);
            if ((numbers.count(x)) && (numbers.count(y)) && *max_element(numbers.begin(), numbers.end()) < out[n-1]) {
                vector<int> vectorNumbers(numbers.begin(), numbers.end());
                for (int l = 0; l < n; l++)
                    out[l] = vectorNumbers[l];
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << out[i] << " ";
    cout << "\n";
    return;
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