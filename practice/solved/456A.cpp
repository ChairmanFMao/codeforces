#include <bits/stdc++.h>
using namespace std;
#define ll long long

// First try failed because of a blank line, second timed out, third try with sorting timed out
// Fourth try I used an unordered_map but, still faced timeout
// Looked at solution and you just need to sort according to price and comparing neighboring elements
// and see if any of them defy the sorted order
// Basically O(n^2) fails and you need to sort and then to a linear search getting O(n log(n)) time

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> laptops;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        laptops.push_back({a,b});
    }
    sort(laptops.begin(), laptops.end());
    for (int i = 0; i < n-1; i++) {
        if (laptops[i].second > laptops[i+1].second) {
            cout << "Happy Alex" << "\n";
            return;
        }
    }
    cout << "Poor Alex" << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}