
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string x[2];
    int p[2];
    cin >> x[0] >> p[0] >> x[1] >> p[1];

    if (x[0].size() + p[0] > x[1].size() + p[1]) {
        cout << ">\n";
    } else if (x[0].size() + p[0] < x[1].size() + p[1]) {
        cout << "<\n";
    } else {
        int longer = max(x[0].size(),x[1].size());
        while ((int)x[0].size() < longer)
            x[0] += "0";
        while ((int)x[1].size() < longer)
            x[1] += "0";

        int first = stoi(x[0]), second = stoi(x[1]);
        if (first > second)
            cout << ">\n";
        else if (second > first)
            cout << "<\n";
        else
            cout<< "=\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}
