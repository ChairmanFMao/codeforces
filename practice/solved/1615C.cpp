#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Looked at solution because I didn't manage to answer this problem in the contest

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;

    int out = 1e9;
    // This loop alternates if all of the bits are starting 
    for (int flip = 0; flip < 2; flip++) {
        // This stores the number of each type of difference
        int c[2] = {0,0};
        // This loops over the string and checks for differences and updates c
        for (int i = 0; i < n; i++) {
            if ((a[i]^flip) != b[i]) {
                c[(a[i]^flip) < b[i]]++;
            }
        }
        // This then checks if the transition is possible and gets the new value of out
        // If the number of 01 is equal to the number of 10 plus the flip
        if (c[1]==c[0]+flip)
            out = min(out, c[0]+c[1]);
    }
    // If out was never updated then it wouldn't be possible for it to be done, so it is -1
    cout << (out == (int)1e9 ? -1 : out) << "\n";
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