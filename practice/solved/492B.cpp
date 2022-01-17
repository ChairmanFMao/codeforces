#include <bits/stdc++.h>
using namespace std;
#define ll long long

// First submit failed due to an error of 0.5 :(, same with second
// Third I just had an algorithmic error
// Looked at solution because I was confused, algorithm is literally the same as theirs
// Solution keeps failing on this one problem which is very infuriating
// Failed four times because I used n instead of l on line 21 column 36, very sad

void solve() {
    int n, l;
    cin >> n >> l;
    vector<int> lanterns;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        lanterns.push_back(a);
    }
    sort(lanterns.begin(), lanterns.end());
    int d = 2 * max(lanterns[0], (l - lanterns[n-1]));
    for (int i = 0; i < n - 1; i++)
        d = max(lanterns[i+1] - lanterns[i], d);
    double out = (double) d / 2;
    cout.precision(30);
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}