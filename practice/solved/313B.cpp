#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Thought for a long time(1hr ish) and managed to make a O(n) algorithm to allow me to complete it first try! :)))))))
// Implemented this cool sliding sum sorta thing from programming book

void solve() {
    string s;
    cin >> s;
    int numbers[s.size()];
    for (int i = 0; i < s.size()-1; i++) {
        if (s[i] == s[i+1])
            numbers[i] = 1;
        else
            numbers[i] = 0;
    }
    numbers[s.size()-1] = 1;
    int running = 0;
    int sums[s.size()+1];
    sums[0] = 0;
    for (int i = 1; i <= s.size(); i++) {
        running += numbers[i-1];
        sums[i] = running;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << sums[r-1]-sums[l-1] << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}