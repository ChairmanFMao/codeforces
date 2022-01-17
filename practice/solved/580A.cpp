#include <bits/stdc++.h>
using namespace std;

// Possible to do using an O(n) algorithm, my O(n^2) was 50ms from timeout ;-; yet, it passed
// I implemented the O(n) solution here

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int longest = 0, run = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i-1])
            run++;
        else {
            longest = max(longest, run);
            run = 1;
        }
    }
    longest = max(longest,run);
    cout << longest;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}