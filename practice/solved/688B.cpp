#include <bits/stdc++.h>
using namespace std;
#define ll long long

// First try :)

void solve() {
    string n;
    cin >> n;
    string out = n;
    reverse(n.begin(), n.end());
    out += n;
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}