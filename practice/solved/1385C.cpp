#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Looked at solution because I spent ages messing around with loops to no avail
// Solution it actually quite simple and I was close to it, just made it more complicated that it was
// Accepted first try!

void solve() {
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    int pos = n-1;
    while (pos >= 1 && numbers[pos-1] >= numbers[pos])
        pos--;
    while (pos >= 1 && numbers[pos-1] <= numbers[pos])
        pos--;
    cout << pos << "\n";
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