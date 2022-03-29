
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    // y then x for ease
    vector<pair<int,int>> points(3);
    for (int i = 0; i < 3; i++) {
        cin >> points[i].second >> points[i].first;
    }

    sort(points.begin(),points.end());
    
    cout << (points[1].first == points[2].first ? abs(points[1].second - points[2].second) : 0) << "\n";
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
