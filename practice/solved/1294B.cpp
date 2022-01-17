#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try!
// Very happy with my algorithm, need to do more implementation problems like this

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> coordinates;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        coordinates.push_back({a,b});
    }
    
    sort(coordinates.begin(), coordinates.end());
    int biggestY = 0;
    for (int i = 0; i < n; i++) {
        if (coordinates[i].second >= biggestY)
            biggestY = coordinates[i].second;
        else {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
    string move = "";
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        while (coordinates[i].first > x) {
            move += "R";
            x++;
        }
        while (coordinates[i].second > y) {
            move += "U";
            y++;
        }
    }   
    cout << move << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve();
}