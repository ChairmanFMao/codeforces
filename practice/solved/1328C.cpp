#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try! very happy that I managed to think of good algorithm
// string name(length, character to fill string);
// Just a cool little trick that I saw in the example solution after completing

void solve() {
    int n;
    cin >> n;
    string number;
    cin >> number;
    
    string out1 = "", out2 = "";
    bool first = 1;
    for (int i = 0; i < n; i++) {
        if (number[i] == '0') {
            out1 += "0";
            out2 += "0";
        } else if (number[i] == '1') {
            if (first) {
                out1 += "1";
                out2 += "0";
                first = 0;
            } else {
                out1 += "0";
                out2 += "1";
            }
        } else {
            if (first) {
                out1 += "1";
                out2 += "1";
            } else {
                out1 += "0";
                out2 += "2";
            }
        }
    }
    cout << out1 << "\n" << out2 << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}