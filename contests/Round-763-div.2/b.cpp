#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Watched Geothermal's tutorial video to get this solution

void solve() {
    int n;
    cin >> n;
    int occurs[n+1];
    memset(occurs,0,sizeof occurs);
    vector<pair<int,int>> pairs;
    for (int i = 0,l,r; i < n; i++) {
        cin >> l >> r;
        for (int j = l; j <= r; j++)
            occurs[j]++;
        pairs.push_back({l,r});
    }
    for (int i = 0; i < n; i++) {
        int smallestO = occurs[pairs[i].first], smallestn = pairs[i].first;
        for (int j = pairs[i].first; j <= pairs[i].second; j++)
            if (occurs[j] < smallestO) {
                smallestO = occurs[j];
                smallestn = j;
            }
        cout << pairs[i].first << " " << pairs[i].second << " " << smallestn << "\n";
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
