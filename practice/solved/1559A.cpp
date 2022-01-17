#include <bits/stdc++.h>
using namespace std;

// Took 6 tries to get accepted, kinda sloppy

void solve() {
    int n;
    cin >> n;
    vector<int> numbers;
    int smallest = 1e9, si = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        numbers.push_back(a);
    }
    // We do this 5 times as it is enough to flatten out the array
    for (int j = 0; j < 5; j++) {
        smallest = 1e9;
        si = 0;
        for (int i = 0; i < n; i++) {
            if (numbers[i] < smallest) {
                smallest = numbers[i];
                si = i;
            }
        }
        if (smallest == 0) {
            cout << 0 << "\n";
            return;
        }
        for (int i = si; i > 0; i--) {
            int temp = numbers[i-1];
            numbers[i-1] &= numbers[i];
            numbers[i] &= temp;
        }
        for (int i = si; i < n - 1; i++) {
            int temp = numbers[i+1];
            numbers[i+1] &= numbers[i];
            numbers[i] &= temp;
        }
        if (*min_element(numbers.begin(), numbers.end()) == 0) {
            cout << 0 << "\n";
            return;
        }
    }
    cout << *max_element(numbers.begin(), numbers.end()) << "\n";
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