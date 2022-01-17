#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, WA test 4, due to forgetting about not allowing leading zeros
// Accepted second try!

void solve() {
    ll x;
    cin >> x;

    string out = "";
    string working = to_string(x);
    for (int i = 0; i < working.size(); i++) {
        if (i == 0)
            out += min(working[i],(char) ('9'-working[i]+48)) == '0' ? working[i] : min(working[i],(char) ('9'-working[i]+48));
        else
            out += min(working[i],(char) ('9'-working[i]+48));
    }
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}