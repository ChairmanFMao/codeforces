#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Very close to the solution, just needed to use the start rather than end.
 
void solve() {
    string x, out = "";
    cin >> x;
    for (int i = x.size()-2; i >= 0; i--) {
        string end = to_string(x[i]-48 + x[i+1]-48);
        if (end.size() == 2) {
            out = x.substr(0,i) + end + x.substr(i+2);
            break;
        }
    }
    if (out == "") {
        out = to_string(x[0]-48 + x[1]-48);
        out += x.substr(2);
    }
    cout << out << "\n";
    
}
 
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}