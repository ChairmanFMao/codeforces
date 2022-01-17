#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try due to misspelling "Mahmoud"
// Accepted second try

void solve() {
    int n;
    cin >> n;
    string out = n & 1 ? "Ehab" : "Mahmoud";
    cout << out << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}