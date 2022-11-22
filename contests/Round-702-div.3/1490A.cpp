#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try lets go

void solve() {
    int n;
    cin >> n;
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        numbers.push_back(a);
    }
    int added = 0;
    for (int i = 1; i < n; i++) {
        if (((double) max(numbers[i], numbers[i-1]) / min(numbers[i], numbers[i-1])) <= 2 + 1e-9) {
            continue;
        } else {
            int small = min(numbers[i], numbers[i-1]);
            int big = max(numbers[i], numbers[i-1]);
            while (small < (double) big / 2) {
                small *= 2;
                added++;
            }
        }
    }
    cout << added << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}