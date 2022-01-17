#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cities;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cities.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << cities[1] - cities[0] << " " << cities[n-1] - cities[0] << "\n";
        } else if (i == n-1) {
            cout << cities[n-1] - cities[n-2] << " " << cities[n-1] - cities[0] << "\n";
        } else {
            cout << min(cities[i]-cities[i-1], cities[i+1] - cities[i]) << " " << max(cities[i] - cities[0], cities[n-1] - cities[i]) << "\n";
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}