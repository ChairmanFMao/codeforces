#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try!

void solve() {
    string s;
    cin >> s;
    int pos = 1;
    int moves = 0;
    for (int i = 0; i < s.size(); i++) {
        int newPos = s[i]-96;
        moves += min(26 - abs(+pos-newPos), abs(newPos-pos));
        pos = newPos;
    }
    cout << moves << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}