#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, WA test 2, forgot case if numbers[i] == lowest
// Accepted second try!

void solve() {
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    
    int bad = 0, lowest = 1e7;
    for (int i = n-1; i >= 0; i--) {
        if (numbers[i] <= lowest)
            lowest = numbers[i];
        else
            bad++;
    }
    cout << bad << "\n";
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