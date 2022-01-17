#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try!

void solve() {
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    
    int ones = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i] == 1)
            ones++;
        else
            break;
    }
    string out = (ones & 1) ? "Second" : "First";
    if (ones == n)
        out = (ones & 1) ? "First" : "Second";
    cout << out << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve();
}