#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try

void solve() {
    string s;
    cin >> s;

    // Keeps a running value of where the last occurence of each number was in the string
    int one = -1, two = -1, three = -1, shortest = INT_MAX;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1')
            one = i;
        if (s[i] == '2')
            two = i;
        if (s[i] == '3')
            three = i;
        if (one != -1 && two != -1 && three != -1) {
            // We need to add one here as the difference between indexes would be one less than we want
            if (max(one,max(two,three)) - min(one,min(two,three)) + 1 < shortest)
                shortest = max(one,max(two,three)) - min(one,min(two,three)) + 1;
        }
    }
    if (shortest == INT_MAX) {
        cout << 0 << "\n";
        return;
    }
    cout << shortest << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}